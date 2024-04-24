#include <iostream>
#include "Tree.h" 


bool compareInt(const int& a, const int& b) {
    return a > b;
}

int main() {
    Tree<int> tree;

    Node<int>* node1 = tree.add_node(5, nullptr);
    Node<int>* node2 = tree.add_node(10, node1);
    Node<int>* node3 = tree.add_node(15, node1);
    tree.add_node(20, node2);
    tree.add_node(25, node3);

    tree.sort(node1, compareInt);

    return 0;
}

