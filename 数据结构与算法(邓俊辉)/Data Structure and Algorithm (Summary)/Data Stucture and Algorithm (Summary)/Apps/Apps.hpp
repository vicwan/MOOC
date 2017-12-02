//
//  Apps.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/11/30.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef Apps_hpp
#define Apps_hpp

#include <stdio.h>
#include <iostream>
#include "Stack.hpp"

void convert ( int n, int base );   // n 转为 base 进制
bool paren( const char exp[], int lo, int hi ); // 括号匹配判断


template <typename T>
int len( T& A ) {    // 卡住了, 如何求数组的长度?
    int totalSize = sizeof(A);
    int typeSize = sizeof(A[0]);
    int len = totalSize / typeSize;
    return len;
}

/*
 ori[] 的排列为 top - bottom
 fin[] 的排列为 bottom - top
 */
template <typename T>
bool kk( const T ori[], const T fin[] ) {   // 栈混洗序列的判断
    if ( len(ori) != len(fin) ) {
        return false;
    }
    
    Stack<T> A = Stack<T>();
    Stack<T> B = Stack<T>();
    Stack<T> C = Stack<T>();
    
    // 将 ori[] 装进栈 A 中
    int i = len(ori) - 1;
    while ( (ori[i] != '\0') && ( i >= 0 ) ) {
        A.push( ori[i] );
    }
    
    
    int j = 0;
    
    while (1) {
        
        if ( A.empty() && !B.empty() && (B.top() != fin[j]) ) {
            return false;
        }
        
        if ( fin[j] != B.top() ) {
            // 如果 ori[i] 值与 A.top 不相等, 则 A.top pop 出来, 压入 B
            if ( fin[j] == A.top() ) {
                __pop_and_push__(A, C);
            }else {
                __pop_and_push__(A, B);
            }
        }else {
            __pop_and_push__(B, C);
        }
        j++;
        
    }
    return true;
}

template <typename T>
T __pop_and_push__( Stack<T>& popFrom, Stack<T>& pushInto ) {
    T e = popFrom.pop();
    pushInto.push(e);
    return e;
}

#endif /* Apps_hpp */
