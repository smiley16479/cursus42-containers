//
// E_RED E_BLACK Tree Implementation
//
#include <bits/stdc++.h>
#include "RBTree.h"
using namespace std;

Node *getRoot(Node *n)
{
	while ( n->parent )
		n = n->parent;
	return n;
}

Node::Node(int data) {
    this->data = data;
    color = E_RED;
    left = right = parent = NULL;
}

RBTree::RBTree() {
    root = NULL;
}

int RBTree::getColor(Node *&node) {
    if (node == NULL)
        return E_BLACK;
    return node->color;
}

void RBTree::deleteTree(Node *ptr)
{
    if (ptr){
    deleteTree(ptr->left);
    deleteTree(ptr->right);
    delete ptr;}
}

RBTree::~RBTree() {
    deleteTree(root);
}


void RBTree::setColor(Node *&node, int color) {
    if (node == NULL)
        return;

    node->color = color;
}

Node* RBTree::insertBST(Node *&root, Node *&ptr) {
    if (root == NULL)
        return ptr;

    if (ptr->data < root->data) {
        root->left = insertBST(root->left, ptr);
        root->left->parent = root;
    } else if (ptr->data > root->data) {
        root->right = insertBST(root->right, ptr);
        root->right->parent = root;
    }
    return root;
}

void RBTree::insertValue(int n) {
    Node *node = new Node(n);
    std::cout << "root : " << root << " vs getRoot() : " << getRoot(node) << " node inséré : " << node << std::endl;
    root = insertBST(root, node);
    std::cout << "root : " << root << " vs getRoot() : " << getRoot(node) << " node inséré : " << node << std::endl;
    fixInsertRBTree(node);
    print2dTree(getRoot(node));
}

/* void RBTree::rotateLeft(Node *&ptr) {
    Node *right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != NULL)
        ptr->right->parent = ptr;

    right_child->parent = ptr->parent;

    if (ptr->parent == NULL)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;

    right_child->left = ptr;
    ptr->parent = right_child;
}

void RBTree::rotateRight(Node *&ptr) {
    Node *left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != NULL)
        ptr->left->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent == NULL)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;

    left_child->right = ptr;
    ptr->parent = left_child;
} */

