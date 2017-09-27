//
//  listNode.h
//  数据结构与算法
//
//  Created by 万伟琦 on 2017/9/25.
//  Copyright © 2017年 万伟琦. All rights reserved.
//

#ifndef listNode_h
#define listNode_h

typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode
{
	T data;
	ListNodePosi(T) pred;	//前驱
	ListNodePosi(T) succ;	//后继
	
	ListNode(){}
	ListNode ( T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL ) : data ( e ), pred ( p ), succ ( s ) {}
	ListNodePosi(T) insertAsPred ( T const& e );
	ListNodePosi(T) insertAsSucc ( T const& e );
};



#endif /* listNode_h */
