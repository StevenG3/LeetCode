#include <bits/stdc++.h>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	int m = prerequisites.size();

	vector<vector<int>> graph(numCourses);
	vector<int> indeg(numCourses);
	for(auto pre : prerequisites) {
		graph[pre[1]].emplace_back(pre[0]);
		// 对节点 pre[0] 的出度加一
		++indeg[pre[0]];
	}

	// 将所有入度为 0 的节点加入到 que 中
	queue<int> que;
	for(int i = 0; i < numCourses; ++i) {
		if(indeg[i] == 0) que.emplace(i);
	}

	// 统计所有入度为 0 的节点
	int ans = 0;
	while(!que.empty()) {
		int u = que.front(); que.pop();
		ans++;
		for(auto v : graph[u]) {
			--indeg[v];
			// 入度为0时，将节点加入到 que 中
			if(!indeg[v]) {
				que.emplace(v);
			}
		}
	}

	return ans == numCourses;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> prerequisites(m);
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> v >> u;
		prerequisites[i].emplace_back(pair{v, u});
	}

	bool ans = canFinish(n, prerequisites);

	if(ans == true) cout << "true" << endl;
	else cout << "false" << endl;

	return 0;
}