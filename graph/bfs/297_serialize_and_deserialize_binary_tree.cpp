#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
	// 使用 BFS 对节点进行存储，只传入存在的节点
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";

		queue<TreeNode*> que;
		que.emplace(root);
		string ans;
		while(!que.empty()) {
			TreeNode* node = que.front(); que.pop();
			if(node) {
				ans += to_string(node->val) + ',';
				que.emplace(node->left);
				que.emplace(node->right);
			}
			else {
				ans += "null,";
			}
		}

		return ans;
    }

    // Decodes your encoded data to tree.
	// 使用两个queue记录分割得到的字符和node，利用BFS建树
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

		string str;
		queue<string> queStr;
		queue<TreeNode*> queNode;
		for(auto ch : data) {
			if(ch == ',') {
				queStr.emplace(str);
				str.clear();
			}
			else {
				str += ch;
			}
		}

        str = queStr.front(); queStr.pop();
		TreeNode* root = new TreeNode(stoi(str));
		queNode.emplace(root);
		// 在循环中需要注意，只有当node存在时，才会去取queStr中的元素，取到之后还需要判断是否为null
		while(!queNode.empty()) {
			TreeNode* node = queNode.front(); queNode.pop();
			if(node) {
				string strLeft = queStr.front(); queStr.pop();
				if(strLeft != "null") {
					node->left = new TreeNode(stoi(strLeft));
					queNode.emplace(node->left);
				}
				string strRight = queStr.front(); queStr.pop();
				if(strRight != "null") {
					node->right = new TreeNode(stoi(strRight));
					queNode.emplace(node->right);
				}
			}
		}

		return root;
    }
};
