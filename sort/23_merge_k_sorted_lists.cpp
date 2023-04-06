#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeKLists(vector<ListNode*>& lists) {
	auto cmp = [](ListNode* x, ListNode* y) {
		return x->val > y->val;
	};

	priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

	for(auto node : lists) {
		ListNode* curr = node;
		while(curr) {
			pq.emplace(curr);
			curr = curr->next;
		}
	}

	ListNode* dummy = new ListNode();
	ListNode* prev = dummy; 
	while(!pq.empty()) {
		ListNode* node = pq.top(); pq.pop();
		prev->next = node;
		prev = prev->next;
	}
	prev->next = nullptr; // 防止出现环

	return dummy->next;
}


int main() {
	int n;
	cin >> n;

	vector<ListNode*> lists(n);

	for(int i = 0; i < n; ++i) {
		int m;
		cin >> m;

		ListNode* dummy = new ListNode();
		ListNode* prev = dummy;
		for(int j = 0; j < m; ++j) {
			int x;
			cin >> x;

			ListNode* node = new ListNode(x);
			prev->next = node;
			prev = prev->next;
		}

		lists[i] = dummy->next;
	}

	ListNode* head = mergeKLists(lists);
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}