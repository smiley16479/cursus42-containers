/* 
** ARBRE BICOLORE WIKIPEDIA (ANGLAIS): 
** JE N'ARRIVE PAS À LE FAIRE MARCHER CODE TRÈS DIFFICILE À LIRE
** https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
*/
#include <cassert>
#include <unistd.h>
#include <iostream>
#define RESET   "\033[0m"
#define RED_D     "\033[31m"

enum color_t { BLACK, RED };

struct RBnode {     // node of red–black tree
  RBnode* parent;   // == NULL if root of the tree
  RBnode* child[2]; // == NIL if child is empty
    // Index is:
    //   LEFT  := 0, if (key < parent->key)
    //   RIGHT := 1, if (key > parent->key)
  enum color_t color;
  int key;
};

#define NIL   NULL // null pointer  or  pointer to sentinel node
#define LEFT  0
#define RIGHT 1
#define left  child[LEFT]
#define right child[RIGHT]

struct RBtree { // red–black tree
  RBnode* root; // == NIL if tree is empty
};

// Get the child direction (∈ { LEFT, RIGHT })
//   of the non-root non-NIL  RBnode* N:
#define childDir(N) ( N == (N->parent)->right ? RIGHT : LEFT )

// Helper functions:

RBnode* GetParent(RBnode* N) {
  // The parent of the root node is set to NULL.
  return N == NULL ? NULL : N->parent;
}

RBnode* GetGrandParent(RBnode* N) {
  // Will return NULL if N is root or child of root
  return GetParent(GetParent(N));
}

RBnode* GetSibling(RBnode* N) {
  RBnode* P = GetParent(N);
  // No parent means no sibling:
  assert(P != NULL);
  return P->child[1-childDir(N)];
}
// If parent P and child direction dir is available, same as:
//   P->child[1-dir]

RBnode* GetUncle(RBnode* N) {
  RBnode* P = GetParent(N);
  // No parent means no uncle:
  assert(P != NULL);
  return GetSibling(P);
}

RBnode* GetCloseNephew(RBnode* N) {
  RBnode* P = GetParent(N);
  int dir;
  RBnode* S;
  assert(P != NULL);
  dir = childDir(N);
  S = P->child[1-dir]; // sibling of N
  assert(S != NIL);
  return S->child[dir]; // the nephew close to N
}

RBnode* GetDistantNephew(RBnode* N) {
  RBnode* P = GetParent(N);
  int dir;
  RBnode* S;
  assert(P != NULL);
  dir = childDir(N);
  S = P->child[1-dir]; // sibling of N
  assert(S != NIL);
  return S->child[1-dir]; // the nephew distant from N
}

RBnode* RotateDirRoot(
    RBtree* T,   // red–black tree
    RBnode* P,   // root of subtree (may be the root of T)
    int dir) {   // dir ∈ { LEFT, RIGHT }
  RBnode* G = P->parent;
  RBnode* S = P->child[1-dir];
  RBnode* C;
  assert(S != NIL); // pointer to true node required
  C = S->child[dir];
  P->child[1-dir] = C; if (C != NIL) C->parent = P;
  S->child[  dir] = P; P->parent = S;
  S->parent = G;
  if (G != NULL)
    G->child[ P == G->right ? RIGHT : LEFT ] = S;
  else
    T->root = S;
  return S; // new root of subtree
}

#define RotateDir(N,dir) RotateDirRoot(T,N,dir)
#define RotateLeft(N)    RotateDirRoot(T,N,LEFT)
#define RotateRight(N)   RotateDirRoot(T,N,RIGHT)

void RBinsert1(
  RBtree* T,         // -> red–black tree
  struct RBnode* P,  // -> parent node of N (may be NULL)
  struct RBnode* N,  // -> node to be inserted
  char dir)          // side of P on which to insert N (∈ { LEFT, RIGHT })
{
  struct RBnode* G;  // -> parent node of P
  struct RBnode* U;  // -> uncle of N

  N->color = RED;
  N->left  = NIL;
  N->right = NIL;
  N->parent = P;
  if (P == NULL) {   // There is no parent
    T->root = N;     // N is the new root of the tree T.
    return; // insertion complete
  }
  P->child[dir] = N; // insert N as dir-child of P
  // start of the (do while)-loop:
  do {    
	  if (P->color == BLACK) {
      // Case_I1 (P black):
      return; // insertion complete
    }
    // From now on P is red.
    if ((G = GetParent(P)) == NULL) 
      goto Case_I4; // P red and root
    // else: P red and G!=NULL.
    dir = childDir(P); // the side of parent G on which node P is located
    U = G->child[1-dir]; // uncle
    if (U == NIL || U->color == BLACK) // considered black
      goto Case_I56; // P red && U black
	      // Case_I2 (P+U red):
    P->color = BLACK;
    U->color = BLACK;
    G->color = RED;
    N = G; // new current node
    // iterate 1 black level
    //   (= 2 tree levels) higher
  } while ((P = N->parent) != NULL);
  // end of the (do while)-loop

    // Case_I3 (P == NULL):
  return; // insertion complete

  Case_I4: // P is the root and red:
  P->color = BLACK;
  return; // insertion complete

  Case_I56: // P red && U black:
  if (N == P->child[1-dir])
  { // Case_I5 (P red && U black && N inner grandchild of G):
    RotateDir(P,dir); // P is never the root
    N = P; // new current node
    P = G->child[dir]; // new parent of N
    // fall through to Case_I6
  }

  // Case_I6 (P red && U black && N outer grandchild of G):
  RotateDirRoot(T,G,1-dir); // G may be the root
  P->color = BLACK;
  G->color = RED;
  return; // insertion complete
} // end of RBinsert1



