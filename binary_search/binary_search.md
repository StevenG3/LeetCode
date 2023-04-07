# 二分
## 特性
1. 单调性
2. 存在两段性的性质

将一个区间 [L, R] 分成红绿两色的线段，前一段是红色，而后一段是绿色，需要观察最终的查找点是红色还是绿色
    - 如果最终的查找点是绿色，并且 -> 模板一
		- 中点 M 是绿色，那么区间 [L, R] -> [L, M]
		- 中点 M 是红色，那么区间 [L, R] -> [M + 1, R]
	- 如果最终的查找点是红色，并且 -> 模板二
		- 中点 M 是红色，那么区间 [L, R] -> [M, R]
		- 中点 M 是绿色，那么区间 [L, R] -> [L, M - 1]

## 模板
```C++
// 模板一
int bsearch_1(int L, int R) {
	while (L < R) {
		int M = L + (R - L >> 1);
		if (check(M)) R = M;
		else L = M + 1;
	}
	return L;
}

// 模板二
int bsearch_2(int L, int R) {
	while (L < R) {
		int M = L + (R - L + 1 >> 1);
		if (check(M)) L = M;
		else R = M - 1;
	}
	return L;
}
```

## 步骤
1. 确定二分的区间 [L, R]
2. 确定二分的模板
3. 确定二分的中点 M
4. 确定二分的条件 check(M)
5. 确定二分的更新区间
6. 如果更新方式是 L = M, R = M - 1，那么需要注意在计算 M 时加上 1 

## 例题
https://leetcode.cn/problems/sqrtx/

计算 x 的平方根

```C++
// 题中的 check 函数对应于 M <= x / M，并且最后求出的边界点位于红色部分，选择模板二
class Solution {
public:
	int mySqrt(int x) {
		int L = 0, R = x;
		while(L < R) {
			int M = L + (R - L + 1 >> 1);
			if(M <= x / M) L = M;
			else R = M - 1;
		}
		return L;
	}
};
```

https://leetcode.cn/problems/search-insert-position/
https://leetcode.cn/problems/search-a-2d-matrix/
