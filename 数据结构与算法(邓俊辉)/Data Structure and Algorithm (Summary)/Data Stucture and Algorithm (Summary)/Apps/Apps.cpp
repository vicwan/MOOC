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


void convert ( int n, int base )
{
	Stack<char> s = Stack<char>();
	
	static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	while (n > 0) {
		s.push( digit[n % base] );
		n /= base;
	}
    int size = s.size();
	for (int i = 0; i < size; i++) {
		cout << s.pop() << "";
	}
	cout << endl;
}

// 返回 1 则匹配.
bool paren( const char exp[], int lo, int hi )
{
    Stack<char> s = Stack<char>();
    for (int i = 0; i < hi - lo ; i++) {
        if (exp[i] == '(') {
            s.push(exp[i]);
        }else if ( !s.empty() ) {
            s.pop();
        }else {
            cout << "有无法匹配的右括号" << endl;
            return false;
        }
    }
    if (s.empty()) {
        cout << "括号完全匹配" << endl;
        return true;
    }else {
        cout << "有未匹配的左括号" << endl;
        return false;
    }
}

