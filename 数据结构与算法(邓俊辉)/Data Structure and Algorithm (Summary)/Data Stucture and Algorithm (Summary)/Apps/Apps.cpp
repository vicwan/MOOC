//
//  Apps.cpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/11/30.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#include "Apps.hpp"
#include "Stack.hpp"
#include <string>

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

#pragma mark - 括号匹配

bool __pair_paren__( const char a, const char b )	// 如果括号成对, 则返回 true
{
	if ( (a == '(') && (b == ')') ) return true;
	if ( (a == '[') && (b == ']') ) return true;
	if ( (a == '{') && (b == '}') ) return true;
	
	return false;
}

bool __is_left__( const char c )	// 如果是左括号, 返回 true
{
	if ( c == '(' ) return true;
	if ( c == '[' ) return true;
	if ( c == '{' ) return true;
	
	return false;
}

bool __can_pop__( Stack<char> s, const char a, const char b )	// 是否可以 pop
{
	if ( s.empty() ) {
		cout << "有未匹配的右括号" << endl;
		return false;
	}
	if ( !__pair_paren__(a, b) ) {
		printf("不能匹配的括号对: %c : %c\n", a, b);
		return false;
	}
	return true;
}

// 返回 1 则匹配.
bool paren( const char exp[], int lo, int hi )
{
    Stack<char> s = Stack<char>();
//    for (int i = 0; i < hi - lo ; i++) {
//        if (exp[i] == '(') {
//            s.push(exp[i]);
//        }else if ( !s.empty() ) {
//            s.pop();
//        }else {
//            cout << "有无法匹配的右括号" << endl;
//            return false;
//        }
//    }
//    if (s.empty()) {
//        cout << "括号完全匹配" << endl;
//        return true;
//    }else {
//        cout << "有未匹配的左括号" << endl;
//        return false;
//    }
	for (int i = 0; i < hi - lo; i++) {
		
		try {
			if (__is_left__(exp[i])) {
				s.push(exp[i]);
			}else if ( __can_pop__(s, s.top(), exp[i]) ) {
				s.pop();
			}
		} catch (int errCode) {
			if (errCode == kErrCode_listLastRetrieve) {
				// Failed at s.top() when the internal list of stack is empty.
				cout << "有无法匹配的右括号. Error code: " << errCode << endl;
			}else {
				cout << "Unknown_error." << endl;
			}
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


