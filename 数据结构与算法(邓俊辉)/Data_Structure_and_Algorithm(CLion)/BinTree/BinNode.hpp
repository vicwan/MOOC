//
//  BinNode.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by Vic Wan on 2017/12/3.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef BinNode_hpp
#define BinNode_hpp

#include <stdio.h>

#define BinNodePosi(T) BinNode<T>*

template <typename T>
struct BinNode {
    BinNodePosi(T) _parent;
    BinNodePosi(T) _lChild;
    BinNodePosi(T) _rChild;
    T _data;
    int _height;
    
public:
    BinNode()
    {
        _parent = nullptr;
        _lChild = nullptr;
        _rChild = nullptr;
    }
    
    BinNode( T e,
            BinNodePosi(T) parent = nullptr,
            BinNodePosi(T) lChild = nullptr,
            BinNodePosi(T) rChild = nullptr,
			int height = 0
			) : _data(e), _parent(parent), _lChild(lChild), _rChild(rChild), _height(height)
    {
//        _data = e;
//        _parent = parent;
//        _lChild = lChild;
//        _rChild = rChild;
//        _height = height;
    }
    // 为当前节点添加一个数据域为 e 的左孩子
    BinNodePosi(T) insertAsLC( T const& e )
    {
        return _lChild = new BinNode( e, this );
    }
    // 为当前节点添加一个数据域为 e 的右孩子
    BinNodePosi(T) insertAsRC( T const& e )
    {
        return _rChild = new BinNode( e, this );
    }
    
    int size()
    {
        int s = 1;
        if (_lChild) s += _lChild->size();
        if (_rChild) s += _rChild->size();
        return s;
    }
	
	// 获取中序遍历情况下的后继
	BinNodePosi(T) succ()
	{
        BinNodePosi(T) node = this;
		if( _rChild ) {
			node = _rChild;
//			while(_rChild->_lChild) {
//				node = _rChild->_lChild;
//			}
			while( node->_lChild ) {
				node = _rChild->_lChild;
			}
		}else {
			while( node->_parent->_rChild == node ) {
				node = node->_parent;
			}
			node = node->_parent;
		}
		return node;
	}
    
};

#endif /* BinNode_hpp */
