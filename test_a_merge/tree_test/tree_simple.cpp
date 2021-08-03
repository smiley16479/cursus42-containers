#include <iostream>

struct node{
	int data;
	node *left;
	node *right;
};

node *create_node(int data)
{
	node *to_return = new node;
	to_return->data = data;
	return to_return;
}

void delete_node(struct node* nd)
{// Il manque le tintouin pour relier les node restant
	delete nd;
}

int main(int argc, char const *argv[])
{
	node *root = create_node(1);
	std::cout << root->data << std::endl;
	delete_node(root);
	return 0;
}
