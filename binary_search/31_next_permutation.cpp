#include <bits/stdc++.h>

using namespace std;

// 总体思想：找到第一个顺序排列的数字作为【较小数】，找到后续位置中的比该数字大的第一个数字作为【较大数】，交换两个数字的位置后，对【较大数】的后续数字进行排序
void nextPermutation(vector<int>& nums) {
	int n = nums.size();

	// 找出第一个正序的数，这个数将与其后面第一个比它大的数交换
	int i;
	for(i = n - 2; i >= 0; --i) {
		if(nums[i] < nums[i + 1]) {
			break;
		}
	}

	// 当数组均为倒序排序时，整体翻转
	if(i == -1) {
		reverse(nums.begin(), nums.end());
		return;
	}

	// 找到第一个比nums[i]大的数
	// 正序时
	// lower_bound：找到第一个大于或等于num的数字
	// upper_bound：找到第一个大于num的数字
	// 倒序时
	// lower_bound：找到第一个小于或等于num的数字
	// upper_bound：找到第一个小于num的数字
	// 此处将找到的位置减一，即可以得到倒序中第一个大于num的数字
	int j = lower_bound(nums.begin() + i + 1, nums.end(), nums[i], greater<int>()) - nums.begin() - 1;

	// 将位置i和j的数字进行交换
	swap(nums[i], nums[j]);

	// 对i的后续位置进行排序
	sort(nums.begin() + i + 1, nums.end());

	return;
}

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	nextPermutation(nums);

	for(auto x : nums) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}