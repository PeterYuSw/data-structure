/*
*利用链表实现一个简单的栈
*2019-2-25
*/

#include<iostream>

using namespace std;

//构造一个链表节点的结构体
struct Node {
	int val;
	Node *next;
};

//定义栈的类
class Stack {
public:
	void init();
	void push(int e);
	void pop();
	int top();
	bool IsEmpty();
	int Length();
private:
	int length=0;
	Node *head;
};

//初始化栈
void Stack::init()
{
	head= new Node();
	length = 0;
}

//push操作
void Stack::push(int e)
{
	Node *p = new Node();
	p->val = e;
	p->next = nullptr;
	if (!head->next)
	{
		head->next = p;
		++length;
	}
	else
	{
		p->next = head->next;
		head->next = p;
		++length;
	}
}

//pop操作
void Stack::pop()
{
	if (!head->next)
		cout << "栈为空！" << endl;
	else
	{
		Node *q = head->next;
		head->next = q->next;
		delete q;
		--length;
	}
}

//获取栈顶元素值
int Stack::top()
{
	if (!head->next)
		return -1;
	else
	{
		return head->next->val;
	}
}

//判断栈是否为空
bool Stack::IsEmpty()
{
	if (!head->next)
		return true;
	else
		return false;
}

//获取栈的长度
int Stack::Length()
{
	return length;
}

int main()
{
	Stack s;
	s.init();
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.pop();
	cout << "栈顶元素为： " << endl;
	cout << s.top() << endl;
	cout << "栈长度为： " << endl;
	cout << s.Length() << endl;
	return 0;
}