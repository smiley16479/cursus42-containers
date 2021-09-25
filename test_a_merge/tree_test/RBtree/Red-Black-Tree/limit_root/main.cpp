// Driver Program for Red Black Tree

#include <bits/stdc++.h>
#include "RBTree.h"
#include <map>

void insertTest();
void deleteTest();

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
    
		// insertTest();
   deleteTest();
/*    std::map<int, int> test;
        std::pair<int, int> a;
    for (size_t i = 0; i < 9; i++) {
        a = std::make_pair<int, int> (i , i);
        test.insert(a);
    }
    std::map<int, int>::iterator it = test.begin(), end = test.end();
    for (; it != end; it++){
        std::cout << it->first << std::endl;
    }
    std::cout << "on en est ou : " << it->first << std::endl;
    ++it;
    std::cout << "on en est ou : " << it->first << std::endl;
    ++it;
    std::cout << "on en est ou : " << it->first << std::endl;

    std::cout << "avant erase --it" << it->first << std::endl;
    test.erase(it);
    std::cout << "après erase --it" << it->first << std::endl;
    // std::cout << it->first << std::endl;
     ++it;
    --it;
    std::cout << it->first << std::endl;
    --it;
    std::cout << it->first << std::endl;
    --it;
    std::cout << it->first << std::endl;
    --it;
    std::cout << it->first << std::endl;
    --it;
    std::cout << it->first << std::endl; */

    return 0;
}

void insertTest()
{
    RBTree rbTree2;
    // for (size_t i = 1; i <= 20; i++)
        // rbTree2.insertValue(i);
    rbTree2.insertValue(2);
    rbTree2.insertValue(8);
    rbTree2.insertValue(3);
    rbTree2.insertValue(16);
    rbTree2.insertValue(1); 
    rbTree2.insertValue(18);
    rbTree2.print2dTree(rbTree2.root->parent);

    std::cout << rbTree2.root->left->data << std::endl;
    std::cout << rbTree2.root->right->data << std::endl;
    my_iterator test1 = rbTree2.end();
    std::cout << "test : root/baseRoot_ptr : " << /* rbTree2.end()._root */test1._root << "/" << /* rbTree2.end()._baseRoot <<  */test1._baseRoot << std::endl;
    if (rbTree2.end()._baseRoot == rbTree2.root)
        std::cout << "OUI\n";
my_iterator it = rbTree2.begin(), end = rbTree2.end();
    for (;it != end; ++it)
        std::cout << *it << std::endl;
    
    std::cout << "Après la boucle ++it\n";
    std::cout << *it << std::endl;
    ++it;
    std::cout << *it << std::endl;
    ++it;
    std::cout << *it << std::endl;
    ++it;
    std::cout << *it << std::endl;

// my_iterator it2 = rbTree2.begin();
    std::cout << "--it\n";
--it;
std::cout << *it << std::endl;
--it;
std::cout << *it << std::endl;
--it;
std::cout << *it << std::endl;
--it;
std::cout << *it << std::endl;    
    
}

void deleteTest()
{
    RBTree rbTree2;
    // for (size_t i = 1; i <= 20; i++)
        // rbTree2.insertValue(i);
    rbTree2.insertValue(2);
    rbTree2.insertValue(8);
    rbTree2.insertValue(3);
    rbTree2.insertValue(16);
    rbTree2.insertValue(1); 
    rbTree2.insertValue(18);
    rbTree2.print2dTree(rbTree2.root->parent);

    std::cout << "rbTree2.root->left/right (data) : " << rbTree2.root->left->data << "/" << rbTree2.root->right->data << std::endl;


    int i(0);
    my_iterator it = rbTree2.begin(), it_end = rbTree2.end();
    //  for (;it != rbTree2.end() /* && ++i < 4 */; ++it){
    //     std::cout << *it << std::endl;
    //      std::cout << it._baseRoot->parent->data << " boucle""\n";
    //      }
    //     // rbTree2.deleteValue(it);
        rbTree2.deleteValue(it, it_end);
    // it = rbTree2.begin();


    // std::cout << *it << std::endl;
    // rbTree2.deleteValue(3); // 16, 18 problem
    rbTree2.print2dTree(rbTree2.root->parent);
    std::cout << "rbTree2.root->left/right (data) : " << rbTree2.root->left->data << "/" << rbTree2.root->right->data << std::endl;
    // std::cout << *it << std::endl;

//Fonctionne :
/*     for (;it != rbTree2.end() && ++i < 3; ++it)
        std::cout << *it << std::endl;
    std::cout << *it << std::endl;
    rbTree2.deleteValue(3); // 8
    rbTree2.print2dTree(rbTree2.root->parent);
    std::cout << *it << std::endl; */
    
    std::cout << "\n2nd boucle\n";

    it = rbTree2.begin();
    for (;it != rbTree2.end()  /* && ++i < 4 */; ++it)
        std::cout << *it << std::endl;
    // std::cout << *it << std::endl;
    
}
