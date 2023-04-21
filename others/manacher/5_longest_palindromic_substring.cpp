#include <iostream>
#include <string> 

using namespace std;

pair<int, int> expand(string& s, int left, int right) {
	int l = left, r = right;
	while(l >= 0 && r < s.size() && s[l] == s[r]) {
		l--;
		r++;
	}

	return {l + 1, r - 1};
}

string longestPalindrome(string s) {
	int start = 0, end = 0;
	for(int i = 0; i < s.size() - 1; ++i) {
		auto p1 = expand(s, i, i);
		auto p2 = expand(s, i, i + 1);

		if(end - start < p1.second - p1.first) {
			start = p1.first;
			end = p1.second;
		}
		
		if(end - start < p2.second - p2.first) {
			start = p2.first;
			end = p2.second;
		}
	}

	return s.substr(start, end - start + 1);
}

int main() {
	string s;
	cin >> s;

	string ans = longestPalindrome(s);

	cout << ans << endl;

	return 0;
}