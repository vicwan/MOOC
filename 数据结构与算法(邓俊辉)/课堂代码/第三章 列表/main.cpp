//
//  main.cpp
//  第三章 列表
//
//  Created by 万伟琦 on 2017/9/23.
//  Copyright © 2017年 万伟琦. All rights reserved.
//

#include <iostream>

using namespace std;

typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode
{
	T data;					//数据域
	ListNodePosi(T) pred;	//前驱	predecessor
	ListNodePosi(T) succ;	//后继	successor
	
	//针对header和trailer的构造
	ListNode(){	}
	
	//默认构造器
	ListNode ( T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL ) : data ( e ), pred ( p ), succ ( s ) {}
	ListNodePosi(T) insertAsPred ( T const& e );	//紧靠当前节点之前插入新节点
	ListNodePosi(T) insertAsSucc ( T const& e );	//紧随当前节点之后插入新节点
};



/*
node - p

 3 node->succ = p
 2 node->pred = p->pred;
 1 p->pred->succ = node;
 4 p->pred = node;

 node->succ = p;
 node->pred = p->pred;
 p->pred = node;
 

*/


int main(int argc, const char * argv[]) {
	// insert code here...
	
	return 0;
}
