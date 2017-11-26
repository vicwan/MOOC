//
//  ListNode.cpp
//  Data Structure and Algorithm (Summary)
//
//  Created by Vic Wan on 2017/11/27.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#include <stdio.h>


#define ListNodePosi(T) ListNode<T>*

typedef int Rank;

template <typename T>
struct ListNode {       // 双向列表
    
    // 成员变量
    T _data;          // 数据域
    ListNodePosi(T) _pred;    // Predecessor
    ListNodePosi(T) _succ;    // Successor
    
    //
    ListNode()
    {
        
    }
    
    // 默认构造器
    ListNode( T data, ListNodePosi(T) pred = NULL, ListNodePosi(T) succ = NULL) : _data(data), _pred(pred), _succ(succ)  {}
    
    // 紧随当前节点之前插入节点
    ListNodePosi(T) insertAsPred( T const& e )
    {
        ListNodePosi(T) node = new ListNode(e);
        node->_pred = _pred;
        node->_succ = this;
        _pred = node;
    
        return node;
    }
    // 紧随当前节点之后插入节点
    ListNodePosi(T) insertAsSucc( T const& e )
    {
        ListNodePosi(T) node = new ListNode(e);
        node->_succ = _succ;
        node->_pred = this;
        _succ = node;
        
        return node;
    }
};
