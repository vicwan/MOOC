//
//  main.cpp
//  第二章 向量
//
//  Created by 万伟琦 on 2017/9/19.
//  Copyright © 2017年 万伟琦. All rights reserved.
//

#include <iostream>

using namespace std;

/**
	向量 ADT 接口		[lo, hi) 遵循左闭右开
 
 1. size()			报告向量当前的规模 (元素总数)
 2. get(r)			获取秩为 r 的元素
 3. put(r,e)		用 e 替换秩为 r 元素的数值
 4. insert(r,e)		e 作为秩为 r 元素插入, 原后继元素一次后移
 5. remove(r)		删除秩为 r 的元素, 返回该元素中原存放的对象
 6. disordered()	判断所有元素是否已按非降序排列
 7. sort()			调整各元素的位置, 使之按非降序排列
 8. find(e)			查找目标元素 e
 9. search(e)		查找目标元素 e, 返回不大于 e 且秩最大的元素 (有序向量)
 10.deduplicate()	剔除重复元素
 11.uniquify()		剔除重复元素 (有序向量)
 12.traverse()		遍历向量并同意处理所有元素, 处理方法由函数对象指定
 
 */

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <class T>
class Vector {
private:
	Rank _size;		//规模 - 共多少个元素, 逻辑空间大小
	int _capacity;	//容量 - 物理空间大小
	T* _elem;		//数据区
	
	//建立在 [lo, hi), 即左闭右开的情况下
	void __copyFrom (T * const A, Rank lo, Rank hi);
	//扩容操作
	void __expand();
	//重载 [] 符号
	T & operator[] (Rank r);
	
public:
	Vector (int c = DEFAULT_CAPACITY)				//构造函数
	{
		_elem = new T [_capacity = DEFAULT_CAPACITY];
		_size = 0;
	}
	
	Vector (T const * A, Rank lo, Rank hi)			//数组区间复制
	{
		__copyFrom(A, lo, hi);
	}
	
	Vector (Vector<T> const& V, Rank lo, Rank hi)	//向量区间复制
	{
		__copyFrom(V._elem, lo, hi);
	}
	
	Vector (Vector<T> const& V)						//向量整体复制
	{
		__copyFrom(V._elem, 0, _size);
	}
	
	~Vector ()										//析构函数
	{
		delete [] _elem;
	}
	
	void printVector();
	
	Rank size();
	T & get(Rank r);
	void put(T& e, Rank r);
	Rank insert(T& e, Rank r);
	void remove (Rank r);
	Rank max ( Rank lo, Rank hi );
	
	// 排序
	bool bubble ( Rank lo, Rank hi );
	void bubbleSort ( Rank lo, Rank hi );		// 起泡排序
	void selectionSort ( Rank lo , Rank hi );	// 选择排序
	void merge ( Rank lo, Rank mi, Rank hi );
	void mergeSort ( Rank lo, Rank hi );		// 归并排序
};
# pragma mark - Private Functions
template <class T>
void Vector<T>::__copyFrom (T * const A, Rank lo, Rank hi)
{
	// 创建适当的空间
	_elem = new Vector[_capacity = 2* (hi - lo)];
	_size = 0;
	while (lo < hi)
	{
		_elem[lo] = A[lo];
		lo ++;
		_size ++;
	}
}

template <class T>
void Vector<T>::__expand() {
	if (_size < _capacity) return;
	T *oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; i++) {
		_elem[i] = oldElem[i];	// T 为基本类型, 或已重载赋值操作符 '='
	}
	delete [] oldElem;
}

template <class T>
T & Vector<T> :: operator [] (Rank r) {
	return _elem[r];
}

# pragma mark - Public Functions

template <class T>
void Vector<T>::printVector(){
	cout << "\n" << endl;
	for (int i = 0; i < _size; i++) {
		cout << _elem[i] << "\t";
	}
	cout << "\n" << endl;
}

template <class T>
Rank Vector<T>::size() {
	return _size;
}

template <class T>
T & Vector<T>::get(Rank r) {
	return _elem[r];
}

template <class T>
void Vector<T>::put(T &e, Rank r)
{
	_elem[r] = e;
}

template <class T>
Rank Vector<T>::insert(T& e, Rank r)
{
	__expand();
	for (int i = _size; i > r; i--) {
		_elem[i] = _elem[i - 1];
	}
	_elem[r] = e;
	_size ++;
	
	return r;
}

template <class T>
void Vector<T>::remove(Rank r) {
	if (r >= _size) {
		cout << "不能移除越界元素!" << endl;
		return;
	}
	
	for (int i = r + 1; i < _size; i++) {
		_elem[i - 1] = _elem[i];
	}
	_size--;
}

template <typename T>	// 起泡单次扫描
bool Vector<T>::bubble(Rank lo, Rank hi)
{
	bool sorted = true;
	while (++lo < hi) {
		if (_elem[lo - 1] > _elem[lo]) {
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]);
		}
	}
	return sorted;
}

template <typename T>	// 起泡排序算法
void Vector<T>::bubbleSort(Rank lo, Rank hi)
{
	while (!bubble(lo, hi--));
}

template <typename T>
Rank Vector<T>::max(Rank lo, Rank hi) {
	Rank maxRank = hi;
	while ( lo < hi-- ) {
		if (_elem[maxRank] < _elem[hi]) {
			maxRank = hi;
		}
	}
	return maxRank;
}

template <typename T>	// 选择排序算法
void Vector<T>::selectionSort(Rank lo, Rank hi)
{
	while (lo < --hi) {
		Rank maxRank = max( lo, hi);
		if (maxRank != hi) {
			swap(_elem[maxRank], _elem[hi]);
		}
	}
}

template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
	// 分别给出 ABC 向量
	T* A = _elem + lo;
	int lb = mi - lo; T* B = new T[mi - lo];
	int lc = hi - mi; T* C = _elem + mi;
	// 初始化向量 B
	for (int i = 0 ; i < lb; i ++) {
		B[i] = A[i];
	}
	// 进行排序
	for (Rank i = 0, j = 0, k = 0; j < lb;) {
		// 如果 B 中元素小于等于 C 中元素, 或 C 中元素已经耗尽. 则复制 B 中元素
		if ( (B[j] <= C[k]) || (lc <= k) ) A[i++] = B[j++];
		// 如果 C 中元素小于 B 中元素, 且 C 中元素尚存. 则复制 C 中元素
		if ( (C[k] < B[j]) && (k < lc) ) A[i++] = C[k++];
		

	}
	// 释放 B
	delete [] B;
}

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {
	
}




#pragma mark - Main
int main(int argc, const char * argv[]) {
	// insert code here...
	
	
	
	
	Vector<int> *v1 = new Vector<int>[20];
	
	for (int i = 0; i < 20; i++) {
		v1->insert(i, 0);
	}
	
	v1->printVector();
	
	v1->selectionSort(0, v1->size());
	
	v1->printVector();
	
	return 0;
}
