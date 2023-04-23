#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
	int n = temperatures.size();
	vector<int> ans(n);
	stack<int> stk;
	for(int i = 0; i < n; ++i) {
		while(!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
			ans[stk.top()] = i - stk.top();
			stk.pop();
		}
		stk.emplace(i);
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> temperatures(n);
	for(int i = 0 ; i < n; ++i) {
		cin >> temperatures[i];
	}

	auto&& ans = dailyTemperatures(temperatures);

	for(auto x : ans) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}