void RBdelete2(
  RBtree* T,         // -> red–black tree
  struct RBnode* N)  // -> node to be deleted
 {
  struct RBnode* P = N->parent;  // -> parent node of N
  char dir;          // side of P on which N is located (∈ { LEFT, RIGHT })
  struct RBnode* S;  // -> sibling of N
  struct RBnode* C;  // -> close   nephew
  struct RBnode* D;  // -> distant nephew

  // P != NULL, since N is not the root.
  dir = childDir(N); // side of parent P on which the node N is located
  // Replace N at its parent P by NIL:
  P->child[dir] = NIL;
  goto Start_D;      // jump into the loop

  // start of the (do while)-loop:
  do {
    dir = childDir(N);   // side of parent P on which node N is located
Start_D:
    S = P->child[1-dir]; // sibling of N (has black height >= 1)
    D = S->child[1-dir]; // distant nephew
    C = S->child[  dir]; // close   nephew
    if (S->color == RED)
      goto Case_D3;                  // S red ===> P+C+D black
    // S is black:
    if (D != NIL && D->color == RED) // not considered black
      goto Case_D6;                  // D red && S black
    if (C != NIL && C->color == RED) // not considered black
      goto Case_D5;                  // C red && S+D black
    // Here both nephews are == NIL (first iteration) or black (later).
    if (P->color == RED)
      goto Case_D4;                  // P red && C+S+D black
	// Case_D1 (P+C+S+D black):
    S->color = RED;
    N = P; // new current node (maybe the root)
    // iterate 1 black level
    //   (= 1 tree level) higher
  } while ((P = N->parent) != NULL);
  // end of the (do while)-loop
    // Case_D2 (P == NULL):
  return; // deletion complete
  Case_D3: // S red && P+C+D black:
  RotateDirRoot(T,P,dir); // P may be the root
  P->color = RED;
  S->color = BLACK;
  S = C; // != NIL
  // now: P red && S black
  D = S->child[1-dir]; // distant nephew
  if (D != NIL && D->color == RED)
    goto Case_D6;      // D red && S black
  C = S->child[  dir]; // close   nephew
  if (C != NIL && C->color == RED)
    goto Case_D5;      // C red && S+D black
  // Otherwise C+D considered black.
  // fall through to Case_D4
  Case_D4: // P red && S+C+D black:
  S->color = RED;
  P->color = BLACK;
  return; // deletion complete
Case_D5: // C red && S+D black:
  RotateDir(S,1-dir); // S is never the root
  S->color = RED;
  C->color = BLACK;
  D = S;
  S = C;
  // now: D red && S black
  // fall through to Case_D6
  Case_D6: // D red && S black:
  RotateDirRoot(T,P,dir); // P may be the root
  S->color = P->color;
  P->color = BLACK;
  D->color = BLACK;
  return; // deletion complete
} // end of RBdelete2


void print2dTree(RBnode *n, int space) {
	if (n == NULL)
		return ;
	space += 5;
	print2dTree(n->child[1], space);
	std::cout << std::endl;
	for (int i = 5; i < space; ++i)
		std::cout << " ";
	n->color ? std::cout << RED_D << n->key << RESET << std::endl : std::cout << n->key << std::endl;
	print2dTree(n->child[0], space);
}

int main()
{
	RBtree root{NULL};
	RBnode a{NULL, NULL, NULL, BLACK, 1};
	RBnode b{NULL, NULL, NULL, BLACK, 2};
	RBnode c{NULL, NULL, NULL, BLACK, 3};
	RBnode d{NULL, NULL, NULL, BLACK, 8};
	RBnode e{NULL, NULL, NULL, BLACK, 16};


	RBinsert1(&root, GetParent(&b), &b, 1);
	RBinsert1(&root, GetParent(&d), &d, 1);
	RBinsert1(&root, GetParent(&c), &c, 1);
	RBinsert1(&root, GetParent(&e), &e, 1);
	RBinsert1(&root, GetParent(&a), &a, 1);
	// print2dTree(&c, 0);
	std::cout << "root.root->key : " << root.root->/* child[0]-> */key << std::endl;
	// std::cout << "root.root->child[1]->key : " << root.root->child[1]->key << std::endl;
	std::cout << "d.child[0]->key : " << d.child[0]->key << std::endl;

}