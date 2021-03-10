#include <iostream>
#include "AVL.h"
#include "TreePrinter.h"
using namespace std;

int main(){
    AVL tree;
    tree.add(1);
    tree.add(-5);
    tree.add(3);
    tree.add(2);
    tree.add(5);
    tree.add(4);
    TP::PrintInorder(tree);
    TP::PrintPreorder(tree);
    TP::PrintPostorder(tree);
    return 0;
}