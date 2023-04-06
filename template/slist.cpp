#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(): val(-1), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* y): val(x), next(y) {}
};

ListNode* buildsList(vector<int>& vec) {
	if(vec.empty()) return nullptr;

	ListNode* root = new ListNode(vec[0]);
	ListNode* curr = root;

	for(int i = 1; i < vec.size(); ++i) {
		curr->next = new ListNode(vec[i]);
		curr = curr->next;
	}

	return root;
}

string printsList(ListNode* root) {
	if(root == nullptr) return "{}";

	string ans;
	ans += '{';
	ListNode* node = root;
	while(node) {
		ans += to_string(node->val) + ',';
		node = node->next;
	}
	
	ans.pop_back();

	ans += '}';

	return ans;
}

int main() {
	// 输入形式：{1,2,3,4,5} 前后两个括号将被去除，元素之间用逗号隔开，不能有空格
	string s;
	cin >> s;

	string str(s.begin() + 1, s.end() - 1);
	stringstream ss(str);
	string token;
	vector<int> vec;

	while(getline(ss, token, ',')) {
		vec.emplace_back(stoi(token));
	}

	ListNode* lst = buildsList(vec);

	string res = printsList(lst);

	cout << res << endl;

	return 0;
}