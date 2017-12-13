//
//  Vertex.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/12/7.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>

typedef enum {
	UNDISCOVERED,
	DISCOVERED,
	VISITED,
} VStatus;

template <typename Tv>
struct Vertex {
	//数据域, 入度, 出度 (最直观的3个)
	Tv _data;
	int _inDegree, _outDegree;
	
	VStatus _status;	//状态
	int _parent;		//遍历树中的父节点
	int _dTime, _fTime;	//顶点被发现, 以及被访问完毕的时刻
	int _priority;		//再基于优先级的算法中, 在遍历树中的优先级 (最短通路, 极短跨边等)
	
public:
	Vertex( Tv const& e ): _data(e), _inDegree(0), _outDegree(0), _status(UNDISCOVERED), _parent(-1), _dTime(-1), _fTime(-1), _priority(__INT_MAX__)
	{
		
	}
	
};

#endif /* Vertex_hpp */
