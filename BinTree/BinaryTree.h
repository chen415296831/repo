/***********************************************

    Filename: BinaryTree.h
    Author: 
    Description:
    Create Data:    2019-03-27 12:47:40
    Modfiy History: 2019-03-27 12:47:40

***********************************************/
#include <iostream>
#include <stack>

template<typename Type>
struct TreeNode
{
    TreeNode()
        :leftChild(nullptr),rightChild(nullptr), vaule(0)
    {}
    TreeNode(Type& v)
        :leftChild(nullptr),rightChild(nullptr), vaule(v)
    {}
    typedef struct TreeNode<Type>* TreeNodePtr;
    TreeNodePtr leftChild;
    TreeNodePtr rightChild;
    Type vaule;
    
    bool isLeaf()
    {
        return leftChild == nullptr && rightChild == nullptr;
    }

    bool hasLeftChild()
    {
        return leftChild != nullptr;
    }

    bool hasRightChild()
    {
        return rightChild != nullptr;
    }

    bool hasTwoChilds()
    {
        return leftChild != nullptr && rightChild != nullptr;
    }
};

void Seed();
int Guide();

template<typename Type>
class BinaryTree
{
public:
    typedef TreeNode<Type> NodeType;
    typedef typename TreeNode<Type>::TreeNodePtr NodePtr;
    typedef unsigned long SizeType;

    BinaryTree()
        :Root_(nullptr),Heigth_(0), Size_(0)
    {}

	void RecrPreTrav();
	void RecrMidTrav();
	void RecrNxtTrav();
	void PreTrav();
	void MidTrav();
	void NxtTrav();

    void insert(Type val);
    ~BinaryTree();

private:
	void RecrPreTravNode(NodePtr ptr)
	{
		if(!ptr) return;
		std::cout << ptr->vaule <<'\t';
		RecrPreTravNode(ptr->leftChild);
		RecrPreTravNode(ptr->rightChild);
	}
	void RecrMidTravNode(NodePtr ptr)
	{
		if(!ptr) return;
		RecrPreTravNode(ptr->leftChild);
		std::cout << ptr->vaule <<'\t';
		RecrPreTravNode(ptr->rightChild);
	}

	void RecrNxtTravNode(NodePtr ptr)
	{
		if(!ptr) return;
		RecrPreTravNode(ptr->leftChild);
		RecrPreTravNode(ptr->rightChild);
		std::cout << ptr->vaule <<'\t';
	}

NodePtr     Root_;
SizeType    Heigth_;
SizeType    Size_; 
};

template<typename Type>
void BinaryTree<Type>::insert (Type val)
{
    if(Root_ == nullptr)
    {
        Root_ = new NodeType(val);
    }
    else
    {
        NodePtr root = Root_;
        while(1)
        {
            if(Guide())
            {
                if(root->leftChild == nullptr)
                {
                    root->leftChild = new NodeType(val);
                    break;
                }
                else
                {
                    root = root->leftChild;
                }
            }
            else
            {
                if(root->rightChild == nullptr)
                {
                    root->rightChild = new NodeType(val);
                    break;
                }
                else
                {
                    root = root->rightChild;
                }
            }
        }
    }
}

template<typename Type>
void BinaryTree<Type>::RecrPreTrav()
{
	RecrPreTravNode(Root_);
	std::cout << '\n';
}

template<typename Type>
void BinaryTree<Type>::PreTrav()
{
	std::stack<NodePtr> track;
	NodePtr cur = Root_;
	while(cur || !track.empty()) //只要当前节点访问，或者栈不为空，就一直访问
	{
		if(!cur)  //当前访问的节点是nullpltr，但是栈中还保存着未访问的节点，出栈访问它们
		{
			cur = track.top();
			track.pop();
			continue;
		}

		std::cout << cur->vaule << '\t';
		if(cur->rightChild) track.push(cur->rightChild);
		cur = cur->leftChild;
	}
	std::cout << '\n';
}
template<typename Type>
void BinaryTree<Type>::MidTrav()
{
	std::stack<NodePtr> track;
	NodePtr cur = Root_;
	while(cur || !track.empty()) //只要当前节点访问，或者栈不为空，就一直访问
	{
		if(cur) 
		{
			track.push(cur);
			cur = cur->leftChild;
			continue;
		}
		else
		{
			cur = track.top();
			track.pop();
		}

		//到这里，说明一直向左，终于没有了左孩子
		std::cout << cur->vaule << '\t';
		//开始访问右孩子
		cur = cur->rightChild;
	}
	std::cout << '\n';
}
template<typename Type>
void BinaryTree<Type>::NxtTrav()
{
	std::stack<NodePtr> track;
	NodePtr cur = Root_;

	while( cur || !track.empty())
	{
		if(cur)
		{
			track.push(cur);
			cur = cur->leftChild;
			continue;
		}
		else
		{
			cur = track.top();
			track.pop();
		}
		//到这里，说明一直向左，终于没有了左孩子
		std::cout << cur->vaule << '\t';

		if(cur->rightChild)
		{
			cur = cur->rightChild;
		}
		else
		{
			cur = track.top()->rightChild;
		}
	}
	std::cout << '\n';
}

template<typename Type>
void BinaryTree<Type>::RecrMidTrav()
{
	RecrMidTravNode(Root_);
	std::cout << '\n';
}
template<typename Type>
void BinaryTree<Type>::RecrNxtTrav()
{
	RecrNxtTravNode(Root_);
	std::cout << '\n';
}

template<typename Type>
BinaryTree<Type>::~BinaryTree()
{
}
