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
	//边集 ( 邻接矩阵 )
	Vector< Vector< Edge<Te>*> > _E;    //_E[i][j] 表示 i->j 的有向边, i 为尾, j 为头.

    int _n, _e; //为何继承不过来?
public:
    GraphMatrix():_n(0), _e(0){};   /*构造函数*/
    /*顶点操作*/

    virtual int& vertex( int i )
    {
        return _V[i];
    }

    virtual int insert( Tv const& v )  /*顶点插入*/
    {
        //为邻接矩阵横向量 append 顶点
        for (int i = 0; i < _n; ++i) {
            _E[i].append(NULL);
        }
        _n++;
        //为邻接矩阵纵向量 append 一条新顶点对应的向量
        Vector<Edge<Te>*> vectorE = Vector<Edge<Te>*>(_n, _n, NULL);
        _E.append(vectorE);

        //为顶点集添加新顶点, 并返回对应的秩
        Vertex<Tv> vtx = Vertex<Tv>(v);
        return _V.insert(_n, vtx);
    }

    virtual Tv remove( int i )  /*顶点删除, 返回该顶点信息*/
    {
        Tv v = vertex(i);
        /*邻接矩阵中移除*/
        for (int j = 0; j < _n; ++j) {
            if( exists(i,j) ) {
                _V[j]._inDegree--;
                _E[i][j] = nullptr;
                _e--;
            }
        }
        _E.remove(i);
        _n--;
        for (int j = 0; j < _n; ++j) {
            if( exists(j,i) ) {
                _V[j]._outDegree--;
                _E[j][i] = nullptr;
                _E[j].remove(i);
            }
        }
        /*顶点集中移除*/
        _V.remove(i);

        return v;
    }

    /*边操作*/

    virtual bool exists( int i, int j ) const
    {
        return (0<=i<_n) && (0<=j<_e) && _E[i][j] != nullptr;
    }

    virtual void insert( Te const& e, int w, int i, int j ) /*边插入*/
    {
        if (exists(i, j)) {
            return;
        }
        _E[i][j] = new Edge<Te>(e, w);
        _e++;
        _V[i]._outDegree++;
        _V[j]._inDegree++;
    }
    virtual Te& edge( int i, int j )    /*返回边信息*/
    {
        return _E[i][j]->_data;
    }

    virtual Te remove( int i, int j )   /*移除边*/
    {
        Te e = edge(i, j);
        if( exists(i, j) ) {
            _E[i][j] = NULL;
            e--;
            _V[i]._outDegree--;
            _V[j]._inDegree--;
        }
        return e;
    }
};

#endif /* GraphMatrix_hpp */
