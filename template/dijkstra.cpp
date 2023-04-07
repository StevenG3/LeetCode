// 实现dijkstra算法
#include <bits/stdc++.h>

using namespace std;

void dijkstra(int n, int s, vector<vector<int>> &g, vector<int> &d) {
	d = vector<int>(n, INT_MAX);
	d[s] = 0;
	vector<bool> st(n);
	// 从小到大枚举每个点
	for (int i = 0; i < n; i++) {
		// t存储未被标记的点中距离最小的点
		int t = -1;
		// 从小到大枚举每个点，找到未被标记的点中距离最小的点
		for (int j = 0; j < n; j++) {
			if (!st[j] && (t == -1 || d[t] > d[j])) t = j;
		}
		st[t] = true;
		// 从小到大枚举每个点，尝试用t更新d[j]
		for (int j = 0; j < n; j++) {
			d[j] = min(d[j], d[t] + g[t][j]);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n, INT_MAX));
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a][b] = min(g[a][b], w);
	}
	vector<int> d;
	dijkstra(n, 0, g, d);
	for (int i = 0; i < n; i++) cout << d[i] << ' ';
	cout << endl;
	return 0;
}