#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
	vector<char> stk;
	for(auto ch : s) {
		if(ch == '(' || ch == '{' || ch == '[') {
			stk.emplace_back(ch);
		}
		else if(ch == ')') {
			if(stk.empty() || stk.back() != '(') return false;
			stk.pop_back();
		}
		else if(ch == '}') {
			if(stk.empty() || stk.back() != '{') return false;
			stk.pop_back();
		}
		else {
			if(stk.empty() || stk.back() != '[') return false;
			stk.pop_back();
		}
	}

	return stk.empty();
}

int main() {
	string s;
	cin >> s;
	string str(s.begin() + 1, s.end() - 1);
	cout << isValid(str) << endl;
	return 0;
}