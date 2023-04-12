#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
	int n = s.size();
	int used[128] = { 0 };
	int ans = 0, j = 0;
	for(int i = 0; i < n; ++i) {
		while(used[s[i]]) {
			used[s[j]]--;
			j++;
		}
		ans = max(ans, i - j + 1);
		used[s[i]]++;
	}
	return ans;
}

int main() {
	string s;
	cin >> s;

	int ans = lengthOfLongestSubstring(s);

	cout << ans << endl;

	return 0;
}