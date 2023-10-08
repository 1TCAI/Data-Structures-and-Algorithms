#include <iostream>

using namespace std;
#define InitSize 10
#define IncSize 5	//共享栈暂时不涉及扩容

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
	bool Push(int stackNum, const T& e) //入栈（增加数据），参数stackNum用于表示栈1还是栈2
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
	bool Pop(int stackNum, T& e) //出栈（删除数据），也就是删除栈顶数据
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
	mtop2 = length;	//共享栈不涉及扩容，所以不是mmaxsize
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