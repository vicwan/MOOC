//
// Created by 万伟琦 on 2017/12/20.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_CLION_BST_H
#define DATA_STRUCTURE_AND_ALGORITHM_CLION_BST_H

#include <stdio.h>
#include "../BinTree/BinTree.hpp"
#include "Entry.h"


/*由 BinTree 派生的 BST 模板类*/
template <typename T>
class BST: public BinTree {
protected:
    BinNodePosi(T) _hot;    /* '命中'节点的父亲 */

    BinNodePosi(T) __searchIn(  )

public:
    BinNodePosi(T) search( T const& e ) {

    }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_CLION_BST_H