void RBTree::rotateLeft(Node *&n/* , Node *&root */)
{
	if (!n || !n->right) {
		std::cout << "il n'y a pas de fils droit from(leftrotate)\n";
		return ;
	}
	n->right->parent = n->parent;
    if (n->parent == NULL)  // <- ici était le souci
        root = n->right;    // <- ici était le souci
	else if (n->parent->right == n)
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

void RBTree::rotateRight(Node *&n/* , Node *&root */)
{
	if (!n | !n->left) {
		std::cout << "il n'y a pas de fils gauche from(rightrotate)\n";
		return ;
	}
	n->left->parent = n->parent;
    if (n->parent == NULL)      // <- ici était le souci
        root = n->left;         // <- ici était le souci
	else if (n->parent->right == n)
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

void RBTree::fixInsertRBTree(Node *&ptr) {
    Node *parent = NULL;
    Node *grandparent = NULL;
    while (ptr != getRoot(ptr)/* root */ && getColor(ptr) == E_RED && getColor(ptr->parent) == E_RED) {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;
            if (getColor(uncle) == E_RED) {
                setColor(uncle, E_BLACK);
                setColor(parent, E_BLACK);
                setColor(grandparent, E_RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->right) {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        } else {
            Node *uncle = grandparent->left;
            if (getColor(uncle) == E_RED) {
                setColor(uncle, E_BLACK);
                setColor(parent, E_BLACK);
                setColor(grandparent, E_RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->left) {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    Node *_ptr = getRoot(ptr);
    setColor(_ptr/* root */, E_BLACK);
}

void RBTree::fixDeleteRBTree(Node *&node) {
    if (node == NULL)
        return;

    if (node == root) {
        root = NULL;
        return;
    }

    if (getColor(node) == E_RED || getColor(node->left) == E_RED || getColor(node->right) == E_RED) {
        Node *child = node->left != NULL ? node->left : node->right;

        if (node == node->parent->left) {
            node->parent->left = child;
            if (child != NULL)
                child->parent = node->parent;
            setColor(child, E_BLACK);
            delete (node);
        } else {
            node->parent->right = child;
            if (child != NULL)
                child->parent = node->parent;
            setColor(child, E_BLACK);
            delete (node);
        }
    } else {
        Node *sibling = NULL;
        Node *parent = NULL;
        Node *ptr = node;
        setColor(ptr, E_DOUBLE_BLACK);
        while (ptr != root && getColor(ptr) == E_DOUBLE_BLACK) {
            parent = ptr->parent;
            if (ptr == parent->left) {
                sibling = parent->right;
                if (getColor(sibling) == E_RED) {
                    setColor(sibling, E_BLACK);
                    setColor(parent, E_RED);
                    rotateLeft(parent);
                } else {
                    if (getColor(sibling->left) == E_BLACK && getColor(sibling->right) == E_BLACK) {
                        setColor(sibling, E_RED);
                        if(getColor(parent) == E_RED)
                            setColor(parent, E_BLACK);
                        else
                            setColor(parent, E_DOUBLE_BLACK);
                        ptr = parent;
                    } else {
                        if (getColor(sibling->right) == E_BLACK) {
                            setColor(sibling->left, E_BLACK);
                            setColor(sibling, E_RED);
                            rotateRight(sibling);
                            sibling = parent->right;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, E_BLACK);
                        setColor(sibling->right, E_BLACK);
                        rotateLeft(parent);
                        break;
                    }
                }
            } else {
                sibling = parent->left;
                if (getColor(sibling) == E_RED) {
                    setColor(sibling, E_BLACK);
                    setColor(parent, E_RED);
                    rotateRight(parent);
                } else {
                    if (getColor(sibling->left) == E_BLACK && getColor(sibling->right) == E_BLACK) {
                        setColor(sibling, E_RED);
                        if (getColor(parent) == E_RED)
                            setColor(parent, E_BLACK);
                        else
                            setColor(parent, E_DOUBLE_BLACK);
                        ptr = parent;
                    } else {
                        if (getColor(sibling->left) == E_BLACK) {
                            setColor(sibling->right, E_BLACK);
                            setColor(sibling, E_RED);
                            rotateLeft(sibling);
                            sibling = parent->left;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, E_BLACK);
                        setColor(sibling->left, E_BLACK);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        if (node == node->parent->left)
            node->parent->left = NULL;
        else
            node->parent->right = NULL;
        delete(node);
        setColor(root, E_BLACK);
    }
}

Node* RBTree::deleteBST(Node *&root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        return deleteBST(root->left, data);

    if (data > root->data)
        return deleteBST(root->right, data);

    if (root->left == NULL || root->right == NULL)
        return root;

    Node *temp = minValueNode(root->right);
    root->data = temp->data;
    return deleteBST(root->right, temp->data);
}

void RBTree::deleteValue(int data) {
    Node *node = deleteBST(root, data);
    fixDeleteRBTree(node);
}

void RBTree::inorderBST(Node *&ptr) {
    if (ptr == NULL)
        return;

    inorderBST(ptr->left);
    cout << ptr->data << " " << ptr->color << endl;
    inorderBST(ptr->right);
}

void RBTree::inorder() {
    inorderBST(root);
}

void RBTree::preorderBST(Node *&ptr) {
    if (ptr == NULL)
        return;

    cout << ptr->data << " " << ptr->color << endl;
    preorderBST(ptr->left);
    preorderBST(ptr->right);
}

void RBTree::preorder() {
    preorderBST(root);
    cout << "-------" << endl;
}

Node *RBTree::minValueNode(Node *&node) {

    Node *ptr = node;

    if (ptr)
        while (ptr->left != NULL)
            ptr = ptr->left;

    return ptr;
}

Node* RBTree::maxValueNode(Node *&node) {
    Node *ptr = node;

    while (ptr->right != NULL)
        ptr = ptr->right;

    return ptr;
}

int RBTree::getBlackHeight(Node *node) {
    int blackheight = 0;
    while (node != NULL) {
        if (getColor(node) == E_BLACK)
            blackheight++;
        node = node->left;
    }
    return blackheight;
}

void RBTree::print2dTree(Node *n, int space) {
	if (n == NULL)
		return ;
	space += 5;
	print2dTree(n->right, space);
	std::cout << std::endl;
	for (int i = 5; i < space; ++i)
		std::cout << " ";
	n->color ? std::cout << n->data << std::endl : std::cout << RED << n->data << RESET << std::endl;
	print2dTree(n->left, space);
}

void RBTree::setRBtreeEnds(void) {

}

// Test case 1 : 5 2 9 1 6 8 0 20 30 35 40 50 0
// Test case 2 : 3 0 5 0
// Test case 3 : 2 1 3 0 8 9 4 5 0

void RBTree::merge(RBTree rbTree2) {
    int temp;
    Node *c, *temp_ptr;
    Node *root1 = root;
    Node *root2 = rbTree2.root;
    int initialblackheight1 = getBlackHeight(root1);
    int initialblackheight2 = getBlackHeight(root2);
    if (initialblackheight1 > initialblackheight2) {
        c = maxValueNode(root1);
        temp = c->data;
        deleteValue(c->data);
        root1 = root;
    }
    else if (initialblackheight2 > initialblackheight1) {
        c = minValueNode(root2);
        temp = c->data;
        rbTree2.deleteValue(c->data);
        root2 = rbTree2.root;
    }
    else {
        c = minValueNode(root2);
        temp = c->data;
        rbTree2.deleteValue(c->data);
        root2 = rbTree2.root;
        if (initialblackheight1 != getBlackHeight(root2)) {
            rbTree2.insertValue(c->data);
            root2 = rbTree2.root;
            c = maxValueNode(root1);
            temp = c->data;
            deleteValue(c->data);
            root1 = root;
        }
    }
    setColor(c,E_RED);
    int finalblackheight1 = getBlackHeight(root1);
    int finalblackheight2 = getBlackHeight(root2);
    if (finalblackheight1 == finalblackheight2) {
        c->left = root1;
        root1->parent = c;
        c->right = root2;
        root2->parent = c;
        setColor(c,E_BLACK);
        c->data = temp;
        root = c;
    }
    else if (finalblackheight2 > finalblackheight1) {
        Node *ptr = root2;
        while (finalblackheight1 != getBlackHeight(ptr)) {
            temp_ptr = ptr;
            ptr = ptr->left;
        }
        Node *ptr_parent;
        if (ptr == NULL)
            ptr_parent = temp_ptr;
        else
            ptr_parent = ptr->parent;
        c->left = root1;
        if (root1 != NULL)
            root1->parent = c;
        c->right = ptr;
        if (ptr != NULL)
            ptr->parent = c;
        ptr_parent->left = c;
        c->parent = ptr_parent;
        if (getColor(ptr_parent) == E_RED) {
            fixInsertRBTree(c);
        }
        else if (getColor(ptr) == E_RED){
            fixInsertRBTree(ptr);
        }
        c->data = temp;
        root = root2;
    }
    else {
        Node *ptr = root1;
        while (finalblackheight2 != getBlackHeight(ptr)) {
            ptr = ptr->right;
        }
        Node *ptr_parent = ptr->parent;
        c->right = root2;
        root2->parent = c;
        c->left = ptr;
        ptr->parent = c;
        ptr_parent->right = c;
        c->parent = ptr_parent;
        if (getColor(ptr_parent) == E_RED) {
            fixInsertRBTree(c);
        }
        else if (getColor(ptr) == E_RED) {
            fixInsertRBTree(ptr);
        }
        c->data = temp;
        root = root1;
    }
    return;
}