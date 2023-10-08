// 队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MaxSize 10
#define IncSize 5

template <typename T>
class SeqQueue
{
public:
	SeqQueue();
	~SeqQueue();
public:
	bool EnQueue(const T& e)//入队列（增加数据）
	{
		if (IsFull())
		{
			return false;
		}
		mdata[mrear++] = e;
		return true;
	}
	bool DeQueue(T& e) //出队列（删除数据）
	{
		if (IsEmpty())
		{
			return false;
		}
		e = mdata[mfront];
		mfront--;
		return true;
	}
	bool GetHead(T& e) //读取对头元素，但元素并没有出队列而是依旧在队列中
	{
		if (IsEmpty())
		{
			return false;
		}
		e = mdata[mfront];
		return true;
	
	}
	void ClearQueue(); //将队列清空

	void DispList(); //输出顺序队列中的所有元素
	int ListLength(); //获取顺序队列的长度（实际拥有的元素数量）

	bool IsEmpty(); //判断顺序队列是否为空
	bool IsFull();  //判断顺序队列是否已满
private:
	T* mdata;
	int mfront;
	int mrear;
};
template <typename T>
SeqQueue<T>::SeqQueue()
{
	mdata = new T[MaxSize];
	mfront = 0;
	mrear = 0;
}
template <typename T>
SeqQueue<T>::~SeqQueue()
{
	delete[] mdata;
}


int main()
{



	return 0;
}
