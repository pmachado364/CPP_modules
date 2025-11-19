#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>


int main() {
    std::vector<int> v; // Simplest type of container. Dynamic array that can change size. Also provides fast random access to elements via indexing.
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "Vector elements: " << std::endl;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }

    try {
        std::vector<int>::iterator i = easyfind(v, 20);
        std::cout << "Found element: " << *i << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    std::list<int> lst; // doubly linked list. Allows fast insertions and deletions anywhere in the list unlike vectors (only at the end)
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);
    std::cout << "List elements: " << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << std::endl;
    }

    try {
        std::list<int>::iterator i = easyfind(lst, 400);
        std::cout << "Found element: " << *i << std::endl;
    } catch (const NotFoundException& e){
        std::cout << e.what() << std::endl;
    }

    std::deque<int> d; // double ended queue. Allows fast insertions and deletions at both ends unlike vectors (only at the end)
    d.push_back(1000);
    d.push_back(2000);
    d.push_back(3000);
    std::cout << "Deque elements: " << std::endl;
    for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it) {
        std::cout << *it << std::endl;
    }

    try {
        std::deque<int>::iterator i = easyfind(d, 3000);
        std::cout << "Found element: " << *i << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}