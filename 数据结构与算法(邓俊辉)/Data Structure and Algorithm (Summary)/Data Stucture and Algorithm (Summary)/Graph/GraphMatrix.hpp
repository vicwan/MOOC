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
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Vector.hpp"

template <typename Tv, typename Te>
class GraphMatrix: public Graph<Tv, Te> {
	//顶点集
	Vector< Vertex<Tv> > _V;
	//边集
	Vector< Vector< Edge<Te>*> > _E;
	
public:
	
};

#endif /* GraphMatrix_hpp */
