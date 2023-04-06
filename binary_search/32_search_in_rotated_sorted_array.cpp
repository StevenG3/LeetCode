#include <bits/stdc++.h>

using namespace std;


// 为什么这么典型二分查找的问题，却需要花费这么长时间思考呢
// 二分查找的思路是：每次将数组分为两部分，判断目标值在哪一部分，然后继续在该部分进行二分查找
// 但是这道题目中，数组并不是完全有序的，因此需要判断左半部分是否有序，右半部分是否有序
// 如果左半部分有序，则判断目标值是否在左半部分，如果在，则继续在左半部分进行二分查找
// 如果左半部分无序，则继续在右半部分进行二分查找
// 如果右半部分有序，则判断目标值是否在右半部分，如果在，则继续在右半部分进行二分查找
// 如果右半部分无序，则继续在左半部分进行二分查找
int search(vector<int>& nums, int target) {
	int n = nums.size();

	if(n == 0) return -1;

	if(n == 1) return nums[0] == target ? 0 : -1;

	int left = 0, right = n - 1;

	while(left <= right) {
		int mid = left + ((right - left) >> 1);

		if(nums[mid] == target) return mid;
		else if(nums[left] <= nums[mid]) {
			// 左半部分有序
			if(nums[left] <= target && target < nums[mid]) left = mid + 1;
			else right = mid - 1;
		}
		else {
			// 右半部分有序
			if(nums[mid] < target && target <= nums[right]) left = mid + 1;
			else right = mid - 1;
		}
	}

	return -1;
}

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	int target;
	cin >> target;

	int ans = search(nums, target);

	cout << ans << endl;

	return 0;
}