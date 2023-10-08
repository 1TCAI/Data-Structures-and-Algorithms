// 二叉树遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MaxSize 10


using namespace std;

enum ECCHILDSIGN
{
	ERoot,
	EChildLeft,
	EChildRight
};



template <typename T>
struct Node
{
	T data;
	bool isValid;
};

template <typename T>
class BinaryTree
{
public:
	BinaryTree()
	{
		for (int i = 1; i <= MaxSize; i++)
		{
			Tree[i].isValid = false;
		}
	}
	~BinaryTree() = default;
	int CreateNode(int parindex, ECCHILDSIGN pointSign, const T& e)
	{

		Node <T> newNode;
		newNode.data = e;
		if (pointSign == ERoot)
		{
			Tree[1] = newNode;
			Tree[1].isValid = true;
			return 1;
		}
		if (pointSign == EChildLeft)
		{
			if (!ifValidRangeIdx(parindex))
				return -1;
			if (!Tree[parindex].isValid)
				return -1;
			Tree[parindex*2] = newNode;
			Tree[parindex * 2].isValid = true;
			return parindex * 2;

		}
		if (pointSign == EChildRight)
		{
			if (!ifValidRangeIdx(parindex))
				return -1;
			if (!Tree[parindex].isValid)
				return -1;
			Tree[parindex * 2 + 1] = newNode;
			Tree[parindex * 2 + 1].isValid = true;
			return parindex * 2 + 1;
		}
		return -1;

	}
	int getParentIdx(int sonindex)
	{
		if (!ifValidRangeIdx(sonindex))
			return -1;
		if (!Tree[sonindex].isValid)
			return -1;

		return sonindex / 2;
	}
	int getPointLevel(int index)
	{
		if (!ifValidRangeIdx(index))
			return false;
		if (!Tree[index].isValid)
			return -1;
		return int(log(index) / log(2) + 1);
	}
	int getLevel()
	{
		if (!Tree[1].isValid)
			return -1;
		int i = MaxSize;
		for (; i >= 1; i--)
		{
			if (Tree[i].isValid)
			{
				break;
			}
		}
		return getPointLevel(i);
	}
	bool ifComplateBT()
	{
		if (!Tree[1].isValid)
			return -1;
		int i = MaxSize;
		for (; i >= 1; i--)
		{
			if (Tree[i].isValid)
				break;
		}
		for (int k = 1; k <= i; k++)
		{
			if (Tree[k].isValid == false)
				return false;
		}
		return true;
	}
	void preOrder()
	{
		if (!Tree[1].isValid)
			return ;
		preOrder(1);
		cout << endl;
	}
	void preOrder(int index)
	{
		if (!ifValidRangeIdx(index))
			return;
		if (!Tree[index].isValid)
			return;

		cout << Tree[index].data<<" ";
		preOrder(2*index);
		preOrder(2*index + 1);
	}
private:
	bool ifValidRangeIdx(int index)
	{
		if (index > MaxSize ||index <= 0)
		{
			return false;
		}
		return true;	
	}
	Node<T> Tree[MaxSize + 1];
};







int main()
{


	BinaryTree<int> tree;
	int num1 = tree.CreateNode(1,ERoot,1);
	int num2 = tree.CreateNode(num1,EChildLeft,2);
	int num3 = tree.CreateNode(num1,EChildRight,3);
	tree.CreateNode(num2, EChildLeft, 4);
	tree.CreateNode(num2, EChildRight, 5);
	tree.CreateNode(num3, EChildLeft, 6);
	tree.CreateNode(num3, EChildRight, 7);
	tree.preOrder();
	cout<<tree.getPointLevel(5);
	return 0;
}

