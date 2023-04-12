#include "../template/unionfind.h"

using namespace std;

int longestConsecutive(vector<int>& nums) {
	if(nums.empty()) return 0;
	// 去重
	unordered_map<int, int> ump;
	int cnt = 0;
	for(auto x : nums) {
		if(ump.count(x) == 0) {
			ump[x] = cnt++;
		}
	}

	UnionFind uf(cnt);
	for(auto&& [x, pos] : ump) {
		if(ump.count(x + 1)) {
			uf.unite(pos, ump[x + 1]);
		}
	}

	return uf.getMaxSize();
}

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	cout << longestConsecutive(nums) << endl;

	return 0;
}