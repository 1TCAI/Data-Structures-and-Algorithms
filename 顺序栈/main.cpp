#include <iostream>

using namespace std;
#define InitSize 10
#define IncSize 5

template <typename T>
class SeqStack
{
public:
	SeqStack(int length = InitSize);
	~SeqStack();

	bool Push(const T& e); //��ջ���������ݣ�
	bool Pop(T& e);        //��ջ��ɾ�����ݣ���Ҳ����ɾ��ջ������
	bool GetTop(T& e);     //��ȡջ��Ԫ�أ�����Ԫ�ز�û�г�ջ����������ջ��

	void DispList(); //���˳��ջ������Ԫ��
	int ListLength(); //��ȡ˳��ջ�ĳ��ȣ�ʵ��ӵ�е�Ԫ��������

	bool IsEmpty(); //�ж�˳��ջ�Ƿ�Ϊ��
	bool IsFull();  //�ж�˳��ջ�Ƿ�����
private:
	void IncreaseSize(); //��˳��ջ�������ݺ���Ե��ô˺���Ϊ˳��ջ����

private:
	T* mdata;
	int mtop;
	int mmaxsize;
};

template <typename T>
int SeqStack<T>::ListLength() //��ȡ˳��ջ�ĳ��ȣ�ʵ��ӵ�е�Ԫ��������
{
	return mtop + 1;

}


template <typename T>
void SeqStack<T>::DispList() //���˳��ջ������Ԫ��
{
	if (IsEmpty())
	{
		return ;
	}
	for (int i = 0; i <= mtop; i++)
	{
		cout << mdata[i] << " ";
	}
	cout << endl;
}



template <typename T>
bool SeqStack<T>::IsEmpty()//�ж�˳��ջ�Ƿ�Ϊ��
{
	if (mtop == -1)
	{
		return true;
	}
	return false;
}

template <typename T>
bool SeqStack<T>::GetTop(T& e)     //��ȡջ��Ԫ�أ�����Ԫ�ز�û�г�ջ����������ջ��
{
	if (IsEmpty())
	{
		return false;
	}
	e = mdata[mtop];
	return true;
}

template <typename T>
bool SeqStack<T>::Pop(T& e)       //��ջ��ɾ�����ݣ���Ҳ����ɾ��ջ������
{
	if (IsEmpty())
	{
		return false;
	}
	e = mdata[mtop];
	mtop--;
	return true;
}
template <typename T>
void SeqStack<T>::IncreaseSize() //��˳��ջ�������ݺ���Ե��ô˺���Ϊ˳��ջ����
{
	T* tmp = mdata;
	mdata = new T[mmaxsize + IncSize];
	for (int i = 0; i <= mtop; i++)
	{
		mdata[i] = tmp[i];
	}
	mmaxsize += IncSize;
	delete[] tmp;
	tmp = nullptr;
}
template <typename T>
bool SeqStack<T>::IsFull()  //�ж�˳��ջ�Ƿ�����
{
	if (mtop == mmaxsize - 1)
	{
		return true;
	}
	return false;
}
template <typename T>
SeqStack<T>::SeqStack(int length)
{
	mdata = new T[length];
	mtop = -1;
	mmaxsize = length;

}
template <typename T>
bool SeqStack<T>::Push(const T& e) //��ջ���������ݣ�
{
	if (IsFull())
	{
		cout<<"ջ����" << endl;
		return false;
	}
	mtop++;
	mdata[mtop] = e;
}
template <typename T>
SeqStack<T>::~SeqStack()
{
	delete[] mdata;
	mdata = nullptr;
	mtop = -1;
	mmaxsize = 0;
}
