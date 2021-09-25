#include "map.hpp"
#include "colors.h"
#include <utility>
#include <time.h>
#include <iomanip>

void insertTest();
void deleteTest();
void unitTest();
using namespace std;

int main() {

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
    // deleteTest();
    unitTest();

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
    ft::map<int, int> rbTree2;
    // for (size_t i = 1; i <= 20; i++)
        // rbTree2.insertValue(i);

	ft::pair<int, int> one(2, 2);
    rbTree2.insert(one);
	one.first =  8;
	one.second = 8;
	// std::cout << rbTree2.getTree()->parent->myPair.first << std::endl;
	//  rbTree2.print2dTree(rbTree2.getTree()->parent);
    rbTree2.insert(one);
    std::cout << MAGENTA "rbTree2.getTree()->parent : " << rbTree2.getTree()->parent << RESET"\n";
    rbTree2.print2dTree(rbTree2.getTree()->parent);

	one.first =  3;
	one.second = 3;
    rbTree2.insert(one);
    std::cout << MAGENTA "rbTree2.getTree()->parent : " << rbTree2.getTree()->parent << RESET"\n";
    rbTree2.print2dTree(rbTree2.getTree()->parent);


	one.first =  16;
	one.second = 16;
    rbTree2.insert(one);
    std::cout << MAGENTA "rbTree2.getTree()->parent : ptr/val" << rbTree2.getTree()->parent << "/" << rbTree2.getTree()->parent->myPair.first << RESET"\n";
    std::cout << MAGENTA "rbTree2.getRoot() : " << rbTree2.getRoot(rbTree2.getTree())->myPair.first << RESET"\n";
    rbTree2.print2dTree(rbTree2.getTree()->parent);
	one.first =  1;
	one.second = 1;
    rbTree2.insert(one);
    rbTree2.print2dTree(rbTree2.getTree()->parent);
	one.first =  18;
	one.second = 18;
    rbTree2.insert(one);
    rbTree2.print2dTree(rbTree2.getTree()->parent);
	one.first =  18;
	one.second = 18;
    rbTree2.insert(one);

    rbTree2.print2dTree(rbTree2.getTree()->parent);

//    std::cout << rbTree2.getTree()->left->myPair.second << std::endl;
//    std::cout << rbTree2.getTree()->right->myPair.second << std::endl;
//    iterator test1 = rbTree2.end();
//    std::cout << "test : root/baseRoot_ptr : " << /* rbTree2.end()._root */test1._root << "/" << /* rbTree2.end()._baseRoot <<  */test1._baseRoot << std::endl;
//    if (rbTree2.end()._baseRoot == rbTree2.root)
//        std::cout << "OUI\n";
    ft::map<int,int>::iterator it = rbTree2.begin(), end = rbTree2.end();
   for (;it != end; ++it)
       std::cout << it->second << std::endl;
    // std::cout << it._ptr->myPair.first << ":" << it._ptr->parent->myPair.first << ":" << it._ptr->parent->parent->myPair.first << ":" << it._ptr->parent->parent->parent->myPair.first << "\n";

//    
//    std::cout << "Après la boucle ++it\n";
//    std::cout << *it << std::endl;
//    ++it;
//    std::cout << *it << std::endl;
//    ++it;
//    std::cout << *it << std::endl;
//    ++it;
//    std::cout << *it << std::endl;
//
//// iterator it2 = rbTree2.begin();
//    std::cout << "--it\n";
//--it;
//std::cout << *it << std::endl;
//--it;
//std::cout << *it << std::endl;
//--it;
//std::cout << *it << std::endl;
//--it;
//std::cout << *it << std::endl;    
    
}

