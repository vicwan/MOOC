//
//  TreeNode.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/12/4.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

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
			int height = 0 )
	{
		_data = e;
		_parent = parent;
		_lChild = lChild;
		_rChild = rChild;
		_height = height;
	}
	// 为当前节点添加一个数据域为 e 的左孩子
	BinNodePosi(T) insertAsLC( T const& e )
	{
		return _lChild = BinNode( e, this );
	}
	// 为当前节点添加一个数据域为 e 的右孩子
	BinNodePosi(T) insertAsRC( T const& e )
	{
		return _rChild = BinNode( e, this );
	}
	
	int size()
	{
		int s = 1;
		if (_lChild) s += _lChild->size();
		if (_rChild) s += _rChild->size();
		return s;
	}
	
};

#endif /* TreeNode_hpp */
