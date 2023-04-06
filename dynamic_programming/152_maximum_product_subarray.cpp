// 动态规划的思想，但是应该注意：当前位置的最优解未必是由前一个位置的最优解转移得到的。
// 根据正负性进行分类讨论

#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums) {
	int n = nums.size();
	vector<int> maxF(nums), minF(nums);

	for(int i = 1; i < n; ++i) {
		maxF[i] = max({maxF[i - 1] * nums[i], nums[i], minF[i - 1] * nums[i]});
		minF[i] = min({minF[i - 1] * nums[i], nums[i], maxF[i - 1] * nums[i]});
	}

	return *max_element(maxF.begin(), maxF.end());
}

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	int ans = maxProduct(nums);

	cout << ans << endl;

	return 0;
}