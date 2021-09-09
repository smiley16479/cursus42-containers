// Driver Program for Red Black Tree

#include <bits/stdc++.h>
#include "RBTree.h"

int main() {
    int data;
    RBTree rbTree1, rbTree2;

    // std::cin >> data;
    // while (data != 0)
    // {
    //     rbTree1.insertValue(data);
    //     std::cin >> data;
    // }

    // rbTree1.preorder();

    // std::cin >> data;
    // while (data != 0)
    // {
    //     rbTree2.insertValue(data);
    //     std::cin >> data;
    // }

    // rbTree2.preorder();
    // rbTree2.print2dTree(rbTree2.root);

    // rbTree1.merge(rbTree2);
    // rbTree1.preorder();

    // for (size_t i = 1; i <= 20; i++)
        // rbTree2.insertValue(i);
    rbTree2.insertValue(2);
    rbTree2.insertValue(8);
    rbTree2.insertValue(3);
    rbTree2.insertValue(16);
    rbTree2.insertValue(1);
    rbTree2.print2dTree(rbTree2.root);

    for (my_iterator it = rbTree2.begin(); it != rbTree2.end(); ++it)
        std::cout << *it << std::endl;
    return 0;
}