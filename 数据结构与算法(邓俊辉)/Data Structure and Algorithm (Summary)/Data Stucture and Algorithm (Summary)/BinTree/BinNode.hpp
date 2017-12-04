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

#define BinNodePosi(T) BinNode<T>

template <typename T>
struct BinNode {
    BinNodePosi(T)          _lChild, _rChild;     //左右孩子节点
    BinNodePosi(T)          _parent;              //父亲节点
    T                       _data;                //数据域
    int                     _height;              //节点高度
    int                     _size;                //子树规模 (包括自身在内, 以及所有后代的总数)
    
    
public:
    BinNodePosi(T) insertAsLC( T const& e )
    {
        BinNodePosi(T) lChild = new BinNode<T>();
        lChild._parent = this;
        lChild._data = e;
        _lChild = lChild;
        return lChild;
    }
    BinNodePosi(T) insertAsRC( T const& e );
};

#endif /* BinNode_hpp */
