#include <iostream>

using namespace std;
#define InitSize 10
#define IncSize 5	//����ջ��ʱ���漰����

template <typename T>
class ShareStack
{
public:
	ShareStack(int length = InitSize);
	~ShareStack();
	bool IsFull()
	{
		if (mtop1 == mtop2 - 1)
		{
			return true;
		}
		return false;
	}
	bool Push(int stackNum, const T& e) //��ջ���������ݣ�������stackNum���ڱ�ʾջ1����ջ2
	{
		if (IsFull() )
		{
			return false;
		}
		if (stackNum == 1)
		{
			mtop1++;
			mdata[mtop1] = e;
			return true;
		}
		if (stackNum == 2)
		{
			mtop2--;
			mdata[mtop2] = e;
			return true;
		}
		return false;
	}
	bool Pop(int stackNum, T& e) //��ջ��ɾ�����ݣ���Ҳ����ɾ��ջ������
	{

		if (stackNum == 1)
		{
			if (mtop1 == -1)
			{
				return false;
			}
			e = mdata[mtop1];
			mtop1--;
			return true;
		}
		if (stackNum == 2)
		{
			if (mtop2 == mmaxsize)
			{
				return false;
			}
			e = mdata[mtop2];
			mtop2++;
			return true;

		}
		return false;

	}
private:
	T* mdata;
	int mtop1;
	int mtop2;
	int mmaxsize;
};

template <typename T>
ShareStack<T>::ShareStack(int length )
{
	mdata = new T[length];
	mtop1 = -1;
	mtop2 = length;	//����ջ���漰���ݣ����Բ���mmaxsize
	mmaxsize = length;
}
template <typename T>
ShareStack<T>::~ShareStack()
{
	delete[] mdata;
	mdata = nullptr;
}



int main()
{


	return 0;
}