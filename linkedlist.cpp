/*
*功能：实现一个简单的带头结点的单链表
*/
#include<iostream>

using namespace std;

//链表结点结构体定义
struct LNode {
	int val;
	LNode *next;
	//默认构造函数
	LNode():val(0),next(nullptr){}
	//接受一个参数的构造函数
	LNode(int x) :val(x), next(nullptr) {}
};

//创建链表，生成头结点
void create(LNode *l)
{
	l->val = 0;
	l->next = nullptr;
}

//在表头插入元素
void insert(LNode *l,int e)
{
	LNode *q = new LNode(e);
	q->next = l->next;
	l->next = q;
}

//删除表头元素
void erase(LNode *l, int &e)
{
	if (l->next)
	{
		e = l->next->val;
		l->next = l->next->next;
	}
	else
		cout << "表为空！" << endl;
}

//遍历打印链表元素
void traverse(LNode *l)
{
	LNode *q = l;
	while (q->next)
	{
		cout << q->next->val << " ";
		q = q->next;
	}
	cout << endl;
}

//链表长度
int length(LNode *l)
{
	LNode *q = l;
	int i = 0;
	while (q->next)
	{
		++i;
		q = q->next;
	}
	return i;
}

//查找第i个元素的值
int find_ith(LNode *l, int i)
{
	int j = 0;
	LNode *q = l;
	while (q->next&&j != i - 1)
	{
		q = q->next;
		++j;
	}
	if (!q->next)
		return -1;
	return q->next->val;
}

//替换第i个元素的值
void change_ith(LNode *l, int i,int e)
{
	int j = 0;
	LNode *q = l;
	while (q->next&&j != i - 1)
	{
		q = q->next;
		++j;
	}
	if (!q->next||j>=i)
		cout << "元素不存在！" << endl;
	q->next->val = e;
}
int main()
{
	LNode *l = new LNode();  //创建头结点
	create(l);
	int e = 0;
	insert(l, 2);
	insert(l, 3);
	insert(l, 4);
	insert(l, 5);
	cout << "链表元素为： " << endl;
	traverse(l);
	erase(l, e);
	cout << "删除元素为： "<<e << endl;
	cout << "链表元素为： " << endl;
	traverse(l);
	cout << "链表长度为： " << endl;
	cout << length(l) << endl;
	cout << "第2个元素为： "<<find_ith(l, 2) << endl;
	change_ith(l, 2, 5);  //替换第二个元素值
	cout << "链表元素为： " << endl;
	traverse(l);
	return 0;
}