#include <bits/stdc++.h>

class UnionFind {
public:
    UnionFind(int n): count(n), parent(n), rank(n), size(n) {
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
            rank[i] = 0;
        }
    }

    void unite(int x, int y) {
        int rootx = find(x), rooty = find(y);

        if(rootx == rooty) {
            return;
        }

        if(rank[rootx] < rank[rooty]) std::swap(rootx, rooty);

        parent[rooty] = rootx;

        if(rank[rootx] == rank[rooty]) rank[rootx] += 1;

        size[rootx] += size[rooty];

        count--;
    }

    int getCount() const { return count; }
    int getMaxSize() const { return *std::max_element(size.begin(), size.end()); }

    void getSize() {
        for(auto&& x : size) std::cout << x << " ";
        std::cout << std::endl;
    } 

    void getRank() {
        for(auto&& x : rank) std::cout << x << " ";
        std::cout << std::endl;
    }
    
private:
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<int> size;
    int count;
};