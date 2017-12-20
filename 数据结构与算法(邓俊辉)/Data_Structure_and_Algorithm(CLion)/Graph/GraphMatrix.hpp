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
//#include "../Stack and Queue/Stack.hpp"


template <typename Tv, typename Te>
class GraphMatrix: public Graph<Tv, Te> {

    void reset()
    {
        for (int i = 0; i < _n; i++) {
            status_v(i) = UNDISCOVERED;
            dTime(i) = fTime(i) = -1;
            parent(i) = -1;
            priority(i) = __INTMAX_MAX__;
            for (int j = 0; j < _e; j++) {
                if (exists(i, j)) {
                    status_e(i, j) == UNDETERMINED;
                }
            }
        }
    }

    //顶点集
    Vector< Vertex<Tv> > _V;
    //边集 ( 邻接矩阵 )
    Vector< Vector< Edge<Te>*> > _E;    //_E[i][j] 表示 i->j 的有向边, i 为尾, j 为头.

    int _n, _e; //为何继承不过来?
public:
    GraphMatrix():_n(0), _e(0){};   /*构造函数*/
    /*顶点操作*/

    virtual int& vertex( int i )    /*顶点数据*/
    {
        return _V[i];
    }
    virtual VStatus& status_v( int i )  /*顶点状态*/
    {
        return _V[i]._status;
    }
    virtual int& parent( int i )    /*顶点的父节点*/
    {
        return _V[i]._parent;
    }
    virtual int& dTime( int i )     /*顶点 discover 时间*/
    {
        return _V[i]._dTime;
    }
    virtual int& fTime( int i )     /*顶点结束时间*/
    {
        return _V[i]._fTime;
    }
    virtual int& priority( int i )     /*顶点结束时间*/
    {
        return _V[i]._priority;
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


    virtual int nextNbr( int i, int j )
    {
        while((-1 < j) && !exists(i, --j));
        return j;
    }
    virtual int firstNbr( int v )
    {
        return nextNbr(v, _n);
    }
    virtual EStatus& status_e( int i, int j )
    {
        return status_e(i, j);
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

    /*搜索算法*/
    void bfs_single( int v, int& clock )    /*单个连通域内的搜索*/
    {
        Queue<int> q = Queue<int>();
        status_v(v) = DISCOVERED;
        q.enqueue(v);

        while (!q.empty()) {
            int v = q.dequeue();
            dTime(v) = ++clock;
            for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
                //对扫描到的节点进行处理
                if( status_v(u) == UNDISCOVERED ) {
                    status_v(u) = DISCOVERED;
                    parent(u) = v;
                    q.enqueue(u);
                    status_e(v, u) = TREE;
                }else if( status_v(u) == VISITED ) {
                    status_e(v, u) = CROSS;
                }
                status_v(u) = VISITED;
            }
        }
    }
    void BFS( int s )  /*广度优先搜索, v 是编号*/
    {
        reset();
        int clock = 0;
        int v = s;
        do {
            if( status_v(v) == UNDISCOVERED ) {
                bfs_single(v, clock);
            }
        }while( s != ( v = ( ++v % _n ) ) );
        /* 这个循环条件拆解开之后, 可以看出其所要表达的意思.
         * 无非就是要确定遍历了所有的顶点, 因为 s 极有可能不是第一个顶点
         * 故取余的话可以让 v 的索引在 0-n 的范围之中循环
         * 直到 v 循环一圈之后又与 s 相等, 则循环退出
         * */
    }

    /*首先 push(v), 搜索顶点 v 的一个邻居
     * 然后这个邻居入栈, 搜索该邻居的所有邻居, 然后需要判断这个邻居是否符合要求, 符合即入栈, 不符合就不入栈
     * 并需要更改这些边和顶点的状态*/
    void dfs( int v, Stack<int>& s )
    {
        s.push(v);
        vertex(v) = DISCOVERED;

        while (!s.empty())
        {
            int u = firstNbr(s.top());

        }
    }
    /*入栈操作*/
    void goToTheBottom ( int v, Stack<int> S )
    {
        while(true) {
            v = S.top();
            for (int u = firstNbr(v); -1 < u ; u = nextNbr(v, u)) {
                switch( status_v(u) ) {
                    case UNDISCOVERED:
                        S.push(u);
                        parent(u) = v;
                        status_e(v, u) = TREE;
                        status_v(u) = DISCOVERED;
                        v = u;
                        break;

                    default:
                        return;
                }
            }
        }

    }
    /*在无向图中对应多个连通域的情况
     * 在有向图中则未必, 也有可能是从子树的根节点开始遍历, 而其父亲不在子树的可达区域中
     * 则外面包装的一层循环可以保证能够访问到所有节点
     * 但如此遍历之后, 那个父节点和子树的根节点的边就不是 TREE 边, 而是 CROSS 跨边
     * 这种情况也和两个连通域类似 */
    void DFS( int v )
    {
        Stack<int> S = Stack<int>();
        int s = v;
        do {
            if (status_v(s) != VISITED)
            {
                dfs(s, S);
            }
        }while( s != (v = (v++%_n) ) );

    }
};

#endif /* GraphMatrix_hpp */
