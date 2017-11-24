//
//  Vector.cpp
//  Data Stucture and Algorithm (Summary)
//
//  Created by Vic Wan on 2017/11/20.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "Fibonacci/Fib.cpp"
#include "Utility.cpp"


typedef int Rank;
#define DEFAULT_CAPACITY 3



// 规定 lo 和 hi 为左闭右开的区间, 即 [lo, hi)
template <typename T>
class Vector {
    // 当前向量的最大容量 capacity
    int _capacity;
    // 当前向量的规模 size
    Rank _size;
    // 数据区
    T *_elem;
    
    
    
public:
#pragma mark - 构造函数
// 构造函数
    Vector(int capacity = DEFAULT_CAPACITY)
    {
        _capacity = capacity;
        _size = 0;
        _elem = new T[_capacity];
    }
	
#pragma mark - 复制构造函数
// 复制构造函数
    void copyFrom( T const * A, Rank lo, Rank hi)   // 数组区间复制
    {
        // 1. 向量内部开辟足够的空间
        _capacity = 2 * (hi - lo);
        _elem = new T[_capacity];
        _size = 0;
        // 2. 进行复制操作
        while (lo < hi) {
            _elem[_size++] = A[lo++];
        }
    }
    Vector( T const * A, Rank lo, Rank hi )     // 数组区间复制
    {
        copyFrom( A, lo, hi);
    }
    
    void copyFrom( Vector<T> const & V, Rank lo, Rank hi )   // 向量区间复制
    {
        // 1. 向量内部开辟足够的空间
        _capacity = 2 * (hi - lo);
        _elem = new T[_capacity];
        _size = 0;
        // 2. 执行复制操作
        while (lo < hi) {
            _elem[_size++] = V._elem[lo++];
        }
    }
    Vector( Vector<T> const & V, Rank lo, Rank hi )     // 向量区间复制
    {
        copyFrom(V, lo, hi);
    }
    
    void copyFrom( Vector<T> const & V )        // 向量整体复制
    {
        // 1. 向量内部开辟足够空间
        _capacity = 2 * V._capacity;
        _elem = new T[_capacity];
        _size = 0;
        // 2. 进行复制操作
        while (_size <= V._size) {
            _elem[_size] = V._elem[_size];
            _size++;
        }
    }
    Vector( Vector<T> const & V )       // 向量整体复制
    {
        copyFrom(V);
    }

#pragma mark - 析构函数
// 析构函数
    ~Vector()
    {
        delete [] _elem;
    }
	
#pragma mark - 运算符重载
	// [] 运算符重载
	T & operator [] (Rank r) const
	{
		assert(r < _size);
		return _elem[r];
	}
    
	// = 运算符重载
	
#pragma mark - 扩容, 缩容
// 扩容操作
    void expand()
    {
        if (_size < _capacity) return;
        
        T *newElem = new T[_capacity << 1];
        for (int i = 0; i < _size; i++) {
            newElem[i] = _elem[i];
        }
        delete [] _elem;
        _elem = newElem;
    }
// 缩容操作
    void shrink()
    {
        // 不能收缩至默认容量下
        if (_capacity < DEFAULT_CAPACITY) {
            return;
        }
        if (_size << 2 > _capacity) {
            return;
        }
        _capacity = _capacity >> 1;
        T *newElem = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            newElem[i] = _elem[i];
        }
        delete [] _elem;
        _elem = newElem;
        
    }
#pragma mark - 数据访问
// 数据访问
	T get( Rank r )
	{
		return _elem[r];
	}
    
// 增删改查
#pragma mark - 增删改查
	

#pragma mark  增
// 增
    // 插入. 将元素 e 作为秩 r 的元素插入
    Rank insert( Rank r, T const& e )
    {
        expand(); // 若有必要, 则扩容
        for (int i = _size; i > r ; i--) {  // 自右向左的顺序, 右移一个单位
            _elem[i] = _elem[i - 1];
        }
        _elem[r] = e;
        _size++;
        return r;
    }
	
#pragma mark  删除相关
// 删
    // 区间删除 (返回被删除元素的数目)
    int removeInterval( Rank lo, Rank hi )
    {
        if (lo == hi) {
            return 0;
        }
        while (hi < _size) {
            _elem[lo++] = _elem[hi++];
        }
        _size = lo;
        shrink();
        return hi - lo;
    }
    
    // 删除向量中, 秩为 r 的元素
    T remove( Rank r )
    {
        T data = _elem[r];
        remove(r, r + 1);
        return data;
    }
    // 无序向量的去重操作, 返回被删除元素的数目
    int deduplicate()
    {
        
    }
	
	// 有序向量的去重操作, 返回被删除元素的数目
	int uniquify()
	{
		int i = 1, j = 0;	// i 为当前被考察元素的秩, j 为互异元素最后一个的秩
		while (i < _size) {
			if (_elem[j] != _elem[i]) {
				_elem[++j] = _elem[i];
			}
			i++;
		}
		_size = ++j;		//  这里需要 ++j, 因为 i 为最后一个元素的秩 +1.
		shrink();
		return i - j;
	}

