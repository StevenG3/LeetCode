#include <bits/stdc++.h>

using namespace std;

// 按照首元素升序，次元素降序的顺序排序
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	sort(people.begin(), people.end(), [](const vector<int>& A, const vector<int>& B){return A[0] == B[0] ? A[1] > B[1] : A[0] < B[0];});

	int n = people.size();

	vector<vector<int>> ans(n);
	vector<int> used(n);

	for(int i = 0; i < n; ++i) {
		int space = people[i][1] + 1;
		// 此处为了结果中不出现 - 1 ，在此处初始值设置为 -1
		int j = -1;
		while(space) {
			if(used[++j] == 0) {
				space--;
			}
		}
		used[j] = 1;
		ans[j] = people[i];
	}

	return ans;
}
