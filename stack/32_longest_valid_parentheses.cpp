#include <bits/stdc++.h>

using namespace std;

// 使用栈模拟整个过程，每次在出现右括号时，判断长度；栈底元素用于记录有效位置的前一个位置
int longestVaildParentheses(string s) {
	int n = s.size();
	stack<int> stk;
	stk.emplace(-1);
	int ans = 0;

	for(int i = 0; i < n; ++i) {
		if(s[i] == '(') {
			stk.emplace(i);
		}
		else {
			stk.pop();
			if(stk.empty()) {
				stk.emplace(i);
			}
			else {
				ans = max(ans, i - stk.top());
			}
		}
	}

	return ans;
}

int main() {
	string s;
	cin >> s;

	int ans = longestVaildParentheses(s);

	cout << ans << endl;

	return 0;
}