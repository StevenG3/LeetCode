#include "../template/unionfind.h"

int numIslands(std::vector<std::vector<char>>& grid) {
	int m = grid.size(), n = grid[0].size();
	int cnt = 0;
	std::unordered_map<int, int> ump;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if(grid[i][j] == '1') ump[i * n + j] = cnt++;
		}
	}

	UnionFind uf(cnt);

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if(grid[i][j] == '1') {
				if(i + 1 < m && grid[i + 1][j] == '1') uf.unite(ump[i * n + j], ump[(i + 1) * n + j]);
				if(j + 1 < n && grid[i][j + 1] == '1') uf.unite(ump[i * n + j], ump[i * n + j + 1]);
			}
		}
	}

	return uf.getCount();
}

int main() {
	int m, n;
	std::cin >> m >> n;

	std::vector<std::vector<char>> grid(m, std::vector<char>(n, '\0'));
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			std::cin >> grid[i][j];
		}
	}

	std::cout << numIslands(grid) << std::endl;

	return 0;
}