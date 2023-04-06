#include <iostream>
#include <vector>

using namespace std;

// 使用该函数获取第k个元素
int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
	int m = nums1.size(), n = nums2.size();

	int idx1 = 0, idx2 = 0;

	// 处理三种边界问题
	// 取最新的k值时，使用相减的方法
	// 更新索引的时候将索引更新为加1
	while(true) {
		if(idx1 == m) {
			return nums2[idx2 + k - 1];
		}

		if(idx2 == n) {
			return nums1[idx1 + k - 1];
		}

		if(k == 1) {
			return min(nums1[idx1], nums2[idx2]);
		}

		int p1 = min(idx1 + k / 2 - 1, m - 1); // 此处需要取两者之间的最小值
		int p2 = min(idx2 + k / 2 - 1, n - 1);
		int val1 = nums1[p1];
		int val2 = nums2[p2];
		if(val1 <= val2) {
			k -= p1 - idx1 + 1;
			idx1 = p1 + 1;
		}
		else {
			k -= p2 - idx2 + 1;
			idx2 = p2 + 1;
		}
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int len = num1.size() + nums2.size();
	if(len % 2 == 1) {
		return getKthElement(nums1, nums2, (len + 1) / 2);
	}

	return (getKthElement(nums1, nums2, len / 2) + getKthElement(nums1, nums2, len / 2 + 1)) / 2.0;
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<int> nums1(m), nums2(n);
	for(int i = 0; i < m; ++i) {
		cin >> nums1[i];
	}

	for(int i = 0; i < n; ++i) {
		cin >> nums2[i];
	}

	double ans = findMedianSortedArrays(nums1, nums2);

	cout << ans << endl;

	return 0;
}