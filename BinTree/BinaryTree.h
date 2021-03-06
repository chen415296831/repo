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

	template<typename Unary>
	void RecrPreTrav(Unary& fun);
	template<typename Unary>
	void RecrMidTrav(Unary& fun);
	template<typename Unary>
	void RecrNxtTrav(Unary& fun);
	void PreTrav();
	void MidTrav();
	void NxtTrav();

    void insert(Type val);
    ~BinaryTree();

private:
	template<typename Unary>
	void RecrPreTravNode(NodePtr ptr, Unary& fun)
	{
		if(!ptr) return;
		//std::cout << ptr->vaule <<'\t';
		fun(ptr->vaule);
		RecrPreTravNode(ptr->leftChild, fun);
		RecrPreTravNode(ptr->rightChild, fun);
	}
	template<typename Unary>
	void RecrMidTravNode(NodePtr ptr, Unary& fun)
	{
		if(!ptr) return;
		RecrMidTravNode(ptr->leftChild, fun);
		fun(ptr->vaule);
		//std::cout << ptr->vaule <<'\t';
		RecrMidTravNode(ptr->rightChild, fun);
	}

	template<typename Unary>
	void RecrNxtTravNode(NodePtr ptr, Unary& fun)
	{
		if(!ptr) return;
		RecrNxtTravNode(ptr->leftChild, fun);
		RecrNxtTravNode(ptr->rightChild, fun);
		//std::cout << ptr->vaule <<'\t';
		fun(ptr->vaule);
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
template<typename Unary>
void BinaryTree<Type>::RecrPreTrav( Unary& fun)
{
	RecrPreTravNode(Root_, fun);
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

        cur = track.top();
        track.pop();

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
    NodePtr lastTrav = nullptr;

	while( cur || !track.empty())
	{
		if(cur)
		{
			track.push(cur);
			cur = cur->leftChild;
			continue;
		}


        if(track.top()->rightChild && lastTrav != track.top()->rightChild)
        {
            track.push(track.top()->rightChild);
            cur = track.top()->leftChild;
        }
        else
        {
            lastTrav = track.top();
            track.pop();
            std::cout << lastTrav->vaule << '\t';
        }
	}
	std::cout << '\n';
}

template<typename Type>
template<typename Unary>
void BinaryTree<Type>::RecrMidTrav(Unary& fun)
{
	RecrMidTravNode(Root_, fun);
	std::cout << '\n';
}
template<typename Type>
template<typename Unary>
void BinaryTree<Type>::RecrNxtTrav( Unary& fun)
{
	RecrNxtTravNode(Root_, fun);
	std::cout << '\n';
}

template<typename Type>
BinaryTree<Type>::~BinaryTree()
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

        cur = track.top()->rightChild;

		delete track.top();
		track.pop();
	}
}
