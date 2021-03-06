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
	BinTree() : _size(0), _root(nullptr) {}
	
	inline BinNodePosi(T) root() const
	{
		return _root;
	}
	inline BinNodePosi(T) insertAsRoot( T const& e )
	{
		_size = 1;
		return _root = new BinNode<T>(e);
	}
	
    BinNodePosi(T) insertAsLC( BinNodePosi(T) x, T const& e )
    {
        if (!x->_lChild) {
            _size ++;
        }
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
	
#pragma mark - 遍历
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
	// 参数 s 一定要加引用, 不然外部栈的 size 不会改变, 因为操作的栈是该函数内部临时的栈.
    void __visitAlongLeftBranch( Stack<BinNodePosi(T)>& s, BinNodePosi(T) x, VST& visit )
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
			if (s.empty()) {
				break;
			}
            //将控制权移交给栈顶元素, 即将对以该元素为根节点的子树的左侧链进行访问
            x = s.pop();
        }
    }
	
	template <typename VST>
	void __goAlongLeftBranch( Stack<BinNodePosi(T)>& s, BinNodePosi(T) x, VST& visit )
	{
		while (x) {
			s.push(x);
			x = x->_lChild;
		}
	}
	// 中序遍历
	template <typename VST>
	void travIn( BinNodePosi(T) x, VST& visit )
	{
		Stack<BinNodePosi(T)> s = Stack<BinNodePosi(T)>();
		while (true) {
			__goAlongLeftBranch(s, x, visit);
			if (s.empty()) {
				break;
			}
			x = s.top()->_rChild;
			visit(s.pop()->_data);
//			x = s.pop();
//			visit( x->_data );
//			x = x->_rChild;
		}
	}
	
	// 后序遍历, 递归版本
	template <typename VST>
	void travPost_recursion( BinNodePosi(T) x, VST& visit )
	{
		if (x->_lChild) {
			travPost(x->_lChild, visit);
		}
		if (x->_rChild) {
			travPost(x->_rChild, visit);
		}
		visit( x->_data );
	}
	
	template <typename VST>
	void __visitAlongOnLevel( Queue<BinNodePosi(T)>& q, BinNodePosi(T) x, VST& visit )
	{
		
	}
	
	template <typename VST>
	void travLevel( BinNodePosi(T) x, VST& visit )
	{
		Queue<BinNodePosi(T)> q = Queue<BinNodePosi(T)>();
		visit(x->_data);
		while (1) {
			if (x->_lChild) {
				q.enqueue(x->_lChild);
			}
			if (x->_rChild) {
				q.enqueue(x->_rChild);
			}
			if (q.empty()) {
				break;
			}
			x = q.dequeue();
			visit( x->_data );
		}
	}
};

#endif /* BinTree_hpp */
