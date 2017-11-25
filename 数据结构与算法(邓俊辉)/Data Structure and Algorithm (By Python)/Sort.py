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
def merge(a, b):	# �ϲ�������������ķ���
	c = []
	i = j = 0
	
	while i < len(a) and j < len(b):	# ѭ�����Ƴ�����Ϊ: a �� b ������һ����Ԫ���ȱ�ȡ��
		if a[i] < b[j]:
			c.append(a[i])
			i += 1
		else:
			c.append(b[j])
			j += 1
	
	if i == len(a):		# ������� a ��Ԫ����ȡ��, �� b ��ʣ��Ԫ�������� c ���
		for k in b[j:]:
			c.append(k)
	if j == len(b):		# ͬ��, �෴���
		for k in a[i:]:
			c.append(k)
			
	return c

def sort_merge(list):	# ���β���
	if len(list) < 2:
		return list
	middle = len(list) / 2				# ȡ��ֵԪ��, Ϊ���λ������
	left = sort_merge(list[:middle]) 	# �ݹ鴦����ߵ�������
	right = sort_merge(list[middle:])	# �ݹ鴦���ұߵ�������
	return merge(left, right)			# ���������������������


print('Merge Sort' ,sort_merge(A))