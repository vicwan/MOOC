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
	
	
#pragma mark - 对外接口
public:
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
	/*
	 在节点 p 的 n 个真前驱中, 查找包含元素 e 的节点
	 */
    ListNodePosi(T) find( T const& e, int n, ListNodePosi(T) p ) const
    {
        while (0 < n--) {
            p = p->_pred;
            if( p->_data == e ) {
                return p;
            }
        }
        return nullptr;
    }
	/*
	 从起始于位置 p 的 n 个元素中选出最大者
	 */
	ListNodePosi(T) selectMax( ListNodePosi(T) p, int n ) const
	{
		if( n < 2 ) {
			return p;
		}
		ListNodePosi(T) max = p;
//		while ( (1 < n) && (p != _trailer) ) {
//			if( max->_data <= p->_data ) {
//				max = p;
//			}
//			p = p->_succ;
//			n--;
//		}
		for ( ListNodePosi(T) cur = p; 1 < n; n-- ) {
			if( ( (cur = cur->_succ) ->_data) >= (max->_data)) {
				max = cur;
			}
		}
		return max;
	}
	
#pragma mark - 排序
	void swap( T& a, T& b ) {
		T c(a); a=b; b=c;
	}
	
	/*
	 选择排序
	 接口语义: 对列表中起始于位置 p 的连续 n 个元素做选择排序
	 */
	void sort_selection( ListNodePosi(T) p, int n )
	{
		if( n < 2 ) {
			return;
		}
		// 设置待排区间 ( head, tail )
		ListNodePosi(T) head = p->_pred;
		ListNodePosi(T) tail = p;
		for (int i = 0; i < n; i++) {
			tail = tail->_succ;
		}
		ListNodePosi(T) max = nullptr;
		while ( 1 < n ) {
			// 遍历乱序区域, 找到最大的
			max = selectMax(p, n);
			// 如果已在有序部分的最前端, 则无需移动
			if (max != tail->_pred) {	// 这里条件在通常情况下, 出现的概率极低, 以至于有时候甚至会得不偿失.
				// 交换 max 和 tail 之前一个节点的数据域. 或者可以直接交换这两个指针的指向
				swap(max->_data, tail->_pred->_data);
			}
			tail = tail->_pred;
			n--;
		}
		// 邓俊辉老师的实现方式
//		while ( 1 < n ) {
//			max = selectMax(head->_succ, n);
//			if (max != tail->_pred) {
//				insertBefore(tail, remove(max));
//			}
//			tail = tail->_pred;
//			n--;
//		}
	}
};


#endif /* List_hpp */
