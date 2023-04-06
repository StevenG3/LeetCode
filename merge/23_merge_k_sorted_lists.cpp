// 23. 合并 K 个升序链表
//
// https://leetcode-cn.com/problems/merge-k-sorted-lists/
//
// Created by learntocode1024 on 11/29/20.
//
// Runtime: 20 ms, faster than 99.05%
// Memory Usage: 13.1 MB, less than 5.26%
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
	// 优先队列
	// ListNode* head = new ListNode();
	// ListNode* tail = head;
	// priority_queue<ListNode*, vector<ListNode*>, greater<ListNode*>> pq;
	// for (ListNode* node : lists) {
	//   if (node) pq.push(node);
	// }
	// while (!pq.empty()) {
	//   ListNode* node = pq.top();
	//   pq.pop();
	//   tail->next = node;
	//   tail = tail->next;
	//   if (node->next) pq.push(node->next);
	// }
	// return head->next;
	
	// 分治
	return merge(lists, 0, lists.size() - 1);
  }

	ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
		ListNode* dummy = new ListNode();
		ListNode* prev = dummy;
		while(head1 && head2) {
			if(head1->val < head2->val) {
				prev->next = head1;
				head1 = head1->next;
			}
			else {
				prev->next = head2;
				head2 = head2->next;
			}
			prev = prev->next;
		}

		if(head1) prev->next = head1;
		if(head2) prev->next = head2;

		return dummy->next;
	}

	ListNode* merge(vector<ListNode*>& lists, int left, int right) {
		if(left > right) return nullptr;

		if(left == right) return lists[left];

		int mid = left + ((right - left) >> 1);
		ListNode* node1 = merge(lists, left, mid);
		ListNode* node2 = merge(lists, mid + 1, right);

		return mergeTwoLists(node1, node2);
	}
};

// 输入一个数组作为链表的头节点
ListNode* createList(vector<int> nums) {
  ListNode* head = new ListNode();
  ListNode* tail = head;
  for (int num : nums) {
	tail->next = new ListNode(num);
	tail = tail->next;
  }
  return head->next;
}

// 打印链表
void printList(ListNode* head) {
  while (head) {
	cout << head->val << " ";
	head = head->next;
  }
  cout << endl;
}

int main() {
  vector<vector<int>> nums = {
	  {1, 4, 5},
	  {1, 3, 4},
	  {2, 6}
  };
  vector<ListNode*> lists;
  for (vector<int> num : nums) {
	lists.push_back(createList(num));
  }
  Solution s;
  ListNode* ans = s.mergeKLists(lists);
  printList(ans);
  return 0;
}