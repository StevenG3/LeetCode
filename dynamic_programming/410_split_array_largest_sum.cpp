/* 
*  [将数组分割成 m 段，求...] 是动态规划题目常见的问法
* 令 f[i][j] 表示将数组的前 i 个数分割为 j 段所能得到的最大连续子数组和的最小值
* 使用 sub(i, j) 表示数组 nums 中下标落在区间 [i, j] 内的数的和
* 状态转移函数为 f[i][j] = min_{k = 0}^{i - 1} {max(f[k][j - 1], sub(k + 1, i))}
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int splitArray(vector<int>& nums, int m) {
	int n = nums.size();
	vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
	vector<long long> sub(n + 1, 0);

	for(int i = 0; i < n; ++i) {
		sub[i + 1] = sub[i] + nums[i];
	}
	f[0][0] = 0;
	// 最外层遍历物品总数n
	for(int i = 1; i <= n; ++i) {
		// 中间层遍历分组，分组的数量可能是m或者i，当 i < m 时，表示
		for(int j = 1; j <= min(m, i); ++j) {
			for(int k = 0; k < i; ++k) {
				f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
			}
		}
	}

	return (int)f[n][m];
}

int main() {
	int n;
	cin >> n;

	vector<int> vec(n);
	for(int i = 0; i < n; ++i) {
		cin >> vec[i];
	}

	int m;
	cin >> m;

	int ans = splitArray(vec, m);

	cout << ans << endl;

	return 0;
}