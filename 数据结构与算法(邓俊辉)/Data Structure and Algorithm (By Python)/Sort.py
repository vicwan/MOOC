#coding:utf-8


A = [12, 32, 2, 33, 9, 6, 56, 44, 13, 42, 12, 10]


# Bubble Sort

def bubble_slow( A, lo, hi ):
	while lo < hi - 1:
		if A[lo] > A[lo + 1]:
			(A[lo], A[lo + 1]) = (A[lo + 1], A[lo])
		lo += 1
	return
	
def bubble_medium( A, lo, hi ):
	isSorted = True
	while lo < hi - 1:
		if A[lo] > A[lo + 1]:
			isSorted = False
			(A[lo], A[lo + 1]) = (A[lo + 1], A[lo])
		lo += 1
	return isSorted
	
def bubble_fast( A, lo, hi ):
	last = 0;
	while lo < hi - 1:
		if A[lo] > A[lo + 1]:
			last = lo + 1
			(A[lo], A[lo + 1]) = (A[lo + 1], A[lo])
		lo += 1
	return last


def sort_bubble_slow( A, lo, hi ):
	loopCount = 0;
	while lo < hi:
		loopCount += 1
		bubble_slow(A, lo, hi)
		hi -= 1
	print(loopCount)

def sort_bubble_medium( A, lo, hi ):
	isSorted = False
	loopCount = 0;
	while isSorted == False:
		loopCount += 1
		isSorted = bubble_medium(A, lo, hi)
		hi -= 1
	print(loopCount)

def sort_bubble_fast( A, lo, hi ):
	loopCount = 0;
	while (lo < hi):
		loopCount += 1
		hi = bubble_fast(A, lo, hi)
	print(loopCount)



# Merge Sort
def merge(a, b):	# 合并两个有序数组的方法
	c = []
	i = j = 0
	
	while i < len(a) and j < len(b):	# 循环的推出条件为: a 或 b 中任意一方的元素先被取完
		if a[i] < b[j]:
			c.append(a[i])
			i += 1
		else:
			c.append(b[j])
			j += 1
	
	if i == len(a):		# 如果数组 a 中元素先取完, 则将 b 中剩余元素依次向 c 添加
		for k in b[j:]:
			c.append(k)
	if j == len(b):		# 同上, 相反情况
		for k in a[i:]:
			c.append(k)
			
	return c

def sort_merge(list):	# 分治策略
	if len(list) < 2:
		return list
	middle = len(list) / 2				# 取中值元素, 为分治划清界限
	left = sort_merge(list[:middle]) 	# 递归处理左边的子数组
	right = sort_merge(list[middle:])	# 递归处理右边的子数组
	return merge(left, right)			# 返回左右子数组的排序结果


print('Merge Sort' ,sort_merge(A))