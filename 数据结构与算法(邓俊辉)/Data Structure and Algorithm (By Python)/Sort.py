#coding:utf-8


A = [12, 32, 2, 33, 9, 6, 56, 44, 13, 42, 12, 10]

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