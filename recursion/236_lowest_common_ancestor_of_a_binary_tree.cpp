#include "../template/btree.h"

using namespace std;

// 可以使用指针的引用作为输出
// 使用递归的方法：1.p 和 q 同时存在于 root 的子节点中: 此种情况下，p 和 q 会处于 root 的两个子树上
// 2.p 或 q 是 root 节点，通过其子节点中存在另一个节点
bool helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
    if(root == NULL) return false;
	bool lson = helper(root->left, p, q, ans);
	bool rson = helper(root->right, p, q, ans);
	if((lson && rson) || (root->val == p->val || root->val == q->val) && (lson || rson)) {
		ans = root;
	}

	return root->val == p->val || root->val == q->val || lson || rson;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode* ans;
	helper(root, p, q, ans);
	return ans;
}
