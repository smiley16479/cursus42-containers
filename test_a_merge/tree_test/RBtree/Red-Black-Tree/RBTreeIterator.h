//
// Red Black Tree Definition
//

#ifndef RED_BLACK_TREE_my_ITERATOR_H
#define RED_BLACK_TREE_my_ITERATOR_H
#include "../../../../colors.h"
// #include "RBTree.h"
#include <unistd.h>

enum Color {E_RED, E_BLACK, E_DOUBLE_BLACK};

struct Node
{
    int data;
    int color;
    Node *left, *right, *parent;

    explicit Node(int);
};

class RBTree
{

    private:
    public:
        typedef RBTree my_iterator;

        Node *root;
    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
        void fixInsertRBTree(Node *&);
        void fixDeleteRBTree(Node *&);
        void inorderBST(Node *&);
        void preorderBST(Node *&);
        int getColor(Node *&);
        void setColor(Node *&, int);
        Node *minValueNode(Node *&);
        Node *maxValueNode(Node *&);
        Node* insertBST(Node *&, Node *&);
        Node* deleteBST(Node *&, int);
        int getBlackHeight(Node *);
    public:
        RBTree();
        RBTree(Node *ptr) : root(ptr){};
        ~RBTree();
        void print2dTree(Node *n, int space = 0);
        void insertValue(int);
        void deleteValue(int);
        void merge(RBTree);
        void inorder();
        void preorder();

        my_iterator begin() {return my_iterator(minValueNode(this->root));}
};


class my_iterator : public RBTree
{
    public:
        Node *_root;
        Node *_null;
    my_iterator() : _root(NULL), _null(NULL) {}
    my_iterator(Node *ptr) : _root(ptr) {}

    my_iterator& operator++() {
		if (_root->right != _null)		//	going down right
			_root = RBTree::minValueNode(_root->right);
		else if (_root == _null || _null->left == _root)
			_root = _root->right;		//	last node or _null case
		else							//	going up
		{
			while (_root->parent != _null && _root == _root->parent->right)
				_root = _root->parent;
			_root = _root->parent;
		}
        return (*this);
    }
    
};

#endif //RED_BLACK_TREE_my_ITERATOR_H
