#include <bits/stdc++.h>

using namespace std;

// 利用环形链表的特点，在数组中有重复元素，则一定会出现成环的情况
int findDuplicate(vector<int>& nums) {
	// 使用快慢指针找到相遇点
	// 使用该方法必须要满足，起点不在环内
	int slow = 0, fast = 0;
	do {
		slow = nums[slow];
		fast = nums[nums[fast]];
	} while(slow != fast);

	slow = 0;
	while(slow != fast) {
		slow = nums[slow];
		fast = nums[fast];
	}

	return slow;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	int ans = findDuplicate(nums);

	cout << ans << endl;

	return 0;
}