//
//  ListNode.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/11/27.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp
#include <stdio.h>

#define ListNodePosi(T) ListNode<T>*

typedef int Rank;

template <typename T>
struct ListNode {			// 双向列表
	
	// 成员变量
	T _data;				// 数据域
	ListNodePosi(T) _pred;	// Predecessor
	ListNodePosi(T) _succ;	// Successor
	
#pragma mark - 对外接口
	
public:
	// 构建 header 和 trailer
	ListNode() {}
	
	// 默认构造器
	ListNode( T data, ListNodePosi(T) pred = NULL, ListNodePosi(T) succ = NULL) : _data(data), _pred(pred), _succ(succ)  {}
	
	
	ListNodePosi(T) insertAsPred( T const& e );	// 紧随当前节点之前插入节点
	ListNodePosi(T) insertAsSucc( T const& e );	// 紧随当前节点之后插入节点
};


#endif /* ListNode_hpp */
