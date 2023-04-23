#include "../template/btree.h"

using namespace std;

typedef long long LL;

void helper(TreeNode* root, int targetSum, unordered_map<LL, int>& cache, LL preSum, int& ans) {
	if(root == nullptr) return;
	preSum += root->val;
	if(cache.count(preSum - targetSum)) ans += cache[preSum - targetSum];

	// 回溯的方法，先插入cache，再从cache中删除
	cache[preSum]++;
	helper(root->left, targetSum, cache, preSum, ans);
	helper(root->right, targetSum, cache, preSum, ans);
	cache[preSum]--;
	if(cache[preSum] == 0) cache.erase(preSum);
}

int pathSum(TreeNode* root, int targetSum) {
	// 每一条从根节点到子节点的路径上保留前缀和
	int ans = 0;
	// 此处先插入一个 {0, 1} 对
	unordered_map<LL, int> cache{{0, 1}};
	helper(root, targetSum, cache, 0, ans);

	return ans;
}