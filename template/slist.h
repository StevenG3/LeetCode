#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Slist {
public:
	// 构造函数创建链表
	Slist(vector<int>& nums) {
		int n = nums.size();
		if(n == 0) return;

		head_ = new ListNode(nums[0]);
		ListNode* curr = head_;

		for(int i = 1; i < nums.size(); ++i) {
			curr->next = new ListNode(nums[i]);
			curr = curr->next;
		}
	}

	// 析构函数
	~Slist() {
		ListNode* node = head_;
		while(node) {
			ListNode* prev = node;
			node = node->next;
			delete prev;
		}
	}

	void PrintSlist(ListNode* head) {
		ListNode* node = head;
		while(node) {
			cout << node->val << " ";
			node = node->next;
		}
		cout << endl;
	}

	void PrintSlist() {
		PrintSlist(head_);
	}

	ListNode* GetHead() { return head_; }
private:
	ListNode* head_ = nullptr;
};