//
//  Fib.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/11/27.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef Fib_hpp
#define Fib_hpp

#include <stdio.h>

// 参考: https://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/fibonacci/fib.h.htm

class Fib {
	int64_t f, g;	// f = fib(k - 1), g = fib(k)
	
public:
	// 构造函数, 初始化为不小于n的最小Fibonacci项
	Fib( int n )
	{
		f = 1;
		g = 0;
		while ( g < n ) {
			next();
		}
	}
	
	// 获取当前 fib 数
	int64_t get()
	{
		return g;
	}
	
	// 转至前一个 fib 数
	int64_t prev()
	{
		f = g - f;
		g = g - f;
		return g;
	}
	
	// 转至后一个 fib 数
	int64_t next()
	{
		g = g + f;
		f = g - f;
		return g;
	}
};

#endif /* Fib_hpp */
