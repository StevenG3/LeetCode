#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int>& nums) {
	int n = nums.size();
	// 使用 candidate 记录当前过程的候选人，cnt 记录出现频次
	int candidate = INT_MIN, cnt = 1;
	for(int i = 0; i < n; ++i) {
		// 当候选者是当前数字时，cnt + 1
		if(candidate == nums[i]) cnt++;
		else {
			// 不是当前数字时，cnt - 1
			cnt--;
			// 减到 0 表示要更新候选人
			if(cnt == 0) {
				candidate = nums[i];
				cnt = 1;
			}
		}
	}
	
	return candidate;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	int ans = majorityElement(nums);

	cout << ans << endl;

	return 0;
}