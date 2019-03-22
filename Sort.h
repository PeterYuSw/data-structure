#pragma once
//#ifndef SORT_H
//#define SORT_H
#include<algorithm>
using namespace std;

//1-1冒泡排序
void Bubble_sort(int a[], int n)
{
	for (int i =n-1; i !=0; i--)
	{
		for (int j = 0; j != i; j++)    //把最大的元素放到最后
		{
			if (a[j + 1] < a[j])    //只有严格小于才交换元素，算法是稳定的
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

//1-2优化的冒泡排序
void BBubble_sort(int a[], int n)
{
	int flag = 0;    //设置一个flag用于表示是否发生了交换
	for (int i = n - 1; i != 0; i--)
	{
		flag = 0;
		for (int j = 0; j != i; j++)    //一次冒泡
		{
			if (a[j + 1] < a[j])    
			{
				flag = 1;    //标识发生了交换
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
		if (flag == 0)    //如果有任何一次没有发生交换，则退出循环
			break;
	}
}

//2.插入排序（扑克牌抓牌）
void Insertion_sort(int a[], int n)
{
	int i = 0;
	for (int p = 1; p != n; p++)
	{
		int temp = a[p];    //摸下一张牌
		for (i = p; i >= 1 && a[i-1] > temp; --i)
			a[i] = a[i - 1];    //移出空位
		a[i] = temp;    //插入新牌
	}
}

//3.希尔排序（优化的插入排序）
void Shell_sort(int a[], int n)
{
	for (int D = n / 2; D != 0; D /= 2)    //增量序列
	{
		int i = 0, p = 0;
		for (p = D; p != n; p++)    //一次增量排序
		{
			int temp = a[p];
			for (i = p; i >= D && a[i - D] > temp; i -= D)    
				a[i] = a[i - D];
			a[i] = temp;
		}
	}
}

//4.选择排序
void Selection_sort(int a[], int n)
{
	for (int i = 0; i != n-1; i++)    //n次排序，每次把最小的元素与最左边元素交换
	{
		int min = i;
		for (int j = i+1; j != n; j++)    //查找未排序部分的最小元素的下标
			if (a[j] < a[min])
				min = j;
		int t = a[i];    //交换元素
		a[i] = a[min];
		a[min] = t;
	}
}

//5.1 归并排序（递归算法）
void Merge(int a[], int tempa[], int L, int R, int Rend)    //将一个序列前后部分归并成一个有序序列
{
	int temp = L;
	int Lend = R - 1;
	int size = Rend - L + 1;
	while (L <= Lend && R <= Rend)
	{
		if (a[L] <= a[R])
			tempa[temp++] = a[L++];
		else
			tempa[temp++] = a[R++];
	}
	while (L <= Lend)
		tempa[temp++] = a[L++];
	while (R <= Rend)
		tempa[temp++] = a[R++];
	for (int i = Rend; i != Rend - size; i--)
		a[i] = tempa[i];
}

void Msort(int a[], int tempa[], int L, int Rend)    //递归归并一个序列
{
	int center;
	if (L < Rend)
	{
		center = (L + Rend) / 2;
		Msort(a, tempa, L, center);
		Msort(a, tempa, center + 1, Rend);
		Merge(a, tempa, L, center + 1, Rend);
	}
}

void Merge_sort(int a[], int n)    //归并排序接口
{
	int *p = new int[n];
	Msort(a, p, 0, n - 1);
	delete p;
}

//5.2归并排序（非递归）

//不再将tempa[]中元素copy到a[]中
void Merge1(int a[], int tempa[], int L, int R, int Rend)
{
	int temp = L;
	int Lend = R - 1;
	while (L <= Lend && R <= Rend)
	{
		if (a[L] <= a[R])
			tempa[temp++] = a[L++];
		else
			tempa[temp++] = a[R++];
	}
	while (L <= Lend)
		tempa[temp++] = a[L++];
	while (R <= Rend)
		tempa[temp++] = a[R++];
}

//一趟归并
void Merge_pass(int a[], int tempa[], int n, int length)
{
	int i = 0;
	for (i; i <=(n -2*length); i += 2 * length)
	{
		Merge1(a, tempa, i, i + length, i + 2 * length - 1);
	}
	if (i + length < n)
		Merge1(a, tempa, i, i + length, n - 1);
	else
		for (int j = i; j < n; j++)
			tempa[j] = a[j];
}

//通用接口
void Merge_sort1(int a[], int n)
{
	int length = 1;
	int *p = new int[n];
	while (length<n)
	{
		Merge_pass(a, p, n, length);
		length *= 2;
		Merge_pass(p, a, n, length);
		length *= 2;
	}
	free(p);
}

//6.快速排序
void find_pivot(int a[], int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[mid])
		swap(a[left], a[mid]);
	if (a[left] > a[right])
		swap(a[left], a[right]);
	if (a[mid] > a[right])
		swap(a[mid], a[right]);
	swap(a[mid], a[right]);
}

void Qsort(int a[],int left,int right)
{
	if (right > left)
	{
		find_pivot(a, left, right);
		int i = left, j = right;
		while (j > i)
		{
			while (a[i] < a[right])
				++i;
			while (a[j] > a[right])
				--j;
			if (i < j)
				swap(a[i++], a[j--]);
		}
		swap(a[i], a[right]);
		Qsort(a, left, i - 1);
		Qsort(a, i + 1, right);
	}
}

void Quick_sort(int a[], int n)
{
	Qsort(a, 0, n - 1);
}

//#endif