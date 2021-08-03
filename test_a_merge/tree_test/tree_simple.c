#include <stdio.h>
#include <stdlib.h>
// La difference de déclaration d'une structure à l'intérueure d'elle même en C/CPP
// oblige à rementionner le nom complet de la structure à déclarer en son sein
typedef struct node_struc{
	int data;
	struct node_struc *parnt;
	struct node_struc *left;
	struct node_struc *right;
}node;

node *create_node(node *parent, int data)
{
	node *to_return = malloc(sizeof(node));
	to_return->parnt= parent;
	to_return->right= NULL;
	to_return->left = NULL;
	to_return->data = data;
	return to_return;
}

node *insert_node(node *root, int data)
{
	while (root) {
		if (data == root->data && (root->data = data))
			return root;
		else if (data > root->data) {
			if (root->right)
				root = root->right;
			else return root->right = create_node(root, data);
		}
		else {
			if (root->left)
				root = root->left;
			else return root->left = create_node(root, data);
		}
	}
	return root = create_node(root, data);
}

void delete_node(node* nd)
{// Efface un noeud (d'extrémité) en rendant la branche parente NULL
	if (nd->parnt->left == nd)
		nd->parnt->left = NULL;
	else
		nd->parnt->right= NULL;
	free(nd);
}

node *get_highest(node *nd) {
	while (nd->right)
		nd = nd->right;
	return nd;
}

node *get_lowest(node *nd) {
	while (nd->left)
		nd = nd->left;
	return nd;
}

void remove_node(node* nd)
{// Il manque le tintouin pour relier les nodes restants
	if (nd->left) {
		nd->data = get_highest(nd->left)->data;
		delete_node(get_highest(nd->left));
		return ;
	}
	else if (nd->right) {
		nd->data = nd->right->data;
		nd->left = nd->right->left;
		node *tmp = nd->right->right; 
		free(nd->right);
		nd->right = tmp;
	}
}

void delete_tree(node* root)
{// Delete the whole thing
	if (root->right) delete_tree(root->right);
	if (root->left) delete_tree(root->left);
	free(root);
}

void print_inorder(node* tree) {
	if (tree) {
		print_inorder(tree->left);
		printf("inorder _ptr : %p, %d\n", tree, tree->data);
		print_inorder(tree->right);
	}
}

int main(int argc, char const *argv[])
{
	node *root = NULL;
	
	root = insert_node(root, 6);
	insert_node(root, 4);
	node *to_delete = insert_node(root, 8);
	insert_node(root, 18);
	delete_node(to_delete);
	print_inorder(root);
	delete_tree(root);
	return 0;
}
