//
//  List.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/11/27.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <assert.h>
#include "ListNode.hpp"

typedef int Rank;

template <typename T>

/*
 双向列表
 */
class List {
	int _size;
	ListNodePosi(T) _header;
	ListNodePosi(T)	_trailer;
	
	
#pragma mark - 私有方法
	ListNodePosi(T) first()	// 取首元素
	{
		assert(_size > 0);
		return _header->_succ;
	}
	
	ListNodePosi(T) last()	// 取末尾元素
	{
		assert(_size > 0);
		return _trailer->_pred;
	}
	
	ListNodePosi(T) getNode( Rank r )	// 获取秩 r 对应的节点
	{
		assert( 0 <= r < _size );
		ListNodePosi(T) p = nullptr;
		
		if ( r < (_size >> 1) ) {
			p = first();
			while (0 < r) {
				p = p->_succ;
				r--;
			}
		}else {
			p = last();
			while (0 < _size - r - 1) {
				p = p->_pred;
				r++;
			}
		}
		return p;
	}

#pragma mark - 对外接口
public:
	// 构造函数. 构造一个空列表, 仅包含头(header)尾(trailer)元素
	void init()
	{
		_header = new ListNode<T>();
		_trailer = new ListNode<T>();
		
		_header->_pred = nullptr;
		_header->_succ = _trailer;
		
		_trailer->_pred = _header;
		_trailer->_succ = nullptr;
		
		_size = 0;
	}
	
	List()
	{
		init();
	}
	// 析构函数
//	~List();
	
	// 复制构造函数
	void copyNodes( ListNodePosi(T) p, int n )
	{
		init();
		while ( 0 < n-- ) {
			insertAsLast(p->_data);
			p = p->_succ;
		}
	}
	
	
	// 获取规模
	inline Rank size() const { return _size; }
	// 判空
	inline bool empty() const { return _size <= 0; }
	
#pragma mark - 元素访问
	T& firstItem()	// 取首元素的数据 data
	{
		ListNodePosi(T) first = first();
		return first->_data;
	}
	
	T& operator [] (Rank r)
	{
		ListNodePosi(T) node = getNode(r);
		return node->_data;
	}
	
#pragma mark - 增删改查
#pragma mark 增
	Rank insert( Rank r, T const& e )	// 向秩为 r 的位置插入一个元素
	{
		insertBefore(getNode(r), e);
		return r;
	}
	
	void append( T const& e )	// 在列表末尾添加一个元素
	{
		insertAsLast(e);
	}
	// 将元素 e 插入列表, 使之成为节点 p 的前驱
	ListNodePosi(T) insertBefore( ListNodePosi(T) p , T const& e )
	{
		_size++;
		return p->insertAsPred(e);
	}
	// 将元素 e 插入列表, 使之成为节点 p 的后继
	ListNodePosi(T) insertAfter( ListNodePosi(T) p , T const& e )
	{
		_size++;
		return p->insertAsSucc(e);
	}
	// 将元素 e 插入列表, 使之成为列表的首元素
	ListNodePosi(T) insertAsFirst( T const& e )
	{
		ListNodePosi(T) node = new ListNode<T>();
		node->_data = e;
		
		insertAfter(_header, e);
		
		return node;
	}
	// 将元素 e 插入列表, 使之成为列表的末元素
	ListNodePosi(T) insertAsLast( T const& e )
	{
		ListNodePosi(T) node = new ListNode<T>();
		node->_data = e;
        
		insertBefore(_trailer, e);
		
		return node;
	}
    
#pragma mark 删
	T remove( ListNodePosi(T) p )
	{
		T e = p->_data;
		
		p->_pred->_succ = p->_succ;
		p->_succ->_pred = p->_pred;
		
		p = nullptr;
		_size--;
		return e;
	}
	
	// 无序列表的唯一化, 返回被删除元素的个数
	int deduplicate()
	{
		// 如果为平凡列表, return
		if (_size < 2) {
			return 0;
		}
		int oldSize = _size;
		ListNodePosi(T) currNode = _header;
		
		for (int i = 0; i < oldSize; i++) {
			currNode = currNode->_succ;
			T e = currNode->_data;
			ListNodePosi(T) dupNode = find(e, i, currNode);
			if (dupNode) {
				remove(dupNode);
			}
		}
		return oldSize - _size;
	}
	
	// 有序列表的唯一化
	int uniquify()
	{
		if (_size < 2) {
			return 0;
		}
		ListNodePosi(T) p = first();
		ListNodePosi(T) q = p->_succ;
		int oldSize = _size;
		
		while (q != _trailer) {
			if ( p->_data != q->_data ) {
				p = q;
			}else {
				remove(q);
			}
			q = p->_succ;
		}
		return oldSize - _size;
	}
	
#pragma mark 改

	
#pragma mark 查
    ListNodePosi(T) find( T const& e, int n, ListNodePosi(T) p ) const
    {
        while( 0 < n-- ) {
            p = p->_pred;
            if( p->_data == e ) {
                return p;
            }
        }
        return nullptr;
    }
	
	
#pragma mark - 排序
	// 选择排序
	
	
};


#endif /* List_hpp */
