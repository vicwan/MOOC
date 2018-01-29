//
// Created by 万伟琦 on 2017/12/20.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_CLION_BST_H
#define DATA_STRUCTURE_AND_ALGORITHM_CLION_BST_H

#include <stdio.h>
#include "../BinTree/BinTree.hpp"
#include "Entry.h"


/*由 BinTree 派生的 BST 模板类*/
template <typename T>

#define EQUAL(v, e) (!(v) || (v)->_data == (e))

class BST: public BinTree {
protected:
    BinNodePosi(T) _hot;    /* '命中'节点的父亲 */

    BinNodePosi(T) __searchIn_recursive( BinNodePosi(T) &v, const T &e, BinNodePosi(T) &hot ) {
        if( EQUAL(v, e) ) return v;
        hot = v;
        return __searchIn_recursive(v, e, hot);
    }

    BinNodePosi(T) __searchIn_iterative( BinNodePosi(T) &v, const T &e, BinNodePosi(T) &hot ) {
        if( EQUAL(v, e) ) return v;
        hot = v;
        while (true) {
            BinNodePosi(T) c;
            if( e < hot->_data ) {
                c = hot->_lChild;
            } else {
                c = hot->_rChild;
            }
            if( EQUAL(v, c) ) {
                return c;
            }

            hot = c;
        }
    }

public:

    BinNodePosi(T) search( T const& e ) {
        int idx = rand() % 2;
        switch (idx) {
            case 0:
                return __searchIn_recursive(_root, e, _hot = NULL);
            case 1:
                return __searchIn_iterative(_root, e, _hot = NULL);
        }
    }

    BinNodePosi(T) insert( T const& e) {
        BinNodePosi(T) x = search(e);
        // 如果树中存在元素为 e 的节点，则不插入，直接返回该节点
        if( !x ) {
            x = new BinNode(e, _hot);
            _size++;
            updateHeightAbove(x);
        }
        return x;
    }

    bool remove( T const& e ) {
        
    }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_CLION_BST_H
