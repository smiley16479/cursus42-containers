#include <unistd.h>
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"

struct Node {
	bool isRed;
	int data;
	Node *left;
	Node *right;
	Node *parent;
};

class RBTree {
	public:

	void leftRotate(Node *n);
	void rightRotate(Node *n);
	Node *getParent(Node *n);
	Node *getGrandParent(Node *n);
	Node *getSibling(Node *n);
	Node *getUncle(Node *n);
	Node *initNd(Node *n, int data);
	Node *getRoot(Node *n);
	bool getColor(Node *n);
	void setColor(Node *n, bool color);
	void fixInsertRBTree(Node *&ptr);
	Node *insert(Node *root, Node *n);
	void RBinsertFixup(Node *root, Node *n);
	void insertYoutube(Node *root, Node *n);
	// void leftRotate(Node *n);
	// void rightRotate(Node *n);
	void print2dTree(Node *n, int space);

	private:
	Node* _root;
};

void leftRotate(Node *n);
void rightRotate(Node *n);
void test_left_right_Rotation();
void test_insert_fix();

// Helper function 
Node *getParent(Node *n)
{
	if (n)
		return (n->parent);
	return NULL;
}

Node *getGrandParent(Node *n)
{
	if (n && n->parent)
		return (n->parent->parent);
	return NULL;
}

Node *getSibling(Node *n)
{
	if (n && n->parent)
		if (n->parent->right == n)
			return (n->parent->left);
		else
			return (n->parent->right);
	return NULL;
}

Node *getUncle(Node *n)
{
	Node *g = getGrandParent(n);
	if (n && n->parent && g)
		if (n->parent == g->right)
			return (g->left);
		else
			return (g->right);
	return NULL;
}

Node *initNd(Node *n, int data)
{
	n->isRed = true;
	n->data  = data;
	n->right = n->left = n->parent = NULL;
	return n;
}

Node *getRoot(Node *n)
{
	while ( n->parent )
		n = n->parent;
	return n;
}

bool getColor(Node *n) {return n->isRed;}
Node * setColor(Node *n, bool color) {n->isRed = color; return n;}

