#include "../template/slist.h"

ListNode* mergeList(ListNode* head1, ListNode* head2) {
	ListNode* node1 = head1, * node2 = head2;
	ListNode* dummy = new ListNode();
	ListNode* node = dummy;
	while(node1 && node2) {
		if(node1->val < node2->val) {
			node->next = node1;
			node1 = node1->next;
		}
		else {
			node->next = node2;
			node2 = node2->next;
		}
		node = node->next;
	}

	if(node1) node->next = node1;
	if(node2) node->next = node2;

	return dummy->next;
}

ListNode* sortList(ListNode* head) {
	if(head == nullptr || head->next == nullptr) return head;

	ListNode* slow = head, * fast = head;
	while(fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode* head1 = head;
	ListNode* head2 = slow->next;
	slow->next = nullptr;
	ListNode* node1 = sortList(head1);
	ListNode* node2 = sortList(head2);

	ListNode* node = mergeList(node1, node2);

	return node;
}


int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	Slist st(nums);

	ListNode* node = sortList(st.GetHead());

	st.PrintSlist(node);

	return 0;
}