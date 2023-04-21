#include <bits/stdc++.h>

using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
	vector<int> vec(n + 1), ans(n);
	for(auto&& booking : bookings) {
		int start = booking[0] - 1, end = booking[1] - 1, val = booking[2];
		vec[start] += val;
		vec[end + 1] -= val;
	}

	for(int i = 0; i <= n; ++i) {
		if(i != 0) ans[i] = ans[i - 1] + vec[i];
		else ans[i] = vec[i];
	}

	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> bookings(m);
	for(int i = 0; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		bookings.emplace_back(vector<int>{u, v, w});
	}

	auto&& ans = corpFlightBookings(bookings, n);

	for(auto&& x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}