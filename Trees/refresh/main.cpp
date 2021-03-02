#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main(){
    BinaryTree<int> tree;
    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    cout << tree.in_order() << endl;
    return 0;
}