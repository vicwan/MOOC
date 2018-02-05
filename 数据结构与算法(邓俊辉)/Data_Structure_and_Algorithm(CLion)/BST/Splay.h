//
// Created by 万伟琦 on 2018/2/5.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_CLION_SPLAY_H
#define DATA_STRUCTURE_AND_ALGORITHM_CLION_SPLAY_H


#include "BST.h"

template <typename T>
class Splay : public BST<T> {

protected:
    BinNodePosi(T) splay( BinNodePosi(T) v ) {

    }

public:
    /*由于查找操作需要改变树的结构，故 search 接口需要重写*/
    BinNodePosi(T) & search( const T& e ) {

    }

    BinNodePosi(T) insert( const T& e ) {

    }

    bool remove( const T& e ) {

    }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_CLION_SPLAY_H
