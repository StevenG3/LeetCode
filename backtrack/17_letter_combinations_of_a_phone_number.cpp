// 17. 电话号码的字母组合
// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
// Created by learntocode1024 on 11/29/20.
// 利用回溯的思想
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 90.91%
#include <bits/stdc++.h>

using namespace std;

vector<string> photoMap = {
	"",     // 0
	"",     // 1
	"abc",  // 2
	"def",  // 3
	"ghi",  // 4
	"jkl",  // 5
	"mno",  // 6
	"pqrs", // 7
	"tuv",  // 8
	"wxyz"  // 9
};

void backtrack(string& digits, int index, string& path, vector<string>& ans) {
	if (index == digits.size()) {
		ans.push_back(path);
		return;
	}
	for (char c : photoMap[digits[index] - '0']) {
		path.push_back(c);
		backtrack(digits, index + 1, path, ans);
		path.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	if (digits.empty()) return {};
	vector<string> ans;
	string path;
	backtrack(digits, 0, path, ans);
	return ans;
}

int main() {
	string digits;
	cin >> digits;
	vector<string>&& ans = letterCombinations(digits);
	for (string s : ans) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
