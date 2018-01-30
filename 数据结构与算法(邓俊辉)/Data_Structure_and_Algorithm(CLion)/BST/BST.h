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

    BinNodePosi(T) __removeAt( BinNodePosi(T) &x, BinNodePosi(T) &hot ) {
        BinNodePosi(T) w = x;
        BinNodePosi(T) succ = nullptr;
        if( !x->_lChild ) {
            x = x->_rChild;
            succ = x;
        } else if( !x->_rChild ) {
            x = x->_lChild;
            succ = x;
        } else {
            w = w->succ();
            swap(x->_data, w->_data);
            BinNodePosi(T) u = w->_parent;
            // 隔离被删除节点，设置父节点的孩子，完成单向连接
            succ = w->_rChild;
            if( u == x ) {
                u->_rChild = succ;
            } else {
                u->_lChild = succ;
            }
        }
        // 记录 hot 节点
        hot = w->_parent;
        // 若删除节点是叶子节点，那么 succ 为 nullptr，自然也不需要设置其父亲
        if( succ ) {
        // 设置顶替的右子树根节点的父亲，至此完成双相连接
            succ->_parent = hot;
        }
        // 释放被删除节点，此处未做
        return succ;
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
        // 如果节点不存在，直接 return
        BinNodePosi(T) x = search(e);
        if( !x ) return false;
        // 实施删除
        __removeAt(x, _hot);
        // 更新规模，父节点高度
        _size--;
        updateHeightAbove(_hot);
        return true;
    }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_CLION_BST_H
