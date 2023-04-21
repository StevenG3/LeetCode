#include <bits/stdc++.h>

using namespace std;

// 算法原理：使用第一行和第一列标识该行/列是否被0标记
// 算法步骤：
// 1. 利用两个标志位 flag_row 和 flag_col 标明
//
//
void setZeroes(vector<vector<int>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();

	bool flag_row = false, flag_col = false;
	for(int i = 0; i < m; ++i) {
		if(matrix[i][0] == 0) flag_col = true;
	}

	for(int j = 0; j < n; ++j) {
		if(matrix[0][j] == 0) flag_row = true;
	}

	for(int i = 1; i < m; ++i) {
		for(int j = 1; j < n; ++j) {
			if(matrix[i][j] == 0) {
				matrix[i][0] = 0, matrix[0][j] = 0;
			}
		}
	}

	for(int i = 1; i < m; ++i) {
		for(int j = 1; j < n; ++j) {
			if(matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}

	if(flag_col) {
		for(int i = 0; i < m; ++i) {
			matrix[i][0] = 0;
		}
	}

	if(flag_row) {
		for(int j = 0; j < n; ++j) {
			matrix[0][j] = 0;
		}
	}
}

int main() {
	int m, n;
	cin >> m >> n;

	vector<vector<int>> matrix(m, vector<int>(n));
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	setZeroes(matrix);

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}