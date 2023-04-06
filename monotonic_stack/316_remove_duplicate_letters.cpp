#include <bits/stdc++.h>

using namespace std;

string removeDuplicateLetters(string s) {
	int n = s.size();
	vector<int> last_pos(26, -1);
	for(int i = n - 1; i >= 0; --i) {
		if(last_pos[s[i] - 'a'] == -1) {
			last_pos[s[i] - 'a'] = i;
		}
	}

	vector<char> stk;

	vector<int> seen(26);

	for(int i = 0; i < n; ++i) {
		// 如果该字符出现过，直接跳过
		if(seen[s[i] - 'a'] == 0) {
			// 可以删除该字符的条件：1、栈不为空；2.栈顶元素大于等于当前元素；3.后面还有该字符
			while(!stk.empty() && stk.back() >= s[i] && last_pos[stk.back() - 'a'] >= i) {
				seen[stk.back() - 'a'] = 0;
				stk.pop_back();
			}
			stk.emplace_back(s[i]);
			seen[s[i] - 'a'] = 1;
		}
	}

	string ans(stk.begin(), stk.end());

	return ans;
}

int main() {
	string s;
	cin >> s;

	string ans = removeDuplicateLetters(s);

	cout << ans << endl;

	return 0;
}