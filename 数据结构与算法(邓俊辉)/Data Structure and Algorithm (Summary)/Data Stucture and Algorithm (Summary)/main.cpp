//
//  main.cpp
//  Data Stucture and Algorithm (Summary)
//
//  Created by Vic Wan on 2017/11/20.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#include <iostream>
#include "Vector.hpp"


using namespace std;


#pragma mark - 函数声明
void test_vector();



#pragma mark - Main 函数
int main(int argc, const char * argv[]) {
	
    
    test_vector();
	
    return 0;
}

#pragma mark - 测试 Vector
typedef Vector<int> VectorInt;
void test_vector()
{
	VectorInt v = VectorInt();
	
    for (int i = 0; i < 10; i++) {
        int e = arc4random_uniform(100);
        v.append(e+1);
    }
    
    v.get(2);
    
    cout << "--------检查排序算法-------" << endl;
    cout << "初始向量为: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "  ";
    }
    cout << endl;
//    v.sort_bubble(0, v.size());
//    v.sort_bubble_slow(0, v.size());
//    v.sort_bubble_fast(0, v.size());
    v.sort_merge(0, v.size());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "  ";
    }
    cout << endl;
    
}

#pragma mark - 测试 List
void  test_List()
{
	
}
