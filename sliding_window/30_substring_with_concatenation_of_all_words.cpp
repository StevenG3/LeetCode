#include <bits/stdc++.h>

using namespace std;

// 方法一：每次向前移动一个字符，以单词为粒度
// 时间复杂度：O(m * s.size())
// 空间复杂度：O(m)
// vector<int> findSubstring(string s, vector<string>& words) {
// 	vector<int> ans;
// 	int wordNum = words.size();
// 	int wordLen = words[0].size();

// 	if(wordNum == 0) 
// 		return ans;

// 	unordered_map<string, int> allWords;
// 	for(auto&& word : words) {
// 		allWords[word]++;
// 	}

// 	// 以单词为单位，每次检查单词是否被使用
// 	for(int i = 0; i < s.size() - wordNum * wordLen + 1; ++i) {
// 		// 哈希表的创建在循环内部，每次重新创建
// 		unordered_map<string, int> hasWords;
// 		int num = 0;
// 		while(num < wordNum) {
// 			string word = s.substr(i + num * wordLen, wordLen);
// 			// 判断该单词是否存在在allWords中
// 			if(allWords.count(word)) {
// 				hasWords[word]++;
// 				if(hasWords[word] > allWords[word]) {
// 					break;
// 				}
// 			}
// 			else {
// 				break;
// 			}
// 			num++;
// 		}
// 		if(num == wordNum) {
// 			ans.emplace_back(i);
// 		}
// 	}

// 	return ans;
// }

// 方法二：将起始情况分为3类：从0/1/2开始，然后分别进行滑窗
// 时间复杂度O(m * n) = O(n)
// 空间复杂度O(m)
// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-6/
// 滑动窗口的关键在于：先将符合条件的右端点元素加入窗口，再从左侧剔除
vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> ans;
	int wordNum = words.size();
	if(wordNum == 0) return ans;

	int wordLen = words[0].size();

	// 统计单词及出现的次数
	unordered_map<string, int> allWords;
	for(auto&& word : words) {
		allWords[word]++;
	}

	for(int i = 0; i < wordLen; ++i) {
		unordered_map<string, int> hasWords;
		int num = 0;
		// 从 i 开始滑窗
		int j = i, k = i;
		while(k + wordLen <= s.size()) {
			// 先将字符串截取出来
			string word = s.substr(k, wordLen);
			// 后续过程中无需使用k，在此处对k进行加操作
			k += wordLen;
			// 判断单词存在
			if(allWords.count(word)) {
				hasWords[word]++;
				num++;
				// 情况一：当字串完全匹配，移动到下一个子串的时候
				// 关键在于此处的判断：无需检查每个字符串的个数是否匹配，仅需要检查最后一个字符串及当前加入hasWords的单词个数
				if(hasWords[word] == allWords[word] && num == wordNum) {
					ans.emplace_back(j);
					string remove = s.substr(j, wordLen);
					hasWords[remove]--;
					num--;
					j += wordLen;
				}
				// 进入该分支的条件有两个：1.次数超了；2.长度还没有达到
				else {
					// 情况三：判断过程中，出现的是符合的单词，但是次数超了
					while(hasWords[word] > allWords[word]) {
						string remove = s.substr(j, wordLen);
						hasWords[remove]--;
						num--;
						j += wordLen;
					}
				}
			}
			// 情况二：当判断过程中出现不符合的单词
			else {
				j = k;
				hasWords.clear();
				num = 0;
			}
		}
	}

	return ans;
}

int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string> words(n);
	for(int i = 0; i < n; ++i) {
		cin >> words[i];
	}

	auto&& ans = findSubstring(s, words);

	for(auto x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}