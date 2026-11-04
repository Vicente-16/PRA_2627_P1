#include <iostream>
#include "Node.h"

int main() {
    Node<char>* n1 = new Node<char>('A');
    Node<char>* n2 = new Node<char>('B', n1);
    Node<char>* n3 = new Node<char>('C', n2);

    std::cout << "Node 3: " << *n3 << std::endl;
    std::cout << "Node 2: " << *(n3->next) << std::endl;
    std::cout << "Node 1: " << *(n3->next->next) << std::endl;

    delete n1;
    delete n2;
    delete n3;

    return 0;
}
