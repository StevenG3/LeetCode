#include <bits/stdc++.h>

using namespace std;

/*
思路：将 0、2 都放在合适的位置，那么 1 必然已在合适的位置；所以整个过程只主动地移动 0、2，1 是被动地被移动的（可以看到循环跳过 nums[i] === 1）：

指针 p：初始化为 0，每确认一个 0，则向右移动 p；或者说 p 左侧的都是 0
指针 q：初始化为 n-1，每确认一个 2，则向左移动 q；或者说 q 右侧的都是 2
注意：指针 p 不能比 i 快，指针 q 不能比 i 慢
为什么要回退 i：nums[i] 用来和 nums[p]/nums[q] 作交换（分别确认一个 0/2），若交换后的 nums[i] 还是 0/2，那么 nums[i] 还要找到正确的位置并交换，因此要原地踏步。

在哪里回退 i：

由于指针 p 不能比 i 快，若在移动指针 p 后回退 i，将有可能导致指针 p 快于 i，从而导致死循环，因此应该在移动指针 q 后回退 i
再者说，不用关心指针 p 指向的是 0 还是 1（不可能是 2，因为 2 都被 i 换到后面去了），只要没有把 0 都找出来，i 都会继续与指针 p 交换值，因此在移动指针 q 时回退 i 是完全可以保证结果正确的
*/

// 使用双指针的思想修改数组内容
void sortColors(vector<int>& nums) {
	int n = nums.size();
	int p0 = 0, p2 = n - 1;

	for(int i = 0; i <= p2; ++i) {
		// 如果当前值为0，则与p0做交换，0/1进入下一个循环，2还需要进行处理
		if(nums[i] == 0) {
			swap(nums[i], nums[p0]);
			p0++;
		}
		// 如果挪过来的值为2，则与p2做交换，非1指针回退
		if(nums[i] == 2) {
			swap(nums[i], nums[p2]);
			p2--;
			if(nums[i] != 1) {
				i--;
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

	for(auto x : nums) {
		cout << x << " ";
	}
	cout << endl;

	sortColors(nums);

	for(auto x : nums) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}