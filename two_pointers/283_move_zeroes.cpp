#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& nums) {
	int n = nums.size();
	for(int i = 0, j = 0; i < n; ++i) {
		// j表示第一个零的位置
		// 由于j <= i，所以nums[j] != 0
		if(nums[i] != 0) swap(nums[i], nums[j++]);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);

	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	moveZeroes(nums);

	for(int i = 0; i < n; ++i) {
		cout << nums[i] << ' ';
	}
	cout << endl;

	return 0;
}