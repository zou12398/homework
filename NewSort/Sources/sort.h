#pragma once

#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int* a, int n)
{
	if (a == NULL||n<=0)
		return;
	int* b = a+1;
	int* c;
	int* a1 = a - 1;
	for (int i = 1; i < n; i++)
	{
		for (c = b-1, b = b + 1;c!=a1&&*c>*(c+1);c-=1)
		{
			if (*c > *(c + 1))
			{
				int d = *c;
				*c = *(c + 1);
				*(c + 1) = d;
			}
		}
	}

}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	if (begin > end)
		return;
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int k = begin;
	while (begin1 <= end1 && begin2 <= end2)
		temp[k++] = a[begin1] < a[begin2] ? a[begin1++] : a[begin2++];
	while (begin1 <= end1)
		temp[k++] = a[begin1++];
	while (begin2 <= end2)
		temp[k++] = a[begin2++];
	for (int i = begin; i <= end; i++)
	{
		a[i] = temp[i];
	}

}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp)
{
	int mid;
	if(begin<end)
	{
		mid = begin + (end - begin) / 2;
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid+1, end, temp);
		MergeArray(a, begin, mid, end, temp);
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end)
{
	if (begin >= end||a==NULL)
		return;
	int r = rand() % (end-begin)+begin;														//生成随机数
	int m = a[begin];
	a[begin] = a[r];
	a[r] = m;
	int tmp = a[begin];
	int i = begin;
	int j = end;
	while (i != j)
	{
		while (a[j] >= tmp && i < j)
			j--;
		while (a[i] <= tmp && i < j)
			i++;
		if (i < j)
		{
			m = a[i];
			a[i] = a[j];
			a[j] = m;
		}
	}
	a[begin] = a[j];
	a[j] = tmp;
	QuickSort_Recursion(a, begin, j-1);
	QuickSort_Recursion(a, j + 1, end);
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */

void QuickSort(int* a, int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void midian(int* left, int* mid, int* right)									//取中间值并确保左指针是指向中间值
{
	int a = *left,b=*mid,c=*right,t;
	if (b > a)
	{
		t = *left;
		*left = *mid;
		*mid = t;
	}
	if(c>a)
	{
		t = *left;
		*left = *right;
		*right = t;
	}
	if (*mid > *right)
	{
		t = *mid;
		*mid = *left;
		*left = t;
	}
	else
	{
		t = *right;
		*right = *left;
		*left = t;
	}

}

void Partition(int* a, int begin, int end)
{
	if (begin >= end || a == NULL)
		return;
	int mid = begin + (end - begin) / 2;
	midian(&a[begin], &a[mid], &a[end]);
	int m;
	int tmp = a[begin];
	int i = begin;
	int j = end;
	while (i != j)
	{
		while (a[j] >= tmp && i < j)
			j--;
		while (a[i] <= tmp && i < j)
			i++;
		if (i < j)
		{
			m = a[i];
			a[i] = a[j];
			a[j] = m;
		}
	}
	a[begin] = a[j];
	a[j] = tmp;
	Partition(a, begin, j - 1);
	Partition(a, j + 1, end);
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size)
{
	if (a == NULL || size <= 1)
		return;
	int min = a[0],max=a[0];
	for (int i = 0; i < size; i++)
	{
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	int* b = (int*)malloc(sizeof(int) * size);
	int* c = (int*)malloc(sizeof(int) * (max-min+1));
	for (int i = 0; i < max - min + 1; i++)
		c[i] = 0;
	for (int i = 0; i < size; i++)
	{
		c[a[i] - min] += 1;
	}
	for (int i = 1; i < max-min+1; ++i) 
	{
		c[i] = c[i] + c[i - 1];
	}
	for (int i = size - 1; i >= 0; --i) 
	{
		b[--c[a[i] - min]] = a[i];
	}
	for (int i = 0; i < size; i++)
		a[i] = b[i];
	free(b);
	free(c);
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size)
{
	if (a == NULL || size <= 1)
		return;
	int* c = (int*)malloc(sizeof(int) * 10);
	int* b = (int*)malloc(sizeof(int) * size);
	int max = a[0];
	for (int i = 0; i < size; i++)
		if (a[i] > max)
			max = a[i];
	int place = 1;
	while (max/place>0)
	{
		for (int i = 0; i < 10; i++)
			c[i] = 0;
		for (int i = 0; i < size; i++)
		{
			c[(a[i] / place) % 10]++;
		}
		for (int i = 1; i < 10; i++)
			c[i] += c[i - 1];
		for (int i = size - 1; i >= 0; i--)
			b[--c[(a[i] / place) % 10]] = a[i];
		for (int i = 0; i < size; i++)
			a[i] = b[i];
		place *= 10;
	}
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size)
{
	if (a == NULL || size <= 1)
		return;
	int p0 = 0, p1 = 0, p2 = size - 1,t;
	while (p1 <= p2)
	{
		if (a[p1] == 0)
		{
			t = a[p0];
			a[p0] = a[p1];
			a[p1] = t;
			p1 += 1;
			p0 += 1;
		}
		else if (a[p1] == 1)
		{
			p1 += 1;
		}
		else if (a[p1] == 2)
		{
			t = a[p2];
			a[p2] = a[p1];
			a[p1] = t;
			p2 -= 1;
		}
	}
}


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int search(int* a, int size,int k,int choice)
{
	if (a == NULL || size == 0 || k < 1)
		return;
	int tar=-1, l = 0, r = size - 1;
	if (choice == 1)
	{
		while (tar != size - k)
		{
			tar=SearchPartition(a, l, r);
			if (tar < size - k)
			{
				l = tar+1;
			}
			if (tar > size - k)
			{
				r = tar-1;
			}
		}
	}
	else if(choice==0)
	{
		while (tar != k-1)
		{
			tar = SearchPartition(a, l, r);
			if (tar < k-1)
			{
				l = tar+1;
			}
			if (tar > k-1)
			{
				r = tar-1;
			}
		}
	}
	return a[tar];
}

int SearchPartition(int* a, int begin, int end)
{
	if (begin >= end || a == NULL)
		return begin;
	int mid = begin + (end - begin) / 2;
	midian(&a[begin], &a[mid], &a[end]);
	int m;
	int tmp = a[begin];
	int i = begin;
	int j = end;
	while (i != j)
	{
		while (a[j] >= tmp && i < j)
			j--;
		while (a[i] <= tmp && i < j)
			i++;
		if (i < j)
		{
			m = a[i];
			a[i] = a[j];
			a[j] = m;
		}
	}
	a[begin] = a[j];
	a[j] = tmp;
	return j;
}

#endif // QUEUE_H_INCLUDED
