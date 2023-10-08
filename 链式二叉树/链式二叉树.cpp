// 链式二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include <stack>
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
	Node<T>* left;
	Node<T>* right;
}; 
template <typename T>
class Tree
{
public:
	Tree()
	{
		mroot = nullptr;
	}
	~Tree()
	{
		ReleaseNode(mroot);
	}
	void preOrder()
	{
		preOrder(mroot);
		cout << endl;
	}
	void preOrder(Node<T>* pnode)
	{
		if (pnode == nullptr)
			return;
		cout << pnode->data << " ";
		preOrder(pnode->left);
		preOrder(pnode->right);
	}

	Node<T>* CreateNode(Node<T>* parentnode, ECCHILDSIGN pointSign, const T& e)
	{
		if (pointSign == ERoot)
		{
			if (mroot != nullptr)
				return nullptr;
			Node<T>* newNode = new Node<T>;
			newNode->left = nullptr;
			newNode->right = nullptr;
			newNode->data = e;
			mroot = newNode;
			return mroot;
		}
		if (pointSign == EChildLeft)
		{
			if (parentnode == nullptr)
				return nullptr;
			if (parentnode->left != nullptr)
				return nullptr;
			Node<T>* newNode = new Node<T>;
			newNode->left = nullptr;
			newNode->right = nullptr;
			newNode->data = e;
			parentnode->left = newNode;
			return newNode;
		}
		if (pointSign == EChildRight)
		{
			if (parentnode == nullptr)
				return nullptr;
			if (parentnode->right != nullptr)
				return nullptr;
			Node<T>* newNode = new Node<T>;
			newNode->left = nullptr;
			newNode->right = nullptr;
			newNode->data = e;
			parentnode->right = newNode;
			return newNode;
		}
		return nullptr;
	}

	void ReleaseNode(Node<T>* pnode)
	{
		if (pnode == nullptr)
			return;
		ReleaseNode(pnode->left);
		ReleaseNode(pnode->right);
		delete pnode;
		pnode = nullptr;
	}

	void inOrder()
	{
		inOrder(mroot);
		cout << endl;
	}
	void inOrder(Node<T>* pnode)
	{
		if (pnode == nullptr)
			return;
		inOrder(pnode->left);
		cout<<pnode->data<<" ";
		inOrder(pnode->right);
	}
	void postOrder()
	{
		postOrder(mroot);
		cout << endl;
	}
	void postOrder(Node<T>* pnode)
	{
		if (pnode == nullptr)
			return;
		postOrder(pnode->left);
		postOrder(pnode->right);
		cout << pnode->data << " ";
	}
	void levelOrder()
	{
		levelOrder(mroot);
		cout << endl;
	}
	void levelOrder(Node<T>* pnode)
	{
		if (pnode == nullptr)
			return;
		Node <T>* tmp;
		queue<Node <T>* > qnode;
		qnode.push(pnode);
		while (!qnode.empty())
		{
			tmp = qnode.front();
			cout<<tmp->data<<" ";
			qnode.pop();
			if (tmp->left == nullptr && tmp->right != nullptr)
			{
				cout<<"非完全二叉树" ;
			}
			if (tmp->left != nullptr)
				qnode.push(tmp->left);
			if (tmp->right != nullptr)
				qnode.push(tmp->right);
		}
	}
	int getSize()
	{
		int num = 0;
		return getSize(mroot, num);
	}
	int getSize(Node<T>* pnode, int &num)
	{

		if (pnode == nullptr)
			return 0;
		num++;
		getSize(pnode->left, num);
		getSize(pnode->right, num);
		return num;
	}
	int getHeight()
	{
		return getHeight(mroot);
	}
	int getHeight(Node<T>* pnode)
	{
		if (pnode == nullptr )
			return 0;
		int lheight = getHeight(pnode->left);
		int rheight = getHeight(pnode->right);
		if (lheight > rheight)
			return lheight + 1;
		return rheight + 1;
	}

	Node<T>* SearchElem(const T& e)
	{
		return SearchElem(mroot, e);
	}
	Node<T>* SearchElem(Node<T>* pnode, const T& e)
	{
		if (pnode == nullptr)
			return nullptr;


		if (pnode->data == e)
			return pnode;
		Node<T>* p = SearchElem(pnode->left, e);
		if (p != nullptr)
			return p;
		return SearchElem(pnode->right, e);

	}

	Node<T>* GetParent(Node<T>* tSonNode)
	{
		return GetParent(mroot, tSonNode);
	}

	Node<T>* GetParent(Node<T>* parentNode, Node<T>* tSonNode)
	{
		if (parentNode == nullptr || tSonNode == nullptr)
		{
			return nullptr;
		}
		if (parentNode->left == tSonNode || parentNode->right == tSonNode)
		{
			return parentNode;
		}
		Node<T>* p1 = GetParent(parentNode->left,tSonNode);
		if (p1 != nullptr)
		{
			return p1;
		}
		Node<T>* p2 = GetParent(parentNode->right,tSonNode);
		if (p2 != nullptr)
		{
			return p2;
		}
	}
	//扩展二叉树前序遍历进行创建树。
	void CreateBTreeAccordPT(char * pstr)
	{
		CreateBTreeAccordPT(mroot,pstr);
	}