#pragma mark  查找
// 查
    // 无序向量的查找 find
    Rank find( T const& e, Rank lo, Rank hi )
    {
        while ((lo < hi--) && (_elem[hi] != e)) // 很巧妙, 正常思路会写出两个 return hi; 没有这样精简
        return hi;
    }
    
    // 遍历
    template <typename VST>
    void traverse( VST& visit )
    {
        for (int i = 0; i < _size; i++) {
			visit(_elem[i]);
        }
    }
	void traverse1( T (*visit)(T&) )
	{
		for (int i = 0; i < _size; i++) {
			visit(_elem[i]);
		}
	}
	
	// 二分查找
	
	/*
	 此版本可以在 mi 命中时立即返回秩, 但每次循环要多一次比较过程.
	 有多个命中元素时，不能保证返回秩最大者；查找失败时，简单地返回-1，而不能指示失败的位置
	 */
	static Rank search_binary_A( T* A, T const& e, Rank lo, Rank hi )
	{
		Rank mi;
		while ( lo < hi ) {
			mi = (lo + hi) >> 1;
			if( e < A[mi] ) {
				hi = mi;
			}else if( e > A[mi] ){
				lo = mi + 1;
			}else {
				return mi;
			}
		}
		return -1;
	}
	
	// 用以优化版本 A 的比较次数. 由于向右转向的成本更高, 需要两次比较.
	static Rank search_fibonaccian( T* A, T const& e, Rank lo, Rank hi )
	{
		Rank mi;
		Fib fib = Fib( hi - lo );
		
		while ( lo < hi ) {
			while ( (hi - lo) < fib.get() ) {
				fib.prev();
			}
			mi = lo + fib.get() - 1;
			if( e < A[mi] ) {
				hi = mi;
			}else if( e > A[mi] ){
				lo = mi + 1;
			}else {
				return mi;
			}
		}
		return -1;
	}
	
	/*
	 此版本较版本 A 少一次比较过程, 但最好情况比版本 A 差很多. 因为必须等到减而治之缩小到 1 个元素的时候, 才能得到结果
	 有多个命中元素时，不能保证返回秩最大者；查找失败时，简单地返回-1，而不能指示失败的位置
	 */
	static Rank search_binary_B( T* A, T const& e, Rank lo, Rank hi )
	{
		Rank mi;
		while ( hi - lo > 1 ) {
			mi = (lo + hi) >> 1;
			if ( e < A[mi] ) {
				hi = mi;
			}else {
				lo = mi;
			}
		}
		if ( A[lo] == e ) {
			return lo;
		}else {
			return -1;
		}
	}
	/*
	 这个版本可以完全符合预期的语义. 即有多个元素命中时, 返回秩最大者; 查找失败时, 返回小于 e 的最大元素位置
	 符合语义很难, 反正我没想出来... 很巧妙的算法, 仔细体会!
	 */
	static Rank search_binary_C( T* A, T const& e, Rank lo, Rank hi )
	{
		Rank mi;
		while ( lo < hi) {
			mi = (lo + hi) >> 1;
			if ( e < A[mi] ) {
				hi = mi;
			}else {
				lo = mi + 1;
			}
		}
		return (lo - 1);
	}
	
#pragma mark  排序
// 排序
	
	void swap( T& a, T& b ) {
		&a = &a ^ &b;
		&b = &a ^ &b;
		&a = &a ^ &b;
	}
	
	// 检查逆序对数量
	int disordered() const
	{
		int count = 0;
		for (int i = 1; i < _size; i++) {
			if (_elem[i - 1] > _elem[i]) {
				count++;
			}
		}
		return count;
	}
	
	// 起泡排序龟速版 -- 最简单粗暴的方式, 没有对扫描区域做任何地扫描优化,
	void bubble_scan_slow( Rank lo, Rank hi )
	{
		while (lo < hi - 1) {
			if (_elem[lo] > _elem[lo + 1]) {
				swap(_elem[lo], _elem[lo + 1]);
			}
			lo++;
		}
	}
	
	void sort_bubble_slow( Rank lo, Rank hi )
	{
		while (lo < hi) {
			bubble_scan_slow(lo, hi);
			hi--;
		}
	}
	
	
	// 起泡排序
	// 单次对未排序区间的扫描, 返回这个区间是否已经排序的布尔值
	bool bubble_scan( Rank lo, Rank hi )
	{
		bool isSorted = true;
		while (lo < hi - 1) {
			if (_elem[lo] > _elem[lo + 1]) {
				/*
				 只要出现一次交换, 即可判定----此次 scan 的未排序区间在 scan 结束后依然有未完全排序的可能
				 所以将排序标志返回 false 出去, 请求调用者继续对未排序区间进行扫描排序
				 */
				isSorted = false;
				swap(_elem[lo], _elem[lo + 1]);
			}
		}
		return isSorted;
	}
	
	/*
	 如果返回排序结果为 false, 那么 hi 继续左移, 进行下一轮的起泡交换.
	 如果返回排序结果为 true, 那么说明该向量的未排序区域已经处于排好序的状态, 可以退出循环, 算法终止.
	 */
	void sort_bubble( Rank lo, Rank hi )
	{
		while (!bubble_scan(lo, hi)) {
			hi--;
		}
	}
	
	// 起泡排序快速版 (比👆版本更早结束对已排序区段元素的扫描)
	bool bubble_scan_fast( Rank lo, Rank hi )
	{
		Rank last = lo;
		while (lo < hi - 1) {
			if (_elem[lo] > _elem[lo + 1]) {
				swap(_elem[lo], _elem[lo + 1]);
				last = lo + 1;
			}
		}
		return last;
	}
	
	bool sort_bubble_fast( Rank lo, Rank hi )
	{
		while (lo < hi) {
			hi = bubble_scan_fast(lo, hi);
		}
	}
	
	// 归并排序
	void sort_merge( Rank lo, Rank hi )
    {
        
    }
	
};

