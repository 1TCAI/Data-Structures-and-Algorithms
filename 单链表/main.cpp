#include <iostream>

using namespace std;



template <typename T>
struct Node
{
	T data;
	Node <T>* next;
};

template <typename T>
class LinkList
{
public:
	LinkList();
	~LinkList();
	bool ListInsert(int i, const T& e);
	bool InsertPriorNode(Node <T>& pcurr, const T& e);
	bool ListDelete(int i);
	bool GetElem(int i ,T& e);
	int LocateElem(const T& e);
	void DistList();
	bool Empty();
	void ReverseList();
	int ListLength();

private:
	Node <T>* mhead;
	int mlength;
};

template <typename T>
void LinkList<T>::ReverseList()
{
	if (mlength <= 1)
	{
		cout << "数据少于2 无法反转" << endl;
		return;
	}
	Node <T>* pothersjd = mhead->next->next;
	mhead->next->next = nullptr;
	Node <T>* ptemp;
	while (pothersjd != nullptr)
	{
		ptemp = pothersjd;
		pothersjd = pothersjd->next;
		ptemp->next = mhead->next;
		mhead->next = ptemp;
	}
}

template <typename T>
LinkList<T>::~LinkList()
{
	Node <T>* pnode = mhead->next;
	Node <T>* temp ;
	while (pnode != nullptr)
	{
		temp = pnode;
		pnode = pnode->next;
		delete temp;
	}
	delete mhead;
	mhead = nullptr;
	mlength = 0;
}

template <typename T>
void LinkList<T>::DistList()
{
	if (mlength < 1)
	{
		cout << "无数据展示" << endl; 
		return;
	}
	Node <T>* pcurr = mhead;
	for (int i = 0; i < mlength; i++)
	{
		pcurr = pcurr->next;
		cout<<pcurr->data<<" ";
	}
	cout << endl;
}
//获取单链表的长度，O(1)
template<typename T>
int LinkList<T>::ListLength()
{
	return mlength;
}
template<typename T>
bool LinkList<T>::Empty()
{
	if (mhead->next == nullptr) //单链表为空（如果是不带头节点的单链表if(m_head == nullptr)来判断是否为空。
	{
		return true;
	}
	return false;
}
template <typename T>
LinkList<T>::LinkList()
{
	mhead = new Node<T>;
	mhead->next = nullptr;
	mlength = 0;
}


template <typename T>
bool LinkList<T>::ListInsert(int i, const T& e)
{
	if (i < 1 || i >(mlength + 1))
	{
		cout<<"插入位置不合法" << endl;
		return false;
	}
	Node <T>* pcurr = mhead;
	for (int j = 0; j < i-1; j++)
	{
		pcurr = pcurr->next;
	}
	Node<T>* node = new Node<T>;
	node->data = e;
	node->next = pcurr->next;

	pcurr->next = node;
	mlength++;
	return true;
}
template <typename T>
bool LinkList<T>::ListDelete(int i)
{
	if (mlength < 1)
	{
		cout<<"没有数据" << endl;
		return false;
	}
	if (i < 1 || i > mlength)
	{
		cout<<"删除数据位置不合法" << endl;
		return false;
	}
	Node <T>* pcurr = mhead;
	for (int j = 0; j < i-1; j++)
	{
		pcurr = pcurr->next;
	}
	Node <T>* pwilldelete = pcurr->next;
	pcurr->next = pwilldelete->next;
	delete pwilldelete;
	mlength--;
	return true;

}

//template <typename T>
//bool LinkList<T>::ListInsert(int i, const T& e)
//{
//	if (i < 1 || i >(mlength + 1))
//	{
//		cout<<"插入位置不对" << endl;
//	}
//	if (i == 1)
//	{
//		Node <T>* newNode = new Node<T>;
//		newNode->data = e;
//		newNode->next = mhead;
//		mhead = newNode;
//		mlength++;
//		return true;
//	}
//	Node <T>* pcurr = mhead;
//	for (int j = 1; j < (i - 1); j++)
//	{
//		pcurr = pcurr->next;
//	}
//	Node <T>* newNode = new Node<T>;
//	newNode->data = e;
//	newNode->next = pcurr->next;
//	pcurr->next = newNode;
//	mlength++;
//	return true;
//}

template <typename T>
bool LinkList<T>::InsertPriorNode(Node <T>& pcurr, const T& e)
{
	if (pcurr->next == nullptr)
	{
		Node <T>* newNode = new Node<T>;
		newNode->next = nullptr;
		newNode->data = pcurr->data;
		pcurr->data = e;
		return true;
	}
	Node <T>* newNode = new Node<T>;
	newNode->next = pcurr->next;
	pcurr->next = newNode;
	newNode->data = pcurr->data;
	pcurr->data = e;
	return true;
}
template <typename T>
bool LinkList<T>::GetElem(int i, T& e)
{
	if (mlength < 1)
	{
		cout<<"没有数据可查询" << endl;
		return false;
	}
	if (i < 1 || i > mlength)
	{
		cout<<"输入查询位置不合法" << endl;
		return false;
	}
	Node <T>* pcurr = mhead;
	for (int j = 0; j < i; j++)
	{
		pcurr = pcurr->next;
	}
	e = pcurr->data;
	return true;
}
template <typename T>
int LinkList<T>::LocateElem(const T& e)
{
	if (mlength < 1)
	{
		cout << "LocateElem没有数据可查询" << endl;
		return false;
	}
	Node <T>* pcurr = mhead;
	for (int i = 0; i < mlength; i++)
	{
		pcurr = pcurr->next;
		if (pcurr->data == e)
		{
			return i+1;
		}
	}
	return -1;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	LinkList<int> seq;
	seq.ListInsert(1,1);
	seq.ListInsert(1,2);
	seq.ListInsert(3,3);
	seq.DistList();
	//cout << seq.LocateElem(3) << endl;
	//int evl;
	//seq.GetElem(1,evl);
	//cout<<evl<<endl;
	//seq.ListInsert(5,2);
	seq.ReverseList();
	seq.DistList();

	return 0;
}