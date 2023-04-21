#include <bits/stdc++.h>

using namespace std;

// 利用哈希表的思想，对于数组 nums 而言，可能缺失的正整数是 1 ~ N + 1
int firstMissingPositive(vector<int>& nums) {
	int n = nums.size();

	// 将所有非整数替换成大于n的正数
	for(int i = 0; i < n; ++i) {
		if(nums[i] <= 0)
			nums[i] = n + 1; 
	}

	for(int i = 0; i < n; ++i) {
		// pos即为数组中的元素应该存在的位置
		int pos = abs(nums[i]) - 1;
		// 如果该元素出现了，其位置在 [0, n) 中，且没有被更改过 (> 0) ，则将其位置进行标记，标记方法为取相反数
		if(pos >= 0 && pos < n && nums[pos] > 0) 
			nums[pos] = -nums[pos];
	}

	// 找出第一个大于0为的位置，即为缺少的元素
	int i = 0;
	for( ; i < n; ++i) {
		if(nums[i] > 0) break; 
	}

	return i + 1;
}

// 方法二：使元素出现在其应该出现的位置

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	int ans = firstMissingPositive(nums);

	cout << ans << endl;

	return 0;
}