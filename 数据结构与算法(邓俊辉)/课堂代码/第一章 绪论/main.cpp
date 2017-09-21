//
//  main.cpp
//  第一章 绪论
//
//  Created by 万伟琦 on 2017/9/15.
//  Copyright © 2017年 万伟琦. All rights reserved.
//

#include <iostream>
#include <time.h>

using namespace std;


// 代码 1.1	冒泡排序
// 基本操作为 2(n - 1)^2 次
void bubblesort1A ( int A[], int n )
{
	bool sorted = false;
	// 需要执行 (n - 1) 轮
	while ( !sorted ) {
		sorted = true;
		// 需要执行 2(n - 1) 次基本操作
		for (int i = 1; i < n; i++) {
			// 至多(n - 1)次判断, 基本操作
			if (A[i - 1] > A[i]) {
				// 至多(n - 1)次交换, 基本操作
				swap( A[i - 1], A[i]);
				sorted = false;
			}
		}
		n--;
	}
}

/* 
 代码 1.2	计算二进制中 1 的数量
 仍有巨大的改进余地
 */
int countOnes ( unsigned int n )
{
	int ones = 0;
	while (0 < n) {
		ones += ( 1 & n );
		n >>= 1;
	}
	return ones;
}

/**
 代码 1.4	计算 2 的 n 次幂	递归版本见代码 1.8
 时间复杂度为 O(n) = O(2^r) (2的 r 次方为 n)
 */
int64_t power2BF_I ( int n )
{
	int64_t pow = 1;
	while ( 0 < n-- )
		pow <<= 1;
	return pow;
}

/**
 代码 1.5	数组求和算法(线性递归版)
 */
int sum ( int A[], int n )
{
	if (n < 1) {
		return 0;
	}else {
		return sum(A, n - 1) + A[n - 1];
	}
}

/**
 代码 1.8	计算 2 的 n 次幂(递归版本)	蛮力迭代见代码 1.4
 时间复杂度为 O(logn) = O(r) (2的 r 次方为 n)
 */
inline int64_t sqr (int64_t a) { return a * a; }
int64_t power2 ( int n )
{
	if (0 == n) {
		return 1;
	}
	if ( n & 1 ) {
		// 奇数
		return sqr ( power2( n >> 1) ) << 1;
	}else {
		// 偶数
		return sqr ( power2( n >> 1) );
	}
}

/**
 代码 1.11	通过二分递归计算数组元素之和
 */
int sumDaQ ( int A[], int lo, int hi )
{
	if (lo == hi) {
		return A[lo];
	}else {
		int mi = ( lo + hi ) >> 1;
		return  sumDaQ ( A, lo, mi ) + sumDaQ ( A, mi + 1, hi );
	}
}



#pragma mark - Main
int main(int argc, const char * argv[]) {


	
	return 0;
}
