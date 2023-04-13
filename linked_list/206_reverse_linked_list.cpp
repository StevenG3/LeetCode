#include "../template/slist.h"

using namespace std;

ListNode* reverseList(ListNode* head) {
	if(head == nullptr || head->next == nullptr) return head;

	ListNode* newHead = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;
	return newHead;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	Slist st(nums);

	ListNode* head = st.GetHead();

	ListNode* newHead = reverseList(head);

	st.PrintSlist(newHead);

	return 0;
}