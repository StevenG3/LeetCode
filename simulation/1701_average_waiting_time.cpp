#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

double averageWaitingTime(vector<vector<int>>& customers) {
	int n = customers.size();
	LL sum = 0;
	// val 表示每一轮的起始时间
	LL val = customers[0][0];

	for(auto&& cus : customers) {
		// 当 起始时间小于每一轮的开始时间时，将 val 赋为 cus[0]
		if(val < cus[0]) val = cus[0];
		// 更新总时间: val + timei - arrivali
		sum += val + cus[1] - cus[0];
		// 更新当前时间: val + timei
		val += cus[1];
	}

	return (double)sum / n;
}

int main() {
	
}