// 19. 删除链表的倒数第 N 个结点
// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

// 不需要建立虚拟头结点，直接使用快慢指针
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* fast = head;
	ListNode* slow = head;
	for (int i = 0; i < n; ++i) {
		fast = fast->next;
	}

	if (fast == nullptr) return head->next;

	// 此处使用 fast->next != nullptr 作为循环条件，而非 fast != nullptr
	while (fast->next != nullptr) {
		fast = fast->next;
		slow = slow->next;
	}

	// 此处使用 slow->next->next 作为赋值语句，而非 slow->next，确保slow指向待删除节点的前一个节点
	slow->next = slow->next->next;
	return head;
}

// 以下为测试代码
int main() {
	ListNode* head = new ListNode(1);
	ListNode* cur = head;
	for (int i = 2; i < 6; ++i) {
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	int n;
	cin >> n;
	ListNode* ans = removeNthFromEnd(head, n);
	while (ans != nullptr) {
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;
	return 0;
}