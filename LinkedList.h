//
// Created by 朱宸 on 2019/10/31.
//

#include <iostream>
#include "Node.h"
using namespace std;
#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H


class Linkedlist {

public:
    Linkedlist();
    Linkedlist(const Linkedlist&list);
    ~Linkedlist();
    Linkedlist&operator = (const Linkedlist &assignment);
    void append(int item);
    void InsertionSort();
    void printList();

private:
    Node*head = nullptr;

};


#endif //BINARYINSERTIONSORT_LINKEDLIST_H