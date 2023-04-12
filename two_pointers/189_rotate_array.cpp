#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int>& nums, int k) {
	int N = nums.size();
	// 当 k >= N 时，会出现循环，因此取 k = k % N
	k %= N;

	// 只需要遍历到 cnt 的位置，就可以保证所有元素都已经交换
	int cnt = gcd(N, k);
	for(int i = 0; i < cnt; ++i) {
		// 循环体内使用 prev 和 j 记录当前节点的起始值
		int prev = nums[i];
		int j = i;
		// 使用 do...while 循环保证最后一次位置可以访问到
		do {
			// 在内层循环中先更新 j 的值
			j = (j + k) % N;
			// 记录该位置的原始值
			int val = nums[j];
			// 赋值操作
			nums[j] = prev;
			// 将本次循环的结果带到下一次循环中
			prev = val;
		} while(i != j);
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> nums(n);

	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	rotate(nums, k);

	for(int i = 0; i < n; ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}