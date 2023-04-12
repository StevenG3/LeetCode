#include <bits/stdc++.h>

using namespace std;

// int findHighestOne(int n) {
//     int pos = 0;
//     while (n != 0) {
//         n >>= 1; // 右移一位
//         pos++; // 记录位数
//     }
//     return pos;
// }

int findHighestOne(int n) {
    return log2(n) + 1; // 使用log2函数求二进制中最高位的1所在的位置
}

int main() {
	int n; 
	cin >> n;

	int ans = findHighestOne(n);

	cout << ans << endl;

	return 0;
}