void deleteTest()
{
    ft::map<int, int>  rbTree2;
    // for (size_t i = 1; i <= 20; i++)
        // rbTree2.insertValue(i);
	ft::pair<int, int> one(2, 2);
    rbTree2.insert(one);
	one.first =  8;
	one.second = 8;
    rbTree2.insert(one);
	one.first =  3;
	one.second = 3;
    rbTree2.insert(one);
	one.first =  16;
	one.second = 16;
    rbTree2.insert(one);
	one.first =  1;
	one.second = 1;
    rbTree2.insert(one);
	one.first =  18;
	one.second = 18;
    rbTree2.insert(one);

    rbTree2.print2dTree(rbTree2.getTree()->parent);

    std::cout << "rbTree2.root->left/right (data) : " 
    << rbTree2.getTree()->left->myPair.second << "/" << rbTree2.getTree()->right->myPair.second << std::endl;

    rbTree2.erase(one.first); // 16, 18 problem
    rbTree2.print2dTree(rbTree2.getTree()->parent);
    one.first =  2;
	one.second = 2;
    rbTree2.erase(one.first); // 16, 18 problem
    rbTree2.print2dTree(rbTree2.getTree()->parent);
    one.first =  3;
	one.second = 3;
    rbTree2.erase(one.first); // 16, 18 problem
    rbTree2.print2dTree(rbTree2.getTree()->parent);

//    int i(0);
   ft::map<int,int>::iterator it = rbTree2.begin();
   for (;it != rbTree2.end() /* && ++i < 4 */; ++it)
       std::cout << it->first << std::endl;
//    std::cout << *it << std::endl;
//    rbTree2.deleteValue(2); // 16, 18 problem
//    rbTree2.print2dTree(rbTree2.getTree()->parent);
//    std::cout << "rbTree2.getTree()->left/right (data) : " 
//    << rbTree2.getTree()->left->myPair.second << "/" << rbTree2.getTree()->right->myPair.second << std::endl;
//    std::cout << *it << std::endl;
//
////Fonctionne :
///*     for (;it != rbTree2.end() && ++i < 3; ++it)
//        std::cout << *it << std::endl;
//    std::cout << *it << std::endl;
//    rbTree2.deleteValue(3); // 8
//    rbTree2.print2dTree(rbTree2.root->parent);
//    std::cout << *it << std::endl; */
//    
//    std::cout << "\n2nd boucle\n";
//
//    it = rbTree2.begin();
//    for (;it != rbTree2.end()  /* && ++i < 4 */; ++it)
//        std::cout << *it << std::endl;
//    std::cout << *it << std::endl;
    
}
#include <map>
void different_eraseBehavior_offMap();
void itInvalidated_offMap();
void itMapping_offMap();

void unitTest()
{

/* 	ft::map<int, int> map_int;
    for (size_t i = 0; i < 100; i++)
    {
		int int1 = rand(), int2 = rand();
		map_int.insert(ft::make_pair(int1, int2));
    }
    std::cout << "map_int._mapTree->parent : " << map_int._mapTree->parent << ":" << map_int._mapTree->parent->myPair.first << std::endl;
    ft::map<int, int> copy = map_int; */

	ft::map<int, int> map1;
	std::map<int, int> off_map1;
	ft::pair<int , int> pair(10, 10);
	std::pair<int , int> of_pair(10, 10);
	map1.insert(pair);
    off_map1.insert(of_pair);
    pair.first = 100; pair.second = 100; of_pair.first = 100; of_pair.second = 100;
    map1.insert(map1.begin(), pair); off_map1.insert(of_pair);
    pair.first = 1000; pair.second = 1000; of_pair.first = 1000; of_pair.second = 1000;
    map1.insert(map1.begin(), pair); off_map1.insert(of_pair);

    std::cout << "map1.size() : " << map1.size() << "map1._mapTree : ptr/val" << map1._mapTree << "/" << map1._mapTree->myPair.first << " \tmain_map\n";
    map1.print2dTree(map1._mapTree);
    // for (ft::map<int, int>::iterator it = map1.begin(), it_end = map1.end(); it != it_end; ++it)
    // {
    //     std::cout << it->first << " \tto_erase\n";
    //     map1.erase(it);
    // }
    std::cout << "map1.size() : " << map1.size() << " \tmain_map\n";
    map1.print2dTree(map1._mapTree);

    map1.erase(map1.begin(), map1.end());
	ft::map<int, int> map2;
	map2.insert(map2.begin(), pair);
	std::map<int, int> off_map2;
    std::cout << "ici\n";
    std::cout << "la\n"; 
	off_map2.insert(off_map2.begin(), of_pair);
    
    std::cout << map2.size() << ":" << off_map2.size() << 
    "/" << map1.begin()->first << std::endl;
}

void infiniteLoop_offMap()
{
	std::map<int, int> off_map1;
	std::pair<int , int> of_pair(100, 100);
	std::map<int, int> off_map2;
    std::cout << "ici_printed\n";
	off_map2.insert(off_map1.begin(), of_pair); // (because it.begin() is not from map2)
    std::cout << "la_not_printed\n"; 
    return;
}

