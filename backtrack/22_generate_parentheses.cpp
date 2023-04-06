#include <bits/stdc++.h>

using namespace std;

// 记录左右括号的数量，当左括号数量大于0时，可以添加左括号，当右括号数量大于左括号数量时，可以添加右括号
void backtrack(vector<string>& ans, string& path, int left, int right) {
	if (left == 0 && right == 0) {
		ans.push_back(path);
		return;
	}
	if (left > 0) {
		path.push_back('(');
		backtrack(ans, path, left - 1, right);
		path.pop_back();
	}
	if (right > left) {
	path.push_back(')');
	backtrack(ans, path, left, right - 1);
	path.pop_back();
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> ans;
	string path;
	backtrack(ans, path, n, n);
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<string> ans = generateParenthesis(n);
	for (string str : ans) {
		cout << str << endl;
	}
	return 0;
}