	void CopyTree(Tree<T>* targetTree)
	{
		CopyTree(mroot, targetTree->mroot);
	}
	void CopyTree(Node<T>* sourceTree, Node<T>* &target)
	{
		if (sourceTree == nullptr)
		{
			target = nullptr;
		}
		else
		{
			target = new Node<T>;
			target->data = sourceTree->data;
			CopyTree(sourceTree->left, target->left);
			CopyTree(sourceTree->right, target->right);
		}
	}
	void preOrder_noRecu()
	{
		preOrder_noRecu(mroot);
		cout << endl;
	}
	void preOrder_noRecu(Node<T>* pnode)
	{
		if (pnode == nullptr)
		{
			return;
		}
		stack<Node<T>*> qnode;
		qnode.push(pnode);
		Node<T>* tmp;
		while (!qnode.empty())
		{
			tmp = qnode.top();
			cout << tmp->data << " ";
			qnode.pop();
			if (tmp->right != nullptr)
				qnode.push(tmp->right);
			if (tmp->left != nullptr)
				qnode.push(tmp->left);
		}
	}

	void inOrder_noRecu()
	{
		inOrder_noRecu(mroot);
		cout << endl;
	}
	void inOrder_noRecu(Node<T>* pnode)
	{
		if (pnode == nullptr)
		{
			return;
		}
		stack<Node<T>*> qnode;
			qnode.push(pnode);
		Node<T>* tmp;
		while (!qnode.empty())
		{
			while (pnode->left != nullptr)
			{
				qnode.push(pnode->left);
				pnode = pnode->left;
			}
			tmp = qnode.top();
			cout << tmp->data << " ";
			qnode.pop();
			if (tmp->right != nullptr)
			{
				pnode = tmp->right;
				qnode.push(pnode);
			}
		}
	}
	void CreateBTreeAccordPI(char *pp, char * pi)
	{
		CreateBTreeAccordPI(mroot, pp ,pi,strlen(pp));
	}
												//前序 中序 节点个数
	void CreateBTreeAccordPI(Node<T>* &pnode, char* pp, char* pi,int n)
	{
		if (n == 0)
		{
			pnode = nullptr ;
		}
		else
		{
			int index = 0;
			while (pp[0] != pi[index])
				index++;
			pnode = new Node<T>;
			pnode->data = pi[index];

			CreateBTreeAccordPI(pnode->left, pp + 1, pi, index);
			CreateBTreeAccordPI(pnode->right, pp + 1 + index, pi + 1 + index, n - index - 1);
		}

	}
	void CreateBTreeAccordIP(char* pi, char* ppost)
	{
		CreateBTreeAccordIP(mroot,pi,ppost , strlen(ppost));
	}

											//中序 后序 节点个数
	void CreateBTreeAccordIP(Node<T>*& pnode, char* pi, char* ppost, int n)
	{
		if (n == 0)
		{
			pnode = nullptr;
		}
		else
		{
			pnode = new Node<T>;
			int index = 0;
			while (ppost[n-1] != pi[index])
			{
				index++;
			}
			pnode->data = pi[index];
			CreateBTreeAccordIP(pnode->left,pi,ppost,index);
			CreateBTreeAccordIP(pnode->right,pi+index+1,ppost+index,n-index-1);
		}
	}










private:		//不加引用只对指针的值改变，加引用还可以对地址进行改变		
	void CreateBTreeAccordPT(Node<T>*& tnode, char*& pstr)
	{
		if (*pstr == '#')
		{
			tnode = nullptr;
		}
		else
		{
			tnode = new Node<T>;
			tnode->data = *pstr;
			CreateBTreeAccordPT(tnode->left,++pstr);
			CreateBTreeAccordPT(tnode->right,++pstr);
		}

	}
private:
	Node<T>* mroot;
};






int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口

	//Tree<int> mytree;
	//Node<int>* root = mytree.CreateNode(nullptr,ERoot,1);
	//Node<int>* left1 = mytree.CreateNode(root,EChildLeft,2);
	//Node<int>* right1 = mytree.CreateNode(root,EChildRight,3);
	//Node<int>* left2 = mytree.CreateNode(left1, EChildLeft, 4);
	//Node<int>* right2 = mytree.CreateNode(left1,EChildRight,5);
	//Node<int>* left3 = mytree.CreateNode(right1, EChildLeft, 6);
	//Node<int>* right3 = mytree.CreateNode(right1, EChildRight, 7);
	////mytree.preOrder();
	////mytree.inOrder();
	////mytree.postOrder();
	////mytree.levelOrder();
	////cout<<mytree.getSize() << endl;;
	////cout<<mytree.getHeight() << endl;;
	//

	////Node<int>* tmp = mytree.GetParent(right2);
	////cout << tmp->data << endl;
	////Tree<char> mytree2;
	////mytree2.CreateBTreeAccordPT((char *)"ABD###C#E##");
	////mytree2.preOrder();

	//mytree.preOrder_noRecu();
	//mytree.inOrder_noRecu();


	Tree<char> mytree;
	//char* p1 = (char *)"ABDECFG";
	//char* p2 = (char*)"DBEAFCG";
	//cout<<strlen(p1)<<endl;
	mytree.CreateBTreeAccordIP((char*)"DBEAFCG", (char*)"DEBFGCA");
	mytree.inOrder();

	return 0;
}



