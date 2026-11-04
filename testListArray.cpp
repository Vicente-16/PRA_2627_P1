#include <iostream>
#include "ListArray.h"

int main() {
    ListArray<int> list;

    std::cout << "List empty? " << (list.empty() ? "Yes" : "No") << std::endl;

    list.append(10);
    list.append(20);
    list.prepend(5);
    list.insert(1, 15);

    std::cout << "List contents: " << list << std::endl;
    std::cout << "Size: " << list.size() << std::endl;

    std::cout << "Element at index 2: " << list.get(2) << std::endl;
    std::cout << "Search 20: index " << list.search(20) << std::endl;

    std::cout << "Removed element at index 1: " << list.remove(1) << std::endl;
    std::cout << "List after removal: " << list << std::endl;

    return 0;
}
