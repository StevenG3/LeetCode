#include <bits/stdc++.h>

using namespace std;

string decodeString(string s) {
	vector<string> stk;
	string str;

	for(auto&& ch : s) {
		if(isdigit(ch)) {
			// 可能存在的情况：str非空，且str.back()是字母
			if(!str.empty() && isalpha(str.back())) {
				stk.emplace_back(str);
				str.clear();
			}
			str += ch;
		}
		else if(isalpha(ch)) {
			str += ch;
		}
		else if(ch == '[') {
			stk.emplace_back(str);
			str.clear();
			// 使用"#"作为分隔符
			stk.emplace_back("#");
		}
		else {
			stk.emplace_back(str);
			str.clear();
			string repeat;
			// 前序一定会出现"#"
			while(stk.back() != "#") {
				repeat = stk.back() + repeat; stk.pop_back();
			}
			// 将"#"弹出
			stk.pop_back();
			int k = stoi(stk.back()); stk.pop_back();
			for(int i = 0; i < k; ++i) {
				str += repeat;
			}
			stk.emplace_back(str);
			str.clear();
		}
	}

	// 可能出现的情况：不以"]"结尾，需要将非空str加入到stk
	if(!str.empty()) {
		stk.emplace_back(str);
		str.clear();
	}

	// 此时stk存放所有的已经解析好的字符串
	string ans;
	for(auto&& ss : stk) {
		ans += ss;
	}

	return ans;
}

int main() {
	string s;
	cin >> s;
	string&& ans = decodeString(s);

	cout << ans << endl;

	return 0;
}