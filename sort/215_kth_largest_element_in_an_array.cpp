#include <bits/stdc++.h>

using namespace std;

// 利用快速排序的思想
// partition 函数的作用是，选取 nums[right] 作为标杆，将小于等于该数的元素放在左边，大于该数的元素放在右边，返回其位置 i
int partition(vector<int>& nums, int left, int right) {
	int x = nums[right], i = left;
	for(int j = left; j < right; ++j) {
		if(nums[j] <= x) {
			swap(nums[i++], nums[j]);
		}
	}
	swap(nums[i], nums[right]);

	return i;
}

// randomPartition 函数的作用是，随机选取一个范围内的元素作为标杆，并将其交换到该分段的最右边
int randomPartition(vector<int>& nums, int left, int right) {
	int i = left + rand() % (right - left + 1);
	swap(nums[i], nums[right]);
	return partition(nums, left, right);
}

// 从区间 [left, right] 选取第 k 个元素
// 选取方法：利用 randomPartition 接口随机获取一个位置 q ，
// 返回时，已经将小于等于 nums[q] 的数字放在了 q 位置的左侧，大于该数字的放在了 q 位置的右侧
int findKthLargest(vector<int>& nums, int k, int left, int right) {
	int q = randomPartition(nums, left, right);
	if(q == k) {
		return nums[q];
	}

	return q < k ? findKthLargest(nums, k, q + 1, right) : findKthLargest(nums, k, left, q - 1);
} 

int findKthLargest(vector<int>& nums, int k) {
	srand(time(nullptr));

	return findKthLargest(nums, nums.size() - k, 0, nums.size() - 1);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	int ans = findKthLargest(nums, k);

	cout << ans << endl;

	return 0;
}