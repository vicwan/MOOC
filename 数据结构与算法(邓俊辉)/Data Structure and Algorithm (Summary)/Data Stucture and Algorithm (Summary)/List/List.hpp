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
#include "ListNode.hpp"

template <typename T>
class List {
	int _size;
	ListNodePosi(T) _header;
	ListNodePosi(T)	_trailer;
	
public:
	List();		// 构造函数
	~List();	// 析构函数
};


#endif /* List_hpp */
