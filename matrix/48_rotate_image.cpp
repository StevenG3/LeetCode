#include <bits/stdc++.h>

using namespace std;

// 思考这道题时，考虑以行和列为单位观察一个行/列旋转之后的位置，将其连接起来就可以知道变化规律
// matrix[col][n - row - 1] = matrix[row][col]
// 方法一：注意遍历的范围 
void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	for(int i = 0; i < n / 2; ++i) {
		for(int j = 0; j < (n + 1) / 2; ++j) {
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[n - j - 1][i];
			matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
			matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
			matrix[j][n - i - 1] = tmp;
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n));
	for(int i= 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	rotate(matrix);

	for(int i= 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << matrix[i][j];
		}
		cout << endl;
	}

	return 0;
}