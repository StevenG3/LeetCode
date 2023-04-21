#include <bits/stdc++.h>

using namespace std;

// 方法一：记忆化搜索
// 使用helper(i, j)表示在该开区间(i, j)内可以得到的最大的乘积和，每次向(i, j)之间插入nums[mid]，计算插入之后的最大值
// int helper(vector<int>& nums, int i, int j, vector<vector<int>>& record) {
// 	int ans = 0;
// 	for(int mid = i + 1; mid <= j - 1; ++mid) {
// 		int A, B;
// 		if(!record[i][mid]) {
// 			A = helper(nums, i, mid, record);
// 			record[i][mid] = A;
// 		}
// 		else {
// 			A = record[i][mid];
// 		}

// 		if(!record[mid][j]) {
// 			B = helper(nums, mid, j, record);
// 			record[mid][j] = B;
// 		}
// 		else {
// 			B = record[mid][j];
// 		}
		
// 		ans = max(ans, nums[i] * nums[mid] * nums[j] + A + B);
// 	}

// 	return ans;
// }

// int maxCoins(vector<int>& nums) {
// 	int n = nums.size();
// 	vector<int> aux(n + 2);
// 	aux[0] = 1, aux[n + 1] = 1;
// 	for(int i = 0; i < n; ++i) {
// 		aux[i + 1] = nums[i];
// 	}

// 	// 目前mid的可选范围是[0, n - 1]
// 	vector<vector<int>> record(n + 2, vector<int>(n + 2));
// 	int ans = helper(aux, 0, n + 1, record);

// 	return ans;
// }

// 方法二：动态规划
// 按照记忆化搜索的方法更改成为动态规划，需要注意最后的答案是dp[0][n + 1]，因此 i 倒序遍历，j 正序遍历
int maxCoins(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> dp(n + 2, vector<int>(n + 2));
	vector<int> aux(n + 2);
	aux[0] = 1, aux[n + 1] = 1;
	for(int i = 0; i < n; ++i) {
		aux[i + 1] = nums[i];
	}

	int ans = 0;
	for(int i = n - 1; i >= 0; --i) {
		for(int j = i + 2; j <= n + 1; ++j) {
			for(int mid = i + 1; mid <= j - 1; ++mid) {
				dp[i][j] = max(dp[i][j], dp[i][mid] + dp[mid][j] + aux[i] * aux[mid] * aux[j]);
			}
		}
	}

	return dp[0][n + 1];
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	cout << maxCoins(nums) << endl;

	return 0;
}