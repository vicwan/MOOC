//
//  Vector.cpp
//  Data Stucture and Algorithm (Summary)
//
//  Created by Vic Wan on 2017/11/20.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#include <stdio.h>
#include <assert.h>

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T>
class Vector {
    // 当前向量的最大容量 capacity
    int _capacity;
    // 当前向量的规模 size
    Rank _size;
    // 数据区
    T *_elem;
    
    
    
public:
// 构造函数
    Vector(int capacity = DEFAULT_CAPACITY)
    {
        _capacity = capacity;
        _size = 0;
        _elem = new T[_capacity];
    }
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
    
// 析构函数
    ~Vector()
    {
        delete [] _elem;
    }
    
// [] 运算符重载
	T & operator [] (Rank r) const
	{
		assert(r < _size);
		return _elem[r];
	}
    
// = 运算符重载
    
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
// 数据访问
	T get( Rank r )
	{
		return _elem[r];
	}
    
// 增删改查
 
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
            
        }
    }

};

