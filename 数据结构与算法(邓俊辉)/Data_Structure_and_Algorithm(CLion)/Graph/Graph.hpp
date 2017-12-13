//
//  Graph.hpp
//  Data Structure and Algorithm (Summary)
//
//  Created by 万伟琦 on 2017/12/6.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include "Vertex.hpp"
#include "Edge.hpp"

template <typename Tv, typename Te>
class Graph {
protected:

	
public:	// 顶点操作, 边操作, 图算法
#pragma mark - 顶点相关
    int _n;                                 //顶点总数
    virtual Tv& vertex( int ) = 0;          //顶点数据
    virtual int insert( Tv const& v ) = 0;  //插入节点, 返回编号
    virtual int inDegree( int ) = 0;        //入度
    virtual int outDegree( int ) = 0;       //出度
    virtual VStatus& status_v( int ) = 0;   //顶点状态
    virtual int& dTime( int ) = 0;          //发现时间
    virtual int& fTime( int ) = 0;          //结束时间
    virtual int& parent( int ) = 0;         //遍历书中的父亲
    virtual int& priority( int ) = 0;       //顶点优先级

    virtual int firstNbr( int ) = 0;        //顶点 v 的首个邻接节点
    virtual int nextNbr( int, int ) = 0;    //顶点 v 相对于顶点 j 的下一邻接节点
    
#pragma mark - 边相关
    int _e;                                 //边总数
    virtual bool exists( int, int ) = 0;    //判断两个顶点是否邻接
    virtual Te& edge( int, int ) = 0;       //边数据
    virtual int& weight( int ) = 0;         //权重
    virtual EStatus& status_e( int, int ) = 0;    //边的状态
    virtual Te remove( int, int ) = 0;      //删除两个顶点之间的边, 并返回该边的信息
    virtual void insert( Te const& e, int w, int i, int j ) = 0; //在顶点 i,j 之间插入权重为 w 的边
    
};

#endif /* Graph_hpp */
