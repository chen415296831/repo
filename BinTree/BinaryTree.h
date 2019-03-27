/***********************************************

    Filename: BinaryTree.h
    Author: 
    Description:
    Create Data:    2019-03-27 12:47:40
    Modfiy History: 2019-03-27 12:47:40

***********************************************/

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

    void insert(Type val);
    ~BinaryTree();

private:
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
BinaryTree<Type>::~BinaryTree()
{
}
