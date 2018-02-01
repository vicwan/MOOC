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

    /*返回该子树新的根节点*/
    BinNodePosi(T) __connect34( BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
                              BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3 )
    {
        //在设置完毕 a 节点的左右子树后，更新子树 a 的高度
        a->_lChild = T0; if( T0 ) T0->_parent = a;
        a->_rChild = T1; if( T1 ) T1->_parent = a;
        updateHeight(a);

        c->_lChild = T2; if( T2 ) T2->_parent = c;
        c->_rChild = T3; if( T3 ) T3->_parent = c;
        updateHeight(c);

        b->_lChild = a; a->_parent = b;
        b->_rChild = c; c->_parent = b;
        updateHeight(b);

        return b;//返回新的根节点
        //由于该方法仅仅是作用于局部，所以不要更新祖先节点的高度，因为那样已经超出了该函数的'作用域'。
    }

    BinNodePosi(T) __rotateAt( BinNodePosi(T) v )
    {
        BinNodePosi(T) p = v->_parent;
        BinNodePosi(T) g = p->_parent;
        //如果节点 p 为 g 的左孩子, zig
        if( isLChild(p) ) {
            //如果节点 v 为 p 的左孩子 zig-zig
            if( isLChild(v) ) {
                p->_parent = g->_parent;
                return __connect34(v, p, g, v->_lChild, v->_rChild, p->_rChild, g->_rChild);
            } else {    //zig-zag
                v->_parent = g->_parent;
                return __connect34(p, v, g, p->_lChild, v->_lChild, v->_rChild, g->_rChild);
            }
        } else { //zag
            if( isLChild(p) ) { //zag-zig
                v->_parent = g->_parent;
                return __connect34(g, v, p, g->_lChild, v->_lChild, v->_rChild, p->_rChild);
            } else { //zag-zag
                p->_parent = g->_parent;
                return __connect34(g, p, v, g->_lChild, p->_lChild, v->_lChild, v->_rChild);
            }
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
