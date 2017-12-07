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
	
	inline int size() const { return _list.size(); }
	inline bool empty() { return _list.size() <= 0; }      //判空
	inline void enqueue( T const& e ) { _list.append(e); } //入列
	inline T dequeue() { return _list.remove( _list.first()); }  //出列
	inline T& front() { return _list.first()->_data; }        //队首元素
	inline T& rear() { return _list.last()->_data; }       //队尾元素
};

#endif /* Queue_hpp */
