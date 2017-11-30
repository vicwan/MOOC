//
//  Queue.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/11/30.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "List.hpp"

template <typename T>
class Queue {
	List<T> _list;
	
public:
	
	void init() { _list = List<T>(); }
	Queue() { init(); }
	
	int size() const { return _list.size(); }
	void enqueue( T const& e ) { _list.append(e); }	//入列
	T dequeue() { return remove( _list.first()); }	//出列
	T& front() { return _list.firstItem(); }		//队首元素
};

#endif /* Queue_hpp */
