// 线性筛求素数
// 1. 从小到大枚举每个数
// 2. 如果这个数是素数，那么就把它的倍数全部标记为合数
// 3. 如果这个数不是素数，那么就跳过
// 4. 重复1-3，直到这个数大于n
// 5. 最后剩下的未被标记的数就是素数
// 6. 时间复杂度O(n)
// 7. 空间复杂度O(n)

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int primes[N], cnt;

bool st[N];

// 线性筛求素数
void get_primes(int n) {
	// 从2开始枚举每个数
	for (int i = 2; i <= n; i++) {
		// 如果这个数是素数，就使用prime数组存储
		if (!st[i]) primes[cnt++] = i;
		// 从小到大枚举每个素数，并一定有primes[j] <= i
		for (int j = 0; primes[j] <= n / i; j++) {
			// 把素数的倍数全部标记为合数
			st[primes[j] * i] = true;
			// 如果i是质数，那么在i == primes[j]时跳出；如果i是合数，那么在i % primes[j] == 0时跳出
			if (i % primes[j] == 0) break;
		}
	}
}

// void get_primes(int n) {
// 	vector<int> primes;
// 	vector<int> is_prime(n + 1, true);
// 	for(int i = 2; i <= n; ++i) {
// 		if(is_prime[i]) primes.emplace_back(i);
// 		for(int j = 0; j < primes.size() && primes[j] <= n / i; ++j) {
// 			is_prime[primes[j] * i] = false;
// 			if(i % primes[j] == 0) break;
// 		}
// 	}
// }

int main() {
	int n;
	cin >> n;
	get_primes(n);
	for (int i = 0; i < cnt; i++) cout << primes[i] << ' ';
	cout << endl;
	return 0;
}
