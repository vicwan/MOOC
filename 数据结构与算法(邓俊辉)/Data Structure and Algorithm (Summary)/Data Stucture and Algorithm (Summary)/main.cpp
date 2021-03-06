//
//  main.cpp
//  Data Stucture and Algorithm (Summary)
//
//  Created by Vic Wan on 2017/11/20.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#include <iostream>

#include "Apps.hpp"		//应用函数
#include "Traverse.hpp"	//遍历

#include "Vector.hpp"
#include "List.hpp"
#include "Stack.hpp"
#include "BinTree.hpp"
#include "GraphMatrix.hpp"


using namespace std;


Visit<int> visit_int = Visit<int>();	//访问器声明
Visit<char> visit_char = Visit<char>();

#pragma mark - 函数声明
void test_vector();
void test_list();
void test_stack();
void test_binTree();
void test_queue();

#pragma mark - Main 函数
int main(int argc, const char * argv[]) {
	
//    test_vector();
//    test_list();
//	test_stack();
//    convert(8, 2);
    
//    char exp[] = "()([])]";
//    paren(exp, 0, 7);
//    cout << len(exp) << endl;
//    int ori[] = {1,2,3};
//    int fin[] = {3,2,1};
//
//    cout <<  kk(ori, fin) << endl;
	
//	test_queue();
	
	test_binTree();
	
	

	
	
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
void test_list()
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
//    for (int i = 0; i < list.size(); i++) {
//        cout << list[i] << "  ";
//    }
//    cout << endl;
//    cout << "是否为空:" << list.empty() << endl;
//
//	int removed = list.deduplicate();
//	cout << "测试 deduplicate. " << "删除了: " << removed << "个元素" << endl;
//	for (int i = 0; i < list.size(); i++) {
//		cout << list[i] << "  ";
//	}
//	cout << "选择排序:" << endl;		list.sort_selection(list.first(), list.size());
	cout << "插入排序:" << endl;		list.sort_insertion(list.first(), list.size());
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << "  ";
	}
}

#pragma mark - 测试 Stack
typedef Stack<int> StackInt;
void test_stack()
{
	StackInt s = StackInt();
	for (int i = 0; i < DEFAULT_LIST_SIZE; i++) {
		int e = arc4random_uniform(100);
		s.push(e);
	}
	cout << "Pop 前 Size 为:" << s.size() << "  是否为空: " << s.empty() << endl;
	for (int i = 0; i < DEFAULT_LIST_SIZE; i++) {
		cout << s.pop() << "  ";
	}
	cout << endl;
	cout << "Pop 后 Size 为:" << s.size() << "  是否为空: " << s.empty() << endl;
	cout << endl;
}


#pragma mark - 测试 Queue
typedef Queue<int> QueueInt;
void test_queue()
{
	QueueInt q = QueueInt();
	cout << "队列是否为空: " << q.empty() << endl;
	for (int i = 0; i < 5; i++) {
		q.enqueue(i);
	}
	printf("队列是否为空: %d. 队列的规模为: %d \n", q.empty(), q.size());
	printf("头部元素为: %d. 尾部元素为: %d \n", q.front(), q.rear());
	while (q.size()) {
		printf("%d ", q.dequeue());
	}
	cout << endl;
	printf("此时队列是否为空: %d. 队列的规模为: %d \n", q.empty(), q.size());
}


#pragma mark - 测试 BinTree
typedef BinTree<char> BinTreeChar;
BinTreeChar* createBinTree()
{
	/*
              A
            /  \
	       /    \
		  B      C
		 / \    / \
	 	D   E  F   G
       / \  / \
	  H  I J  K
	 
	 */
	
	BinTreeChar* binTree = new BinTreeChar();
	BinNodePosi(char) nodeA = binTree->insertAsRoot('A');
	BinNodePosi(char) nodeB = binTree->insertAsLC(nodeA, 'B');
	BinNodePosi(char) nodeC = binTree->insertAsRC(nodeA, 'C');
	BinNodePosi(char) nodeD = binTree->insertAsLC(nodeB, 'D');
	BinNodePosi(char) nodeE = binTree->insertAsRC(nodeB, 'E');
	BinNodePosi(char) nodeF = binTree->insertAsLC(nodeC, 'F');
	BinNodePosi(char) nodeG = binTree->insertAsRC(nodeC, 'G');
	BinNodePosi(char) nodeH = binTree->insertAsLC(nodeD, 'H');
	BinNodePosi(char) nodeI = binTree->insertAsRC(nodeD, 'I');
	BinNodePosi(char) nodeJ = binTree->insertAsLC(nodeE, 'J');
	BinNodePosi(char) nodeK = binTree->insertAsRC(nodeE, 'K');
	
    visit_char(nodeK->succ()->_data);
    visit_char(nodeJ->succ()->_data);
    
	return binTree;
}

void test_binTree()
{
	BinTreeChar *binTree = createBinTree();
	
//	binTree->travPre_V1(binTree->root(), visit_char);	// A, B, D, H, I, E, J, K, C, F, G
//	binTree->travPre_V2(binTree->root(), visit_char);
//	binTree->travIn(binTree->root(), visit_char);		// H, D, I, B, J, E, K, A, F, C, G
//	binTree->travPost_recursion(binTree->root(), visit_char);
//	binTree->travLevel(binTree->root(), visit_char);
	
	
	
	
	cout << endl;
}
