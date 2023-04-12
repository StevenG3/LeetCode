#include <bits/stdc++.h>

using namespace std;

bool check(unordered_map<char, int>& cache, unordered_map<char, int>& window) {
	for(auto&& [ch, freq] : cache) {
		if(window.count(ch) == 0 || freq > window[ch]) {
			return false;
		}
	}
	return true;
}

string minWindow(string s, string t) {
	unordered_map<char, int> cache;

	for(auto ch : t) cache[ch]++;

	int n = s.size();

	unordered_map<char, int> window;

	int len = n + 1;
	int pos = -1;

	// 核心逻辑：每次将s[i]添加进window中，再收缩边界，直到不满足check(cache, window)
	for(int i = 0, j = 0; i < n; ++i) {
		if(cache.count(s[i])) {
			window[s[i]]++;
			while(j <= i && (cache.count(s[j]) == 0 || check(cache, window))) {
				if(cache.count(s[j])) {
					if(len > i - j + 1) {
						len = i - j + 1;
						pos = j;
					}
					window[s[j]]--;
				}
				j++;
			}
		}
	}

	return pos == -1 ? "" : s.substr(pos, len);
}

int main() {
	string s, t;
	cin >> s;
	cin >> t;

	string ans = minWindow(s, t);

	cout << ans << endl;

	return 0;
}