//
//  GraphMatrix.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/12/7.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef GraphMatrix_hpp
#define GraphMatrix_hpp

#include <stdio.h>
#include "Graph.hpp"
#include "../Vector/Vector.hpp"

template <typename Tv, typename Te>
class GraphMatrix: public Graph<Tv, Te> {
	//顶点集
	Vector< Vertex<Tv> > _V;
	//边集 / 邻接矩阵
	Vector< Vector< Edge<Te>*> > _E;
	
public:
    int _n, _e; //为何继承不过来?
    
    GraphMatrix():_n(0), _e(0){};   //构造函数
    
    virtual bool exists( int i, int j ) const
    {
        return (0<=i<_n) && (0<=j<_e) && _E[i][j] != nullptr;
    }
    //边插入
    virtual void insert( Te const& e, int w, int i, int j )
    {
        if (exists(i, j)) {
            return;
        }
        _E[i][j] = new Edge<Te>(e, w);
        _e++;
        _V[i]._outDegree++;
        _V[j]._inDegree++;
    }
};

#endif /* GraphMatrix_hpp */
