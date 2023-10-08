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

	bool Push(const T& e); //入栈（增加数据）
	bool Pop(T& e);        //出栈（删除数据），也就是删除栈顶数据
	bool GetTop(T& e);     //读取栈顶元素，但该元素并没有出栈而是依旧在栈中

	void DispList(); //输出顺序栈中所有元素
	int ListLength(); //获取顺序栈的长度（实际拥有的元素数量）

	bool IsEmpty(); //判断顺序栈是否为空
	bool IsFull();  //判断顺序栈是否已满
private:
	void IncreaseSize(); //当顺序栈存满数据后可以调用此函数为顺序栈扩容

private:
	T* mdata;
	int mtop;
	int mmaxsize;
};

template <typename T>
int SeqStack<T>::ListLength() //获取顺序栈的长度（实际拥有的元素数量）
{
	return mtop + 1;

}


template <typename T>
void SeqStack<T>::DispList() //输出顺序栈中所有元素
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
bool SeqStack<T>::IsEmpty()//判断顺序栈是否为空
{
	if (mtop == -1)
	{
		return true;
	}
	return false;
}

template <typename T>
bool SeqStack<T>::GetTop(T& e)     //读取栈顶元素，但该元素并没有出栈而是依旧在栈中
{
	if (IsEmpty())
	{
		return false;
	}
	e = mdata[mtop];
	return true;
}

template <typename T>
bool SeqStack<T>::Pop(T& e)       //出栈（删除数据），也就是删除栈顶数据
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
void SeqStack<T>::IncreaseSize() //当顺序栈存满数据后可以调用此函数为顺序栈扩容
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
bool SeqStack<T>::IsFull()  //判断顺序栈是否已满
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
bool SeqStack<T>::Push(const T& e) //入栈（增加数据）
{
	if (IsFull())
	{
		cout<<"栈已满" << endl;
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
