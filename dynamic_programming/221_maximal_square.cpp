#include <bits/stdc++.h>

using namespace std;

// 动态规划的思想， dp[i][j] 表示以 i, j 为正方形右下角的的正方形边长
int maximalSquare(vector<vector<char>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> dp(m, vector<int>(n));
	int ans = 0;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if(matrix[i][j] == '1') {
				if(i == 0 || j == 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
				}
				ans = max(ans, dp[i][j]);
			}
		}
	}

	return ans * ans;
}

int main() {
	int m, n;
	cin >> m >> n;

	vector<vector<char>> matrix(m, vector<char>(n));

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	int ans = maximalSquare(matrix);

	cout << ans << endl;
	
	return 0;
}