void /* RBTree:: */fixInsertRBTree(Node *&ptr/*, Node *_root  */) {
    Node *parent = NULL;
    Node *grandparent = NULL;
    while (ptr != getRoot(ptr)/* _root */ && getColor(ptr) == 1 && getColor(ptr->parent) == 1) {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;
            if (getColor(uncle) == 1) {
                setColor(uncle, 0);
                setColor(parent, 0);
                setColor(grandparent, 1);
                ptr = grandparent;
            } else {
                if (ptr == parent->right) {
                    leftRotate(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rightRotate(grandparent);
                std::swap(parent->isRed, grandparent->isRed);
                ptr = parent;
            }
        } else {
            Node *uncle = grandparent->left;
            if (getColor(uncle) == 1) {
                setColor(uncle, 0);
                setColor(parent, 0);
                setColor(grandparent, 1);
                ptr = grandparent;
            } else {
                if (ptr == parent->left) {
                    rightRotate(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                leftRotate(grandparent);
                std::swap(parent->isRed, grandparent->isRed);
                ptr = parent;
            }
        }
    }
    setColor(getRoot(ptr)/* _root */, 0);
}

void insert(Node *root, Node *n)
{
	if (!root) {
		n->isRed =false;
		return /* (n) */;
	}
	while (root)
		if (n->data > root->data && root->right)
			root = root->right;
		else if (n->data > root->data) {
			root->right = n;
			n->parent = root;
			return /* getRoot (n) */;
		}
		else if (n->data < root->data && root->left)
			root = root->left;
		else if (n->data < root->data) {
			root->left = n;
			n->parent = root;
			return /* getRoot (n) */;
		}
		else std::cout << "(insert) You should have never hit this!\n";
	return /* (NULL) */fixInsertRBTree(n/* , getRoot(n) */);
}

void RBinsertFixup(Node *root, Node *n)
{
	Node *y = NULL;
	while (n->parent->isRed == true)
		if (n->parent == n->parent->parent->left){
			y = n->parent->parent->right;
			if (y->isRed == true) {
				n->parent->isRed = false;				// case 1
				y->isRed = false;						// case 1
				n->parent->parent->isRed = true;		// case 1
				n = n->parent->parent;					// case 1
			}
			else {
				if (n == n->parent->right) {
					n = n->parent;						// case 2
					leftRotate(n);						// case 2
				}
				n->parent->isRed = false;				// case 3
				n->parent->parent->isRed = true;		// case 3
				rightRotate(n->parent->parent);//n		// case 3
			}
		}
		else {
			y = n->parent->parent->left;
			if (y->isRed == true) {
				n->parent->isRed = false;
				y->isRed = false;
				n->parent->parent->isRed = true;
				n = n->parent->parent;
			}
			else	{
				if (n == n->parent->left) {
					n = n->parent;
					rightRotate(n);
				}
			n->parent->isRed = false;
			n->parent->parent->isRed = true;
			leftRotate(n->parent->parent);//n
			}
		}
		root->isRed = false;							// case 0
}

void insertYoutube(Node *root, Node *n)
{
	// n->parent = NULL; // ds l'example Java

	Node *y = NULL;
	Node *x = root;

	if (!root) {
		n->isRed =false;
		return ;
	}


	while (x != NULL)
	{
		y = x;
		if (n->data < x->data)
			x = x->left;
		else x = x->right;
	}
	n->parent = y;
	if (y == NULL)
		root = n;
	else if (n->data < y->data)
		y->left = n;
	else y->right = n;
	n->left = NULL;
	n->right = NULL;
	n->isRed = true;
	RBinsertFixup(root, n);
}


void leftRotate(Node *n)
{
	if (!n || !n->right) {
		std::cout << "il n'y a pas de fils droit from(leftrotate)\n";
		return ;
	}
	n->right->parent = n->parent;
	if (n->parent)
		if (n->parent->right == n)
			n->parent->right = n->right;
		else
			n->parent->left = n->right;
//  (2)
	n->parent = n->right;
	if (n->right && n->right->left)
		n->right->left->parent = n;
	if (n->right)
		n->right = n->right->left;
	n->parent->left = n;
}

void rightRotate(Node *n)
{
	if (!n | !n->left) {
		std::cout << "il n'y a pas de fils gauche from(rightrotate)\n";
		return ;
	}
	n->left->parent = n->parent;
	if (n->parent)
		if (n->parent->right == n)
			n->parent->right = n->left;
		else
			n->parent->left = n->left;
//	(2)
	n->parent = n->left;
	if (n->left && n->left->right)
		n->left->right->parent = n;
	if (n->left)
		n->left = n->left->right;
	n->parent->right = n;
	return ;
}


void print2dTree(Node *n, int space) {
	if (n == NULL)
		return ;
	space += 5;
	print2dTree(n->right, space);
	std::cout << std::endl;
	for (int i = 5; i < space; ++i)
		std::cout << " ";
	n->isRed ? std::cout << RED << n->data << RESET << std::endl : std::cout << n->data << std::endl;
	print2dTree(n->left, space);
}

int main()
{
	// test_left_right_Rotation();
	test_insert_fix();
}

void test_insert_fix_YOUTUBE()
{
	Node a{true, 1, NULL, NULL, NULL};
	Node b{true, 2, NULL, NULL, NULL};
	Node c{true, 3, NULL, NULL, NULL};
	Node d{true, 8, NULL, NULL, NULL};
	Node e{true, 16, NULL, NULL, NULL};
	insertYoutube(NULL, &b);
	insertYoutube(getRoot(&b), &d);
	insertYoutube(getRoot(&b), &c);
	insertYoutube(getRoot(&b), &e);
	insertYoutube(getRoot(&b), &a);
	print2dTree(getRoot(&b), 0);

}

void test_insert_fix()
{
	Node a{true, 1, NULL, NULL, NULL};
	Node b{true, 2, NULL, NULL, NULL};
	Node c{true, 3, NULL, NULL, NULL};
	Node d{true, 8, NULL, NULL, NULL};
	Node e{true, 16, NULL, NULL, NULL};

	insert(NULL, &b);
	insert(getRoot(&b), &d);
	insert(getRoot(&b), &c);
	insert(getRoot(&b), &e);
	insert(getRoot(&b), &a);
	print2dTree(getRoot(&b), 0);

}

void test_left_right_Rotation()
{
	Node a{true, 1, NULL, NULL, NULL};
	Node b{true, 2, NULL, NULL, NULL};
	Node c{true, 3, NULL, NULL, NULL};
	Node d{true, 8, NULL, NULL, NULL};
	Node e{true, 16, NULL, NULL, NULL};
	// Node f{true, 32, NULL, NULL, NULL};
	// Node g{true, 10, NULL, NULL, NULL};

	insert(NULL, &b);
	insert(getRoot(&b), &d);
	insert(getRoot(&b), &c);
	insert(getRoot(&b), &e);
	insert(getRoot(&b), &a);
	// insert(getRoot(&b), &f);
	// insert(getRoot(&f), &g);
// 
	print2dTree(getRoot(&b), 0);
	leftRotate(&b);
	std::cout << "------" << std::endl;
	print2dTree(getRoot(&b), 0);
	leftRotate(&d);
	std::cout << "------" << std::endl;
	print2dTree(getRoot(&b), 0);
	leftRotate(&e);

	rightRotate(&e);
	std::cout << "------" << std::endl;
	print2dTree(getRoot(&b), 0);
	rightRotate(&d);
	std::cout << "------" << std::endl;
	print2dTree(getRoot(&b), 0);
	rightRotate(&b);
	std::cout << "------" << std::endl;
	print2dTree(getRoot(&b), 0);
	rightRotate(&a);

	return ;
}