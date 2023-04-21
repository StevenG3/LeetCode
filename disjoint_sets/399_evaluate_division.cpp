#include <bits/stdc++.h>

using namespace std;

// 带权并查集: 在基础的并查集的基础上，维护对公共父节点的权值
// 当查询节点x的父节点时, 如果f[x] != x, 需要先找到 f[x] 的父亲 father, 并将f[x]更新为 father
// 当合并两个节点时，先找到两者的父亲 fx 和 fy, 并将 f[fx] 更新为 fy 

// findf函数：找到节点的父节点，并更新权值
int findf(vector<int>& f, vector<double>& w, int x) {
	if(f[x] != x) {
		int father = findf(f, w, f[x]);
		w[x] *= w[f[x]];
		f[x] = father;
	}
	return f[x];
}

// merge函数：找到两个节点的父节点，并将其合并
void merge(vector<int>& f, vector<double>& w, int x, int y, double val) {
	int fx = findf(f, w, x);
	int fy = findf(f, w, y);
	f[fx] = fy;
	w[fx] = val * w[y] / w[x];
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	int nvars = 0;
	// 使用哈希压缩字符串，建立映射关系
	unordered_map<string, int> variables;

	int n = equations.size();
	for(int i = 0; i < n; ++i) {
		if(variables.find(equations[i][0]) == variables.end()) {
			variables[equations[i][0]] = nvars++;
		}
		if(variables.find(equations[i][0]) == variables.end()) {
			variables[equations[i][1]] = nvars++;
		}
	}

	vector<int> f(nvars);
	vector<double> w(nvars, 1.0);
	for(int i = 0; i < nvars; ++i) {
		f[i] = i;
	}

	// 将关联元素合并
	for(int i = 0; i < n; ++i) {
		int va = variables[equations[i][0]], vb = variables[equations[i][1]];
		merge(f, w, va, vb, values[i]);
	}

	vector<double> ret;
	for(const auto& q : queries) {
		double result = -1.0;
		if(variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()) {
			int ia = variables[q[0]], ib = variables[q[1]];
			// 获取父节点，如果一致则更新result
			int fa = findf(f, w, ia), fb = findf(f, w, ib);
			if(fa == fb) {
				result = w[ia] / w[ib];
			}
		}
		ret.emplace_back(result);
	}
}
