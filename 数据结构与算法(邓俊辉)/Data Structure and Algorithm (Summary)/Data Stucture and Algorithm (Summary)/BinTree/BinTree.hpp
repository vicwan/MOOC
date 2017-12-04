//
//  BinTree.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by Vic Wan on 2017/12/4.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef BinTree_hpp
#define BinTree_hpp

#include <stdio.h>
#include <iostream>
#include "BinNode.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

using namespace std;

#define max(a, b)  (((a) > (b)) ? (a) : (b))
#define stature(p) ( (p) ? (p)->_height : -1 )    //将退化为一个节点和 0 个节点的树的高度统一起来

template <typename T>
class BinTree {
    
protected:
    BinNodePosi(T) _root;
    int _size;
    
    /*
     更新节点 x 的高度. 由于树是一个庞大的家族, 其子类对高度更新的函数, 都不尽相同. 所以这里使用虚函数, 以让子类分别实现各自的 updateHeight.
     */
    virtual int updateHeight( BinNodePosi(T) x )
    {
        return x->_height = 1 + max(stature(x->_lChild), stature(x->_rChild));
    }
    
    // 更新节点 x 及其祖先的高度
    void updateHeightAbove( BinNodePosi(T) x )
    {
        while (x) {
            updateHeight(x);
            x = x->_parent;
        }
    }
    
public:
    BinNodePosi(T) insertAsLC( BinNodePosi(T) x, T const& e )
    {
        if (!x->_lChild) {
            _size ++;
        }
        _size ++;
        x->insertAsLC(e);
        updateHeightAbove(x);
        return x->_lChild;
    }
    
    BinNodePosi(T) insertAsRC( BinNodePosi(T) x, T const& e )
    {
        if (!x->_rChild) {
            _size ++;
        }
        x->insertAsRC(e);
        updateHeightAbove(x);
        return x->_rChild;
    }
    
    // 先序遍历
    template <typename VST>
    void travPre_V1( BinNodePosi(T) x, VST& visit )
    {
        Stack<BinNodePosi(T)> s = Stack<BinNodePosi(T)>();
        
        if (x) {
            s.push(x);
        }
        while (!s.empty()) {
            x = s.pop();
            visit( x->_data );
            if (x->_rChild) {
                s.push(x->_rChild);
            }
            if (x->_lChild) {
                s.push(x->_lChild);
            }
        }
    }
    
    // 职责包括: 访问左侧链的同时, 将左侧链相关的右子树的根节点入栈
    template <typename VST>
    void __visitAlongLeftBranch( Stack<BinNodePosi(T)> s, BinNodePosi(T) x, VST& visit )
    {
        while (x) {
            s.push(x->_rChild);
            visit( x->_data );
            x = x->_lChild;
        }
    }
    
    // 职责包括: 将控制权交给合适的右子树根节点.
    template <typename VST>
    void travPre_V2( BinNodePosi(T) x, VST& visit )
    {
        Stack<BinNodePosi(T)> s = Stack<BinNodePosi(T)>();
        
        while (true) {
            //访问左侧链的同时, 将左侧链相关的右子树的根节点入栈
            __visitAlongLeftBranch(s, x, visit);
            //及时判空
            if (s.empty())  break;
            //将控制权移交给栈顶元素, 即将对以该元素为根节点的子树的左侧链进行访问
            x = s.pop();
        }
    }
};

#endif /* BinTree_hpp */
