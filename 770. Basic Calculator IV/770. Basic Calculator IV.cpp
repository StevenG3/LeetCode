#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Poly {
private:
    map<list<string>, int> count;
public:
    Poly() {}

    void update(list<string> key, int val) {
        count[key] += val;
    }

    // * `Poly:add(this, that)` 返回 `this + that` 的结果。
    Poly add(Poly& that) {
        Poly ans;
        for (auto& m : this->count) {
            ans.update(m.first, m.second);
        }
        for (auto& m : that.count) {
            ans.update(m.first, m.second);
        }
        return ans;
    }

    // * `Poly:sub(this, that)` 返回 `this - that` 的结果。
    Poly sub(Poly& that) {
        Poly ans;
        for (auto& m : this->count) {
            ans.update(m.first, m.second);
        }
        for (auto& m : that.count) {
            ans.update(m.first, -m.second);
        }
        return ans;
    }

    // * `Poly:mul(this, that)` 返回 `this * that` 的结果。
    Poly mul(Poly& that) {
        Poly ans;
        for (auto& m1 : this->count) {
            for (auto& m2 : that.count) {
                list<string> newKey;
                for (string s : m1.first) {
                    newKey.push_back(s);
                }
                for (string s : m2.first) {
                    newKey.push_back(s);
                }
                newKey.sort();
                ans.update(newKey, m1.second * m2.second);
            }
        }
        return ans;
    }

    // * `Poly:evaluate(this, evalmap)` 在用 `evalmap` 指定的常量替换所有自由变量后返回多项式。
    Poly evaluate(map<string, int>& evalmap) {
        Poly ans;
        for (auto& m : this->count) {
            int c = m.second;
            list<string> k;
            for (string s : m.first) {
                if (evalmap.count(s)) {
                    c *= evalmap[s];
                }
                else {
                    k.push_back(s);
                }
            }
            ans.update(k, c);
        }
        return ans;
    }

    // * `Poly:toList(this)` 以正确的输出格式返回多项式。
    vector<string> toVector() {
        vector<string> ans;
        vector<list<string>> keys;
        for (auto& m : this->count) {
            if (m.second == 0) {
                continue;
            }
            keys.push_back(m.first);
        }

        sort(keys.begin(), keys.end(), [](list<string>& A, list<string>& B) -> bool {
            if (A.size() != B.size()) {
                return A.size() > B.size();
            }
            else {
                auto ita = A.begin();
                auto itb = B.begin();
                while (ita != A.end() && *ita == *itb) {
                    ++ita, ++itb;
                }
                return *ita < *itb;
            }
            });

        for (list<string>& k : keys) {
            string w = to_string(this->count[k]);
            for (string s : k) {
                w.push_back('*');
                w.append(s);
            }
            ans.push_back(w);
        }
        return ans;
    }
};

class Solution {
public:
    Poly combine(Poly& left, Poly& right, char symbol) {
        if (symbol == '+') {
            return left.add(right);
        }
        else if (symbol == '-') {
            return left.sub(right);
        }
        else if (symbol == '*') {
            return left.mul(right);
        }
        else {
            throw "unexpected symbol";
        }
    }

    Poly make(string expr) {
        Poly ans;
        list<string> k;
        if (isdigit(expr[0])) {
            ans.update(k, stoi(expr));
        }
        else {
            k.push_back(expr);
            ans.update(k, 1);
        }
        return ans;
    }

    Poly parse(string expr) {
        vector<Poly> bucket;
        vector<char> symbols;
        int i = 0;
        while (i < expr.size()) {
            if (expr[i] == '(') {
                int c = 0;
                int j = i;
                for (; j < expr.size(); ++j) {
                    if (expr[j] == '(') {
                        ++c;
                    }
                    else if (expr[j] == ')') {
                        --c;
                    }
                    if (c == 0) break;
                }
                bucket.push_back(parse(expr.substr(i + 1, j - i - 1)));
                i = j;
            }
            else if (isdigit(expr[i]) || isalpha(expr[i])) {
                int j = i;
                for (; j < expr.size(); ++j) {
                    if (expr[j] == ' ') break;
                }
                bucket.push_back(make(expr.substr(i, j - i)));
                i = j;
            }
            else if (expr[i] != ' ') {
                symbols.push_back(expr[i]);
            }
            ++i;
        }

        for (int j = symbols.size() - 1; j >= 0; --j) {
            if (symbols[j] == '*') {
                bucket[j] = combine(bucket[j], bucket[j + 1], '*');
                bucket.erase(bucket.begin() + j + 1);
                symbols.erase(symbols.begin() + j);
            }
        }

        if (bucket.empty()) {
            return Poly();
        }

        Poly ans = bucket[0];
        for (int j = 0; j < symbols.size(); ++j) {
            ans = combine(ans, bucket[j + 1], symbols[j]);
        }

        return ans;
    }

    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        map<string, int> evalmap;

        for (int i = 0; i < evalvars.size(); ++i) {
            evalmap[evalvars[i]] = evalints[i];
        }

        return parse(expression).evaluate(evalmap).toVector();
    }
};


int main(void) {
    string expression = "e + 8 - a + 5";
    vector<string> evalvars = { "e" };
    vector<int> evalints = { 1 };

    Solution solution;
    auto&& ans = solution.basicCalculatorIV(expression, evalvars, evalints);

    for (auto& str : ans) {
        cout << str << " ";
    }
    cout << endl;

    system("pause");

    return 0;
}