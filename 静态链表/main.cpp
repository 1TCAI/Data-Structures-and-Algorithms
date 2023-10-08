#include <iostream>
using namespace std;


#define MaxSize 201


enum NODEUSE
{
	eNOUSE = -1,
	eLAST = -2
};
template <typename T>
struct Node
{
	T data;
	int cur;
};

template<typename T>
class StaticLinkList
{
public:
	StaticLinkList(); //���캯��
	~StaticLinkList() {}; //��������

public:
	int findAnIdlePos(); //�ҵ�һ������λ�����ڱ�������
	bool ListInsert(int iPos, const T& e); //�ڵ�i��λ�ò���ָ��Ԫ��e
	bool ListDelete(int i); //ɾ����i��λ�õ�Ԫ��

	bool GetElem(int i, T& e); //��õ�i��λ�õ�Ԫ��ֵ
	int LocateElem(const T& e); //��Ԫ��ֵ�������ھ�̬�����е�һ�γ��ֵ�λ��

	void DispList();   //�����̬�����е�����Ԫ��
	int ListLength();  //��ȡ��̬����ĳ���
	bool Empty();   //�жϾ�̬�����Ƿ�Ϊ��

private:
	Node<T> mdata[MaxSize]; //����ڵ����ݵ�����
	int mlength; //��ǰ���ȣ�Ҳ���ǵ�ǰ��������ݽڵ���Ŀ
};


template<typename T>
bool StaticLinkList<T>::ListDelete(int i) //ɾ����i��λ�õ�Ԫ��
{
	if (mlength < 1)
	{
		return false;
	}
	if (i < 1 ||i > mlength)
	{
		return false;
	}

	Node <T> tmp = mdata[0];
	if (i == 1)
	{
		tmp = mdata[tmp.cur];
		if (mlength > 1) 
		{
			mdata[0].cur = tmp.cur;
			tmp.cur = eNOUSE;
			mlength--;
			return true;
		}
		tmp.cur = eNOUSE;
		mdata[0].cur = eLAST;
		mlength--;
		return true;
	}
	for (int j = 0; j < i-1; j++)
	{
		tmp = mdata[tmp.cur];
	}
	if (i == mlength)
	{
		mdata[tmp.cur].cur = eNOUSE;
		tmp.cur = eLAST;
		mlength--;
		return true;
	}
	//Node <T> next = mdata[mdata[tmp.cur].cur];
	tmp.cur = mdata[tmp.cur].cur;
	mdata[tmp.cur].cur = eNOUSE;

	mlength--;

	return true;
}



template<typename T>
int StaticLinkList<T>::LocateElem(const T& e) //��Ԫ��ֵ�������ھ�̬�����е�һ�γ��ֵ�λ��
{
	if (mlength < 1)
		return -1;
	Node <T> tmp = mdata[0];
	int pos = 0;
	while (tmp.cur != eLAST)
	{
		pos++;
		tmp = mdata[tmp.cur];
		if (tmp.data == e)
		{
			return pos ;
		}
	}
	return -1;
}
template<typename T>
bool StaticLinkList<T>::GetElem(int i, T& e) //��õ�i��λ�õ�Ԫ��ֵ
{
	if (mlength < 1)
		return false;
	if (i < 1 ||i > mlength)
		return false;
	
	Node <T> tmp = mdata[0];
	int count = 0;
	while (true)
	{
		count++;
		tmp = mdata[tmp.cur];
		if (count == i)
		{
			e = tmp.data;
			return true;
		}
	}
	return false;
}


template<typename T>
void StaticLinkList<T>::DispList()   //�����̬�����е�����Ԫ��
{
	if (mlength < 1)
		return;
	
	Node <T> curr = mdata[0];
	while (curr.cur != eLAST)
	{
		curr = mdata[curr.cur];
		cout << curr.data << "  ";
	}
	cout << endl;
}
template<typename T>
StaticLinkList<T>::StaticLinkList() //���캯��
{
	for (int i = 1; i < MaxSize; i++)
	{
		mdata[i].cur = eNOUSE;
	}
	mlength = 0;
}

template<typename T>
int StaticLinkList<T>::findAnIdlePos() //�ҵ�һ������λ�����ڱ�������
{
	for (int i = 1; i < MaxSize; i++)
	{
		if (mdata[i].cur == eNOUSE) 
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
bool StaticLinkList<T>::ListInsert(int iPos, const T& e) //�ڵ�i��λ�ò���ָ��Ԫ��e
{
	if (iPos < 1 || iPos >(mlength + 1))
	{
		cout<<"����λ�ò��Ϸ�" << endl;
		return false;
	}
	int iIdx = findAnIdlePos();

	if (iIdx == -1)
	{
		cout<<"û�п���λ��" << endl;
		return false;
	}

	int iIdxPrev;
	if (iPos == 1)
	{
		mdata[iIdx].data = e;
		if (mlength == 0)
		{
			mdata[iIdx].cur = eLAST;
		}
		else
		{									//ͷ�ڵ�curָ���һ��
			mdata[iIdx].cur = mdata[0].cur;	//�²����һ����curָ��ԭ�ȵ�һ��
		}
		mdata[0].cur = iIdx;
	}
	else
	{
		int iPosCount = 0;
		int tmpcur = mdata[0].cur;
		while (true)
		{
			iPosCount++;
			if (iPosCount == iPos -1)
			{
				iIdxPrev = tmpcur;
				break;
			}
			tmpcur = mdata[tmpcur].cur;
		}
		int nextcur = mdata[iIdxPrev].cur;
		mdata[iIdxPrev].cur = iIdx;
		mdata[iIdx].cur = nextcur;
		mdata[iIdx].data = e;
	}

	mlength++;
	return true;
}












int main()
{
	StaticLinkList<int> seq;
	seq.ListInsert(1,10);
	seq.ListInsert(1,20);
	seq.ListInsert(1,30);
	seq.DispList();
	int a;
	seq.GetElem(1,a);
	cout<<a<<endl;
	cout<<seq.LocateElem(30)<<endl;
	seq.ListDelete(3);
	seq.DispList();


	return 0;
}