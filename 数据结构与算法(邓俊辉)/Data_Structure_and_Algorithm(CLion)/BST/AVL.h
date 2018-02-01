//
// Created by 万伟琦 on 2018/1/31.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_CLION_AVL_H
#define DATA_STRUCTURE_AND_ALGORITHM_CLION_AVL_H

#include "BST.h"

#define Balanced(x) \
        ( stature((x)->_lChild) == stature((x)->_rChild) )
#define BalFac(x) \
        ( stature((x)->_lChild) - stature((x)->_rChild) )
#define AvlBalanced(x) \
        ( -2 < BalFac(x) ) && ( BalFac(x) < 2 )

template <typename T>
class AVL: public BST<T> {


public:
    // AVL 类需要重写的函数，仅仅是动态操作。而 search 接口可以直接沿用

    BinNodePosi(T) insert( const T& e ) {
        BinNodePosi(T) x = search(e);
        // 如果树中存在元素为 e 的节点，则不插入，直接返回该节点
        if( x ) return x;

        BinNodePosi(T) xx = x = new BinNode(e, _hot);
        _size++;
        updateHeightAbove(x);

        for (BinNodePosi(T) g = _hot; g; g = g->_parent) {
            if( !AvlBalanced(g) ) {

            } else {
                updateHeight(g);
            }
        }
        return xx;
    }

    bool remove( const T& e ) {

    }

    BinNodePosi(T) tallerChild( BinNodePosi(T) x )
    {
        if( stature(x->_lChild) > stature(x->_rChild) ) {
            return x->_lChild;
        } else {
            if( stature(x->_lChild) < stature(x->_rChild) ) {
                return x->_rChild;
            } else {
                if( isLChild(x) ) {
                    return x->_lChild;
                } else {
                    return x->_rChild;
                }
            }
        }

    }

};

#endif //DATA_STRUCTURE_AND_ALGORITHM_CLION_AVL_H
