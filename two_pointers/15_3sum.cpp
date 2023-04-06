// 这个方法就是我们常说的「双指针」，
// 当我们需要枚举数组中的两个元素时，如果我们发现随着第一个元素的递增，第二个元素是递减的，那么就可以使用双指针的方法

#include <bits/stdc++.h>

using namespace std;

// 思路：先排序，然后枚举第一个数，然后用双指针枚举第二个数和第三个数
// 注意去重
// 去重的时候，如果第一个数和第二个数相同，那么第二个数就不用再枚举了
// 如果第二个数和第三个数相同，那么第三个数就不用再枚举了
vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	vector<vector<int>> ans;

	for (int i = 0; i < nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		int target = -nums[i];
		int l = i + 1, r = nums.size() - 1;

		while (l < r) {
			if (nums[l] + nums[r] == target) {
				ans.push_back({nums[i], nums[l], nums[r]});
				while (l < r && nums[l] == nums[l + 1]) l++;
				while (l < r && nums[r] == nums[r - 1]) r--;
				l++;
				r--;
			} else if (nums[l] + nums[r] < target) {
				l++;
			} else {
				r--;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	vector<vector<int>>&& ans = threeSum(nums);
	for (auto v : ans) {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}