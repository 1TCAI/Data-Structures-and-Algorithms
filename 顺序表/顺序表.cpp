#include<iostream>

#define InitSize 10
#define IncSize 5

using namespace std;
template <typename T>
class SeqList
{
public:
	SeqList(int length = InitSize);
	~SeqList();
	bool ListInsert(int i, const T& e);
	bool GetElem(int i, T& e);
	bool ListDelete(int i);
	int LocateElem(const T& e);

	void DispList();
	int ListLength();
	void ReverseList();

private:
	void IncreaseSize();
private:
	T* mdata;
	int mlength;
	int mmaxsize;
};

template <typename T>
SeqList<T>::SeqList(int length)
{
	mdata = new T[length];
	mlength = 0;
	mmaxsize = length;
}
template <typename T>
SeqList<T>::~SeqList()
{
	delete[] mdata;
	mlength = 0;
}


template <typename T>
bool SeqList<T>::ListInsert(int i, const T& e)
{
	if (mlength >= mmaxsize)
	{
		//cout<<"已满，不允许插入" << endl;
		//return false;
		IncreaseSize();
	}
	if (i < 1 || i > mlength+1)
	{
		cout<<i<<"插入位置不合法。在1-"<<mlength<<"之间插入" << endl;		
		return false;
	}
	for (int j = mlength; j >= i; j--)
	{
		mdata[j] = mdata[j-1];
	}
	mdata[i-1] = e;
	mlength++;
	return true;
}


template <typename T>
bool SeqList<T>::ListDelete(int i)
{
	if (mlength < 1)
	{
		cout<<"顺序表为空，不能删除" << endl;
		return false;
	}
	if (i < 1 || i > mlength)
	{
		cout<<"删除位置不合法" << endl;
		return true;
	}
	for (int j = i; j < mlength; j++)
	{
		mdata[j-1] = mdata[j];
	}
	mlength--;
	return false;
}


template <typename T>
bool SeqList<T>::GetElem(int i, T& e)
{
	if (mlength < 1)
	{
		cout << "顺序表为空，不能获取" << endl;
		return false;
	}
	if (i < 1 || i > mlength)
	{
		cout << "获取位置不合法" << endl;
		return true;
	}
	e = mdata[i-1];
	return true;
}


template <typename T>
void SeqList<T>::DispList()
{
	if (mlength < 1)
	{
		cout << "顺序表为空，不能展示" << endl;
		return ;
	}
	for (int i = 0; i < mlength; i++)
	{
		cout << mdata[i] << " ";
	}
	cout<< endl;
}


template <typename T>
int SeqList<T>::LocateElem(const T& e)
{
	if (mlength < 1)
	{
		cout << "顺序表为空" << endl;
		return -1;
	}
	for (int i = 0; i < mlength; i++)
	{
		if (mdata[i] == e) 
		{
			cout<<"找到元素"<<e <<"位置在"<<i+1 << endl;
			return i + 1;
		}
	}
	cout<<"未找到元素"<<e << endl;
	return -1;
}


template <typename T>
int SeqList<T>::ListLength()
{
	return mlength;
}

template <typename T>
void SeqList<T>::ReverseList()
{
	if (mlength <=1)
	{
		cout<<"元素个数少于2 不用反转" << endl;
		return;
	}
	T temp;
	for (int i = 0; i < mlength/2; i++)
	{
		temp = mdata[i];
		mdata[i] = mdata[mlength-i-1];
		mdata[mlength - i - 1] = temp;
	}
}



template <typename T>
void SeqList<T>::IncreaseSize()
{
	T* p = mdata;
	mdata = new T[mmaxsize + IncSize];
	for (int i = 0; i < mlength; i++)
	{
		mdata[i] = p[i];
	}
	mmaxsize = mmaxsize + IncSize;
	delete[] p;
}


int main()
{

	SeqList<int> seq(10);
	seq.ListInsert(1,10);
	seq.ListInsert(1,20);
	seq.ListInsert(1,30);
	seq.ListInsert(1,50);
	seq.ListInsert(1,60);
	seq.DispList();
	seq.ListDelete(3);
	seq.ListDelete(2);
	seq.DispList();
	seq.LocateElem(60);
	seq.ReverseList();
	seq.DispList();
	return 0;
}