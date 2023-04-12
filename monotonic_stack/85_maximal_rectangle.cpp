#include <bits/stdc++.h>

using namespace std;

// 暴力法
// 时间复杂度O((mn)^2)
// int maximalRectangle(vector<vector<char>>& matrix) {
// 	int m = matrix.size(), n = matrix[0].size();
// 	vector<vector<int>> presum(m + 1, vector<int>(n + 1));

// 	for(int i = 1; i <= m; ++i) {
// 		for(int j = 1; j <= n; ++j) {
// 			presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + (matrix[i - 1][j - 1] == '1');
// 		}
// 	}

// 	int ans = 0;
// 	for(int i = 1; i <= m; ++i) {
// 		for(int j = 1; j <= n; ++j) {
// 			for(int p = 0; p < i; ++p) {
// 				for(int q = 0; q < j; ++q) {
// 					int target = presum[i][j] - presum[p][j] - presum[i][q] + presum[p][q];
// 					if(target == (i - p) * (j - q) && ans < target) {
// 						ans = target;
// 					}
// 				}
// 			}
// 		}
// 	}

// 	return ans;
// }

// 参照 https://leetcode.cn/problems/largest-rectangle-in-histogram/ 给出本题的单调栈解法
// 需要先求出每个元素的左边连续1的数量，然后将其拆分成 84. 柱状图中最大的矩形 中的最大矩形问题
int largestRectangleArea(vector<int>& heights) {
	vector<int> stk;
	heights.emplace_back(0);
	int n = heights.size();
	stk.emplace_back(-1);
	int res = 0;

	for(int i = 0; i < n; ++i) {
		while(stk.back() != -1 && heights[i] < heights[stk.back()]) {
			int mid = stk.back();
			stk.pop_back();
			int w = i - 1 - stk.back();
			int h = heights[mid];
			res = max(res, w * h);
		}
		stk.emplace_back(i);
	}

	return res;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> left_one(m, vector<int>(n));
	for(int i = 0; i < m; ++i) {
		left_one[i][0] = (matrix[i][0] == '1');
	}

	for(int i = 0; i < m; ++i) {
		for(int j = 1; j < n; ++j) {
			left_one[i][j] = matrix[i][j] == '1' ? left_one[i][j - 1] + 1 : 0;
		}
	}

	int ans = 0;
	for(int j = 0; j < n; ++j) {
		vector<int> res(m);
		for(int i = 0; i < m; ++i) {
			res[i] = left_one[i][j];
		}
		ans = max(ans, largestRectangleArea(res));
	}

	return ans;
}


int main() {
	int m, n;
	cin >> m >> n;

	vector<vector<char>> matrix(m, vector<char>(n, '\0'));
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	int ans = maximalRectangle(matrix);

	cout << ans << endl;

	return 0;
}