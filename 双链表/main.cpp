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
	bool ListInsert(int i, const T& e);  //�ڵ�i��λ�ò���ָ��Ԫ��e
	bool ListDelete(int i);              //ɾ����i��λ�õ�Ԫ��


	bool GetElem(int i, T& e);           //��õ�i��λ�õ�Ԫ��ֵ
	int  LocateElem(const T& e);         //��Ԫ��ֵ��������˫�����е�һ�γ��ֵ�λ��

	void DispList();                     //���˫�����е�����Ԫ��
	int  ListLength();                   //��ȡ˫����ĳ���
	bool Empty();                        //�ж�˫�����Ƿ�Ϊ��

private:
	Node<T>* mhead; //ͷָ�루ָ�������һ���ڵ��ָ�룬���������ͷ�����ָ��ͷ��㣩
	int mlength;
};

template <typename T>
bool DblLinkList<T>::ListInsert(int i, const T& e)  //�ڵ�i��λ�ò���ָ��Ԫ��e
{
	if (i < 1 || i >(mlength + 1))
	{
		cout<<"����λ�ò��Ϸ�" << endl;
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
	if (ptemp == nullptr)		//˫����ΪʲôҪ���ӶԺ����ڵ���жϲ�������������û���ж�
	{
		pcurr->next = newNode;
		newNode->prior = pcurr;
		newNode->next = nullptr;
		mlength++;				//��֧ע�����ӳ��ȡ�
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
		cout<<"û�����ݿ�չʾ" << endl;
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
bool DblLinkList<T>::ListDelete(int i)	//ɾ����i��λ�õ�Ԫ��
{
	if (mlength < 1)
	{
		cout<<"û�����ݿ���ɾ��" << endl;
		return false;
	}
	if (i < 1 || i > mlength)
	{
		cout<<"ɾ��λ�ò��Ϸ�" << endl;
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
	//mhead = nullptr; ����ط��������� �� �ò�����new�ĵ�ַ ��ָ��գ��Ͱ�new�ˡ�
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
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