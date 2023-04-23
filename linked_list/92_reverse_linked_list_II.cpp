struct ListNode {    
	int val;
    ListNode *next;
};

ListNode* reverse(ListNode* head) {
	if(head == nullptr || head->next == nullptr) {
		return head;
	}

	ListNode* node = reverse(head->next);
	head->next->next = head;
	head->next = nullptr;

	return node;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
	int l = left - 1, r = right;
	ListNode* prevM = head, * nodeN = head;
	ListNode* dummy = new ListNode;
	dummy->next = head;
	int cnt = 0;
	for(ListNode* node = dummy; node != nullptr; node = node->next) {
		if(l == cnt) prevM = node;
		if(r == cnt) {
			nodeN = node;
			break;
		}
		cnt++;
	}

	ListNode* nodeM = prevM->next;
	ListNode* nextN = nodeN->next;

	prevM->next = nullptr;
	nodeN->next = nullptr;

	ListNode* node = reverse(nodeM);

	prevM->next = node;
	while(node->next) {
		node = node->next;
	}

	node->next = nextN;

	return dummy->next;
}
