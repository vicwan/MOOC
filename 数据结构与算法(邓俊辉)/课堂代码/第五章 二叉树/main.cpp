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

#pragma mark - 先序遍历
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
		
	/**
		while (x) {
			visit( x->data );		// 访问当前节点
			S.push( x->rChild );	// 右孩子 ( 右子树 ) 入栈 ( 将来逆序入栈 )
			x = x->lChild;			// 沿左侧链下行
		}
	*/
		if ( S.empty() ) break;
		x = S.pop();
	}
}

#pragma mark - 中序遍历
static void goAlongLeftBranch(
								 BinNodePosi(T) x,
								 Stack<BinNodePosi(T)> & S) {
	// 反复地入栈, 沿左分支深入
	while (x) {
		S.push(x);
		x = x->lChild;
	}
}

// 主算法
template <typename T, typename VST>
void travIn_I1( BinNodePosi(T) x, VST & visit ) {
	Stack <BinNodePosi(T)> S;
	while (true) {
		goAlongLeftBranch( x, S );	// 从当前节点出发, 逐批入栈
	/**
		while (x) {
			S.push(x);
			x = x->lChild;
		}
	 */
		if ( S.empty() ) break;		// 直至所有节点处理完毕
		x = S.pop();				// x 的左子树或为空, 或已遍历 ( 等效于空 ), 故可以
		visit( x->data );			// 立即访问之
		x = x->rChild;				// 再转向其右子树 ( 可能为空, 留意处理手法 )
	}
}


int main(int argc, const char * argv[]) {
	
	
	
	return 0;
}
