#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node <T>* prior;
	Node <T>* next;
};

template <typename T>
class DblLinkList
{
public:
	DblLinkList();
	~DblLinkList();

public:
	bool ListInsert(int i, const T& e);  //在第i个位置插入指定元素e
	bool ListDelete(int i);              //删除第i个位置的元素


	bool GetElem(int i, T& e);           //获得第i个位置的元素值
	int  LocateElem(const T& e);         //按元素值查找其在双链表中第一次出现的位置

	void DispList();                     //输出双链表中的所有元素
	int  ListLength();                   //获取双链表的长度
	bool Empty();                        //判断双链表是否为空

private:
	Node<T>* mhead; //头指针（指向链表第一个节点的指针，如果链表有头结点则指向头结点）
	int mlength;
};

template <typename T>
bool DblLinkList<T>::ListInsert(int i, const T& e)  //在第i个位置插入指定元素e
{
	if (i < 1 || i >(mlength + 1))
	{
		cout<<"插入位置不合法" << endl;
		return false;
	}
	Node <T>* newNode = new Node<T>;
	newNode->data = e;
	Node <T>* pcurr = mhead;
	for (int j = 0; j < i-1; j++)
	{
		pcurr = pcurr->next;
	}
	Node <T>* ptemp = pcurr->next;
	if (ptemp == nullptr)		//双链表为什么要增加对后续节点的判断操作？？单链表都没有判断
	{
		pcurr->next = newNode;
		newNode->prior = pcurr;
		newNode->next = nullptr;
		mlength++;				//分支注意增加长度。
		return true;
	}

	pcurr->next = newNode;
	ptemp->prior = newNode;
	newNode->next = ptemp;
	newNode->prior = pcurr;
	mlength++;
	return true;
}

template <typename T>
void DblLinkList<T>::DispList()
{
	if (mlength < 1)
	{
		cout<<"没有数据可展示" << endl;
	}
	Node <T>* temp = mhead;
	while (temp->next != nullptr)
	{
		temp = temp->next;
		cout << temp->data << " ";
	}
	cout << endl;
}


template <typename T>
bool DblLinkList<T>::ListDelete(int i)	//删除第i个位置的元素
{
	if (mlength < 1)
	{
		cout<<"没有数据可以删除" << endl;
		return false;
	}
	if (i < 1 || i > mlength)
	{
		cout<<"删除位置不合法" << endl;
		return false;
	}
	Node <T>* pcurr = mhead;
	for (int j = 0; j < i-1; j++)
	{
		pcurr = pcurr->next;
	}
	Node <T>* pwilldelete = pcurr->next;
	pcurr->next = pwilldelete->next;
	pwilldelete->next->prior = pcurr;
	delete pwilldelete;
	return true;

}


template <typename T>
DblLinkList<T>::DblLinkList()
{
	mhead = new Node<T>;
	//mhead = nullptr; 这个地方不能这样 ， 好不容易new的地址 再指向空，就白new了。
	mhead->next = nullptr;
	mhead->prior = nullptr;
}


template <typename T>
DblLinkList<T>::~DblLinkList()
{
	Node <T>* pnode = mhead->next;
	Node <T>* ptemp;
	while (pnode != nullptr)
	{
		ptemp = pnode;
		pnode = pnode->next;
		delete ptemp;
	}
	delete mhead;
	mhead = nullptr;
	mlength = 0;
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	DblLinkList<int> seq;
	seq.ListInsert(1,10);
	seq.ListInsert(1,20);
	seq.ListInsert(1,30);
	seq.ListInsert(4,40);
	//seq.ListInsert(6,30);
	seq.DispList();
	seq.ListDelete(1);
	seq.DispList();

	return 0;
}