void itInvalidated_offMap()
{
	std::map<int, int> off_map1;
	std::pair<int , int> of_pair(100, 100);
    off_map1.insert(of_pair);
    of_pair.first = 10; of_pair.second = 10;
    off_map1.insert(of_pair);
    of_pair.first = 1000; of_pair.second = 1000;
    off_map1.insert(of_pair);
    // of_pair.first = 500; of_pair.second = 500;
    // off_map1.insert(of_pair);

    std::cout << "il y a : " << off_map1.size() << " elements\n";
    std::map<int, int>::iterator it = off_map1.begin(), it_end = off_map1.end();
    for (; it != it_end; ++it)
        std::cout << it->first << "\n";
    std::cout << "\n\n";

    it = off_map1.begin(), it_end = off_map1.end();
    std::cout << "\non avance l'itérator qui sert à effacé il pointe vers le 2eme élements\n";
    ++it;
    for (; it != it_end; ++it)
    {
        std::cout << it->first << "\n";
        off_map1.erase(it);
        std::cout << "it._M_node : " << it._M_node << ":"/*  << it._M_node->_M_left  */<< ":\n"; 
        std::cout  << it._M_node->_M_right << ":" << it._M_node->_M_parent << "\n";
        // std::cout << it->first << " \tmain_map\n"; //<- segfault 
    }
    std::cout << "il y a : " << off_map1.size() << " elements\n";
    for (; it != it_end; ++it)
        std::cout << it->first << "\n";
    return;
}

void different_eraseBehavior_offMap()
{//dans un cas on efface tous les éléments ds l'autres non (sans savoir pourquoi)
    std::map<int, int> off_map1;
	std::pair<int , int> of_pair(100, 100);
    off_map1.insert(of_pair);
    of_pair.first = 10; of_pair.second = 10;
    off_map1.insert(of_pair);
    of_pair.first = 1000; of_pair.second = 1000;
    off_map1.insert(of_pair);
    std::cout << "il y a : " << off_map1.size() << " elements\n";
    std::map<int, int>::iterator it = off_map1.begin(), it_end = off_map1.end();
    for (; it != it_end; ++it)
        std::cout << it->first << ":" << it._M_node << ":" << it._M_node->_S_minimum(it._M_node) << 
        ":" <<it._M_node->_S_maximum(it._M_node) << " \tmain_map\n";
    std::cout << "\n\non avance l'itérator qui sert à effacé il pointe vers le 2eme élements\n\n";
    it = off_map1.begin(), it_end = off_map1.end();
    ++it;
    for (; it != it_end; ++it)
    {
        std::cout << it->first << ":" << it._M_node << ":" << it._M_node->_S_minimum(it._M_node) 
        << ":" << it._M_node->_S_maximum(it._M_node) << " \tto_erase\n";
        off_map1.erase(it);
        std::cout << "it._M_node : " << it._M_node << "\n";
    }
    std::cout << "il y a : " << off_map1.size() << " elements\n";
    it = off_map1.begin(), it_end = off_map1.end();
    for (; it != it_end; ++it)
        std::cout << it->first << "\n";

    std::cout << "S'il y a plus de membres tout n'est pas effacé\n";
    of_pair.first = 100; of_pair.second = 100;
    off_map1.insert(of_pair);
    of_pair.first = 10; of_pair.second = 10;
    off_map1.insert(of_pair);
    of_pair.first = 1000; of_pair.second = 1000;
    off_map1.insert(of_pair);
    of_pair.first = 500; of_pair.second = 500;
    off_map1.insert(of_pair);
    of_pair.first = 200; of_pair.second = 200;
    off_map1.insert(of_pair);
    of_pair.first = 150; of_pair.second = 150;
    off_map1.insert(of_pair);
    of_pair.first = 600; of_pair.second = 600;
    off_map1.insert(of_pair);
    of_pair.first = 700; of_pair.second = 700;
    off_map1.insert(of_pair);
    std::cout << "il y a : " << off_map1.size() << " elements\n";
    it = off_map1.begin(), it_end = off_map1.end();
    for (; it != it_end; ++it)
        std::cout << it->first << ":" << it._M_node << ":" << it._M_node->_S_minimum(it._M_node) << 
        ":" <<it._M_node->_S_maximum(it._M_node) << " \tmain_map\n";
    std::cout << "\non avance l'itérator qui sert à effacé il pointe vers le 2eme élements\n";
    it = off_map1.begin(), it_end = off_map1.end();
    ++it;
     std::map<int, int>::iterator test(it._M_node);
    for (; it != it_end; ++it)
    {
        std::cout << it->first << ":" << it._M_node << ":" << it._M_node->_S_minimum(it._M_node) 
        << ":" << it._M_node->_S_maximum(it._M_node) << " \tto_erase\n";
        off_map1.erase(it);
        std::cout << "it._M_node : " << it._M_node << "\n";
    }
    std::cout << "il y a : " << off_map1.size() << " elements\n";
    it = off_map1.begin(), it_end = off_map1.end();
    for (; it != it_end; ++it)
        std::cout << it->first << "\n";
    
    return;
}

