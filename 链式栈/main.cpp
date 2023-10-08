#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node <T>* next;
};


template <typename T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
	bool Push(const T& e); //入栈元素e
	bool Pop(T& e); //出栈（删除数据）操作，也就是删除栈顶数据
	bool GetTop(T& e); //读取栈顶元素，但该元素并没有出栈而是依旧在栈中

	void DispList(); //输出链式栈中的所有元素
	int ListLength(); //获取链式栈的长度
	bool Empty(); //判断链式栈是否为空
private:
	Node <T>* mtop;
	int mlength;
};

template <typename T>
LinkStack<T>::~LinkStack()
{
	Node<T>* p = mtop;

	while (p !=nullptr)
	{
		p = p->next;
		delete mtop;
		mtop = p;
	}


}



template <typename T>
bool LinkStack<T>::Empty() //判断链式栈是否为空
{
	if (mlength < 1)
	{
		return true;
	}
	return false;
}
template <typename T>
void LinkStack<T>::DispList() //输出链式栈中的所有元素
{
	if (Empty())
	{
		return;
	}
	Node <T>* tmp = mtop;
	while (tmp != nullptr)
	{
		cout<<tmp->data<<endl;
		tmp = tmp->next;
	}
}
template <typename T>
LinkStack<T>::LinkStack()
{
	mtop = nullptr;
	mlength = 0;
}
template <typename T>
bool LinkStack<T>::Push(const T& e) //入栈元素e
{
	Node <T>* newNode = new Node<T>;
	newNode->next = mtop;
	newNode->data = e;
	mtop = newNode;
	mlength++;
	return true;
}
template <typename T>
bool LinkStack<T>::Pop(T& e) //出栈元素e
{
	if (Empty())
	{
		return false;
	}
	Node <T>* tmp = mtop;
	e = tmp->data;
	mtop = mtop->next;
	mlength--;
	delete tmp;
	return true;

}
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	LinkStack<int> seq;
	seq.Push(10);
	seq.DispList();
	return 0;
}