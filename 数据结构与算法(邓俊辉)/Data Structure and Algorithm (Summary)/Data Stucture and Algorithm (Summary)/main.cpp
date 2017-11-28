//
//  main.cpp
//  Data Stucture and Algorithm (Summary)
//
//  Created by Vic Wan on 2017/11/20.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#include <iostream>
#include "Vector.hpp"
#include "List.hpp"


using namespace std;


#pragma mark - 函数声明
void test_vector();
void test_list();


#pragma mark - Main 函数
int main(int argc, const char * argv[]) {
	
    
    test_vector();
//    test_list();
	
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
	int removed = v.uniquify();
	cout << "考察有序列表的唯一化:" << "移除了:" << removed << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "  ";
	}
	
	cout << "\n考察复制构造函数:" << endl;
	VectorInt v1 = v;
	for (int i = 0; i < v.size(); i++) {
		cout << v1[i] << "  ";
	}
	cout << endl;

	cout << "复制构造函数:" << endl;
	int a[5] = {1, 2, 3, 4, 5};
	VectorInt v2 = Vector<int>(a, 0, 3);
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << "  ";
	}
	cout << endl;
	
	
	
}

#pragma mark - 测试 List
#define DEFAULT_LIST_SIZE 10
typedef List<int> ListInt;
void  test_list()
{
	ListInt list = ListInt();
	for (int i = 0; i < DEFAULT_LIST_SIZE; i++) {
		int e = arc4random_uniform(100);
		list.append(e);
	}

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << "  ";
    }
    list.insert(3, 10000);
    cout << endl;
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << "  ";
    }
    cout << endl;
    cout << "是否为空:" << list.empty() << endl;

	int removed = list.deduplicate();
	cout << "测试 deduplicate. " << "删除了: " << removed << "个元素" << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << "  ";
	}
	
}
