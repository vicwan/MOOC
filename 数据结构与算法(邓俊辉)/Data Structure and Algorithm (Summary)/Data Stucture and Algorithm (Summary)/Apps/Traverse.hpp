//
//  Traverse.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/12/4.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef Traverse_hpp
#define Traverse_hpp

#include <stdio.h>
#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
struct Visit {
	
	
public:
	//访问元素, 仅仅是打印出来而已. 当然, 也可以在访问时增加其它功能
	void operator() (T const& e)
	{
//		cout << is_same<T, char>::value << "\n";
		cout << e << ", ";
	}
};

#endif /* Traverse_hpp */
