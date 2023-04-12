#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	vector<int> stk;
	heights.emplace_back(0);
	int n = heights.size();
	stk.emplace_back(-1);
	int res = 0;

	for(int i = 0; i < n; ++i) {
		while(stk.back() != -1 && heights[i] < heights[stk.back()]) {
			int mid = stk.back();
			stk.pop_back();
			int w = i - 1 - stk.back();
			int h = heights[mid];
			res = max(res, w * h);
		}
		stk.emplace_back(i);
	}

	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> heights(n);
	for(int i = 0; i < n; ++i) {
		cin >> heights[i];
	}

	int ans = largestRectangleArea(heights);

	cout << ans << endl;

	return 0;
}