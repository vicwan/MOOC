//
//  Apps.cpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/11/30.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#include "Apps.hpp"
#include "Stack.hpp"

using namespace std;


void convert (int n, int base )
{
	Stack<char> s = Stack<char>();
	
	static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	while (n > 0) {
		s.push( digit[n % base] );
		n /= base;
	}
	
	for (int i = 0; i < s.size(); i++) {
		cout << s.pop() << "  ";
	}
	cout << endl;
}
