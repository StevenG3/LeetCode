#include "../template/btree.h"

// 用递归的方法，依次遍历每个节点，添加到root1上。
// 如果root1不存在，则返回root2
// 如果两者同时存在，则将值累加
// 通过递归的方式传递给左右节点
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
	if(root1 == nullptr) return root2;
	if(root2 == nullptr) return root1;

	root1->val += root2->val;

	root1->left = mergeTrees(root1->left, root2->left);
	root1->right = mergeTrees(root1->right, root2->right);

	return root1;
}