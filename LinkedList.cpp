//
// Created by 朱宸 on 2019/10/31.
//
#include <iostream>
using namespace std;
#include "Node.h";
#include "LinkedList.h"

Linkedlist::Linkedlist(){
    Node(0, nullptr);
}

Linkedlist::Linkedlist(const Linkedlist &list) {
    cout << "Calling Copy Constructor: " << endl;
    Node* current = list.head;
    Node* copy = head;
    while(current->next!= nullptr){
        copy->next = new Node(current->next->value);
        copy = copy->next;
        current = current->next;
    }
}

Linkedlist::~Linkedlist() {
    cout << "Calling Destructor: " << endl;
    Node *curr = head;
    Node *next = curr->next;
    while(curr->next != nullptr){
        delete curr;
        curr = next;
        next = next->next;
    }
}

Linkedlist& Linkedlist::operator=(const Linkedlist &assignment) {
    cout<<"copy assignment operator:"<<endl;
    Linkedlist copyObject;
    swap(copyObject.head,head);
    return *this;

}

void Linkedlist::append(int item){
    if(head == nullptr){
        head = new Node(item);
    }
    else{
        Node *curr = head;
        while(curr->next !=nullptr){
            curr = curr->next;
        }
        curr->next = new Node(item);
    }
}


void Linkedlist::InsertionSort( ) {
    Node * curr = head->next;
    Node * temp;
    Node * prev  = head;
    Node * next;
    if(head == nullptr||head->next == nullptr){
        return;
    }

    while(curr != nullptr){
        if(curr->value >= prev->value) {
            curr = curr->next;
            prev = prev->next;
        }
        else{
            if(curr->value < head->value){
                prev->next = curr->next;
                curr->next = nullptr;
                curr->next = head;
                head = curr;

            }

            else{
                temp = head;
                while (curr->value > temp->next->value &&temp->next != nullptr) {
                    temp = temp->next;
                }
                prev->next = curr->next;
                curr->next = nullptr;
                curr->next = temp->next;
                temp->next = curr;
            }
        }
        curr=prev->next;
    }

}

void Linkedlist::printList(){
    Node* cursor = head;
    if (!cursor) {
        cout << "Empty" << endl;
    }
    else{
        while(cursor){
            cout << cursor->value << "\t";
            cursor = cursor->next;
        }
    }
    cout << endl;
}
