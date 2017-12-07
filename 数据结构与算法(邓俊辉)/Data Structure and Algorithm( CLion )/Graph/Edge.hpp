//
//  Edge.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/12/7.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>

typedef enum {
	UNDETERMINED,
	TREE,
	CROSS,
	FORWARD,
	BACKWARD,
} EStatus;

template <typename Te>
struct Edge {
	Te _data;
	int _weight;	//权重
	EStatus _status;
	
public:
	Edge( Te const& e, int w ): _data(e), _weight(w), _status(UNDETERMINED)
	{
		
	}
};

#endif /* Edge_hpp */
