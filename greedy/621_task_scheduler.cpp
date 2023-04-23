#include <bits/stdc++.h>

using namespace std;

// 统计最大的执行次数和对应的元素的个数
int leastInterval(vector<char>& tasks, int n) {
	unordered_map<char, int> freq;
	for(char ch : tasks) {
		++freq[ch];
	}

	int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
		return u.second < v.second;
	})->second;

	int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u) {
		return acc + (u.second == maxExec);
	});

	return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
}

int main() {
	string s;
	cin >> s;

	vector<char> tasks(s.begin(), s.end());

	int n;
	cin >> n;

	int ans = leastInterval(tasks, n);

	cout << ans << endl;

	return 0;
}