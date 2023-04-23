#include <bits/stdc++.h>

using namespace std;

// 假设无序部分是 [L, R] , 那么 nums[R]必然小于前序的最大值，因为如果nums[R]比前序的最大值大，那么乱序部分将来到[L, R - 1]
// 同理可知nums[L]必然小于后序的最小值
int findUnsortedSubarray(vector<int>& nums) {
	int n = nums.size();
	int start = 1, end = 0;
	int maxn = INT_MIN, minn = INT_MAX;
	for(int i = 0; i < n; ++i) {
		if(nums[i] < maxn) {
			end = i;
		}
		else {
			maxn = nums[i];
		}

		if(nums[n - i - 1] > minn) {
			start = n - i - 1;
		}
		else {
			minn = nums[n - i - 1];
		}
	}

	return end - start + 1;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	int ans = findUnsortedSubarray(nums);

	cout << ans << endl;

	return 0;
}