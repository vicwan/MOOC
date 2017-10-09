//
//  main.cpp
//  第五章 二叉树
//
//  Created by 万伟琦 on 2017/9/27.
//  Copyright © 2017年 万伟琦. All rights reserved.
//

#include <iostream>


#define stature(p) ( (p) ? (p)->height : -1 )

template <typename T, typename VST>
static void visitAlongLeftBranch(
								 BinNodePosi(T) x,
								 VST & visit,
								 Stack<BinNodePosi(T)> & S) {
	while (x) {
		visit( x->data );		// 访问当前节点
		S.push( x->rChild );	// 右孩子 ( 右子树 ) 入栈 ( 将来逆序入栈 )
		x = x->lChild;			// 沿左侧链下行
	}
}

// 主算法
template <typename T, typename VST>
void travPre_I2( BinNodePosi(T) x, VST & visit ) {
	Stack <BinNodePosi(T)> S;
	while (true) {
		visitAlongLeftBranch( x, visit, S );	// 访问子树 x 的左侧链, 右子树入栈缓冲
		if ( S.empty() ) break;
		x = S.pop();
	}
}

int main(int argc, const char * argv[]) {
	
	
	
	return 0;
}
