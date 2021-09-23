//
// Red Black Tree Definition
//

#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H
// #include "RBTreemy_Iterator.h"
#include "../../../../colors.h"

enum Color {E_RED, E_BLACK, E_DOUBLE_BLACK};

struct Node
{
    int data;
    int color;
    Node *left, *right, *parent;

    explicit Node(int);
};

class my_iterator
{
    public:
        Node *_baseRoot;
        Node *_root;

    typedef Node* reference;

    my_iterator() : _root(NULL) {}
    my_iterator(Node *ptr) : _root(ptr), _baseRoot(NULL) {
        _baseRoot = get_rootNode(ptr);
        #ifdef debug
            std::cout << "parametric it constructor\n"; 
            std::cout << "_baseRoot ptr/val : " <<  _baseRoot << "/" << _baseRoot->data  <<"\n"; 
        #endif
    }
    // bool friend operator!=();

    my_iterator& operator++() {
/*       if ((_root->right && _root->right->parent != _root)
        || (_root->left && _root->left->parent != _root))
        _root = _root->left;
      else  */
      if (_root->right == _baseRoot)
          _root = _baseRoot;
      else if (_root->right) {
        _root = _root->right;
        while (_root->left)
          _root = _root->left;
      }
      else {
        Node *tmp = _root->parent;

        while (_root == tmp->right) {
          _root = tmp;
          tmp = tmp->parent;
        }
        if (_root->right != tmp)
          _root = tmp;
      }
    #ifdef debug
        std::cout << "ds op++ root-data " << _root->data << ", root/baseRoot ptr : " <<   _root << "/" << _baseRoot << std::endl;
    #endif

      return *this;


/* 
		if (_root->right != maxValueNode(_root))		//	going down right
			_root = this->minValueNode(_root->right);
		else if (_root == maxValueNode(_root) || maxValueNode(_root)->left == _root)
			_root = _root->right;		//	last node or maxValueNode(_root) case
		else							//	going up
		{
			while (_root->parent != maxValueNode(_root) && _root == _root->parent->right)
				_root = _root->parent;
			_root = _root->parent;
		}
        return (*this); //c'est faux */
    }
    my_iterator operator++(int) {my_iterator tmp(*this); ++(*this); return tmp;} 

    my_iterator& operator -- () {
/*       if ((_root->right && _root->right->parent != _root)
        || (_root->left && _root->left->parent != _root))
        _root = _root->right; */
      if (_root->left == _baseRoot) {
          _root = _baseRoot;
          return *this;
      }
      else if (_root->left) {
        _root = _root->left;
        while (_root->right)
          _root = _root->right;
      }
      else {
        Node *tmp = _root->parent;

        while (_root == tmp->left) {
          _root = tmp;
          tmp = tmp->parent;
        }
        _root = tmp;
      }
      return *this;
    };

    int operator*() { return _root->data;}

Node *get_rootNode(Node *&node) {
    Node *ptr = node;
    while (ptr->parent != NULL)
        ptr = ptr->parent;
    Node *previous_ptr = ptr;
    while (ptr->left != previous_ptr)
    {   
        #ifdef debug
            // std::cout << " ptr inséré : " << ptr << " data : " << ptr->data << " prt : " << ptr->parent << std::endl;
        #endif
        previous_ptr = ptr;
        ptr = ptr->left;
    }
    return ptr;
}


    Node *minValueNode(Node *&node) {
        #ifdef debug
            // std::cout << " node inséré : " << node << " data : " << node->data << " parent : " << node->parent << std::endl;
        #endif
        Node *ptr = node;
        while (ptr->parent != NULL)
        {
            ptr = ptr->parent;     
        }
        while (ptr->left != NULL && ptr->left != _baseRoot)
            ptr = ptr->left;
        return ptr;
    }
    
    Node *maxValueNode(Node *&node) {
        Node *ptr = node;
        while (ptr->parent != NULL)
            ptr = ptr->parent;     
        while (ptr->right != NULL)
            ptr = ptr->right;
        return ptr;
}

    bool operator!=(my_iterator b) { if (this->_root != b._root) return true; return false;};
    bool operator==(my_iterator b) { if (*this != b) return false; return true;};

    my_iterator operator+(size_t n) { 
        if (this->_root) {
            my_iterator it(this->_root); 
            while (--n)
                ++it;
            return (it);
        }
        my_iterator it(maxValueNode(this->_root));
        return (it);
    }
};

    // bool operator!=(my_iterator& a, my_iterator& b) { if (a._root != b._root) return true; return false;};


class RBTree
{
    // private:
    public:
        // typedef RBTree my_iterator;

        Node *root;
        size_t siz;
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
        void deleteTree(Node *);
        int getBlackHeight(Node *);
        /* AJOUT */
        void set_left_right(void);
        void remove_left_right(void);
        void setRBtreeEnds(void);
        void bind_first_node(Node *ptr);
    public:
        RBTree();
        RBTree(Node *ptr);
        ~RBTree();

        void insertValue(int);
        void deleteValue(int);
        void merge(RBTree);
        void inorder();
        void preorder();
        /* AJOUT */
        void deleteValue( my_iterator it );
        void deleteValue( my_iterator it,  my_iterator last );
        void print2dTree( Node *n, int space = 0 );

        /* :: */my_iterator begin() {return /* :: */my_iterator(minValueNode(this->root->left));}
        /* :: */my_iterator end() {return   /* :: */my_iterator(this->root);}
};


#endif //RED_BLACK_TREE_RBTREE_H
