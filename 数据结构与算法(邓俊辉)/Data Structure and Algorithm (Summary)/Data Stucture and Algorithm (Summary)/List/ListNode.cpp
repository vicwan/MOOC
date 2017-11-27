//
//  ListNode.cpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/11/27.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#include "ListNode.hpp"


template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred( T const& e ) {
	ListNodePosi(T) node = new ListNode<T>(e);
	node->_pred = _pred;
	node->_succ = this;
	_pred = node;
	
	return node;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc( T const& e ) {
	ListNodePosi(T) node = new ListNode(e);
	node->_succ = _succ;
	node->_pred = this;
	_succ = node;
	
	return node;
}
