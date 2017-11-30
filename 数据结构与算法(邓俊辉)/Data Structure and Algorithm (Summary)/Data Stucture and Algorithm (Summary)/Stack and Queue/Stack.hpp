//
//  Stack.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/11/30.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include "List.hpp"

template <typename T>
class Stack {
	
	List<T> _list;
	
public:
	
#pragma mark - 构造函数和复制构造函数
	void init() {
		_list = List<T>();
	}
	
	Stack() {
		init();
	}
	
# pragma mark - 元素访问
	T& top() {
		return _list.last()->_data;
	}
	
	bool empty() const
	{
		return _list.size() <= 0;
	}
	
	int size() const
	{
		return _list.size();
	}
	
# pragma mark - 栈操作
	void push( T const& e ) { _list.append(e); }
	
    T pop() {
        ListNodePosi(T) last = _list.last();
        T rm = _list.remove(last);
        return rm;
    }
	
};

#endif /* Stack_hpp */