void itMapping_offMap()
{//sert à savoir comment sont réorganisés les éléments d'une map offcielle après une insertion ou délétion
	std::map<int, int> off_map1;
	std::pair<int , int> of_pair(100, 100);
    off_map1.insert(of_pair);
    of_pair.first = 10; of_pair.second = 10;
    off_map1.insert(of_pair);
    of_pair.first = 1000; of_pair.second = 1000;
    off_map1.insert(of_pair);
    of_pair.first = 500; of_pair.second = 500;
    off_map1.insert(of_pair);

    std::cout << "il y a : " << off_map1.size() << " elements\n";
    std::map<int, int>::iterator it = off_map1.begin(), it_end = off_map1.end();
    std::cout << std::setw(5) << "value" << " | "  << std::setw(15) << "node" << 
        " | " << std::setw(15) << "nod_parent" << " | "  << std::setw(15) 
        << "node_left" << " | " << std::setw(15) << "node_right" << "\n";
    for (; it != it_end; ++it)
        std::cout << std::setw(5) << it->first << " | "  << std::setw(15) << it._M_node << 
        " | "  << std::setw(15) << it._M_node->_M_parent << " | "  << std::setw(15) << it._M_node->_M_left <<
        " | "   << std::setw(15) << it._M_node->_M_right << "\tmain_map\n";
    std::cout << "\n\n";

    it = off_map1.begin(), it_end = off_map1.end();
    std::cout << "\non avance l'itérator qui sert à effacé il pointe vers le 2eme élements\n";
    ++it;
    std::cout << "it to_erase : " << it->first << std::endl;
    off_map1.erase(it);
    // ++it;
    std::cout << "\n\n";
    it = off_map1.begin(), it_end = off_map1.end();

/*     ++it;
        std::cout << std::setw(5) << it->first << " | "  << std::setw(15) << it._M_node << 
        " | "  << std::setw(15) << it._M_node->_M_parent << " | "  << std::setw(15) << it._M_node->_M_left << 
        " | "  << std::setw(15) << it._M_node->_M_right  << "\tmain_map\n";
    it = off_map1.begin(), it_end = off_map1.end();
    std::cout << "il y a : " << off_map1.size() << " elements\n"; */
    for (; it != it_end; ++it)
        std::cout << std::setw(5) << it->first << " | "  << std::setw(15) << it._M_node << 
        " | "  << std::setw(15) << it._M_node->_M_parent << " | "  << std::setw(15) << it._M_node->_M_left <<
        " | "   << std::setw(15) << it._M_node->_M_right << "\tmain_map\n";
    std::cout << "\n\n";

    std::cout << std::setw(5) << it->first << " | "  << std::setw(15) << it._M_node << 
    " | "  << std::setw(15) << it._M_node->_M_parent << " | "  << std::setw(15) << it._M_node->_M_left <<
    " | "   << std::setw(15) << it._M_node->_M_right << "\tmain_map\n";
    return;
}

/* void print2dTree(std::_Rb_tree_node_base *n, int space) {
	if (n == NULL)
		return ;
	space += 5;
	print2dTree(n->_M_right, space);
	std::cout << std::endl;
	for (int i = 5; i < space; ++i)
		std::cout << " ";
	n->color ? std::cout << n->data << " : " << n << std::endl : std::cout << RED << n->data << " : " << n << RESET << std::endl;
	print2dTree(n->left, space);
} */