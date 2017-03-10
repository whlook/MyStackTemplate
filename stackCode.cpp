#include <iostream>
#include <stdlib.h>
using namespace std;

template<class T>
struct node
{

	T value;
	node<T>* next;

	node() :next(nullptr){};
	node(T t) :value(t), next(nullptr){};
};

template<class T>
class myStack
{
	int cnts; //入栈数量
	node<T> *head; //栈的头部
public:

	myStack(){ cnts = 0; head = new node<T>; }
	void stackPush(T arg); //入栈
	T stackPop();  //出栈
	T stackTop(); //获取栈顶元素

	void printStack(); //打印栈
	int counts(); //获取栈内元素个数
	bool isEmpty(); //判断空
};
template<class T>
void myStack<T>::stackPush(T arg)
{
	node<T> *pnode = new node<T>(arg); //申请入栈元素的空间
	pnode->next = head->next;
	head->next = pnode;
	cnts++;
}
template<class T>
T myStack<T>::stackPop()
{
	if (head->next!=nullptr) 
	{
		node<T>* temp = head->next;
		head->next = head->next->next;
		T popVal = temp->value;
		delete temp;
		return popVal;
	}
}
template<class T>
T myStack<T>::stackTop()
{
	if (head->next!=nullptr)
	{
		return head->next->value;
	}
}
template<class T>
void myStack<T>::printStack()
{
	if (head->next != nullptr)
	{
		node<T>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			cout << temp->value << endl;
		}
	}
}
template<class T>
int myStack<T>::counts()
{
	return cnts;
}
template<class T>
bool myStack<T>::isEmpty()
{
	if (cnts)
		return false;
	else
		return true;
}
int main()
{
	myStack<char*> stackTest;
	
	stackTest.stackPush("hello");
	stackTest.stackPush("world");
	stackTest.stackPush("!");
	cout << stackTest.isEmpty() << endl;	
	cout << stackTest.stackTop() << endl;
	stackTest.printStack();

	stackTest.stackPop();
	cout << stackTest.isEmpty() << endl;
	cout << stackTest.stackTop() << endl;
	stackTest.printStack();

}
