#include <bits/stdc++.h>

using namespace std;

vector<int> countBits(int n) {
	vector<int> dp(n + 1);

	for(int i = 1; i <= n; ++i) {
		dp[i] = dp[i & (i - 1)] + 1;
	}

	return dp;
}

int main() {
	int n;
	cin >> n;

	auto&& ans = countBits(n);

	for(auto&& x : ans) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}