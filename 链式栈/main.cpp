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
	bool Push(const T& e); //��ջԪ��e
	bool Pop(T& e); //��ջ��ɾ�����ݣ�������Ҳ����ɾ��ջ������
	bool GetTop(T& e); //��ȡջ��Ԫ�أ�����Ԫ�ز�û�г�ջ����������ջ��

	void DispList(); //�����ʽջ�е�����Ԫ��
	int ListLength(); //��ȡ��ʽջ�ĳ���
	bool Empty(); //�ж���ʽջ�Ƿ�Ϊ��
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
bool LinkStack<T>::Empty() //�ж���ʽջ�Ƿ�Ϊ��
{
	if (mlength < 1)
	{
		return true;
	}
	return false;
}
template <typename T>
void LinkStack<T>::DispList() //�����ʽջ�е�����Ԫ��
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
bool LinkStack<T>::Push(const T& e) //��ջԪ��e
{
	Node <T>* newNode = new Node<T>;
	newNode->next = mtop;
	newNode->data = e;
	mtop = newNode;
	mlength++;
	return true;
}
template <typename T>
bool LinkStack<T>::Pop(T& e) //��ջԪ��e
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	LinkStack<int> seq;
	seq.Push(10);
	seq.DispList();
	return 0;
}