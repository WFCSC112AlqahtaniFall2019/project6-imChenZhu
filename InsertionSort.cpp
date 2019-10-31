#include <iostream>
#include <vector>
#include "BinaryInsertionSort.h"
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main() {

    int seed, length;
    cout<<"Please enter a seed";
    cin >> seed;
    cout<<"Please enter a length";
    cin>> length;
    srand(seed);

    vector<int> v(length);
    Linkedlist L = Linkedlist();

    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
    }

    //create a linked list for sorting
    for (int i = 0; i < length; i++) {
        L.append(v[i]);
    }
    //print the list to be sorted
    cout<<"Numbers to be sorted:"<<endl;
    L.printList();


    // FINISH ME
    clock_t start_binarysort = clock();
    insertionSort(v, v.size());
    clock_t end_binarysort = clock();


    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }

    cout<<"after binary insertion sort:"<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout<<endl;

    clock_t start_insertionsort = clock();
    L.InsertionSort();
    clock_t end_insertionsort = clock();

    cout << "List after linked list insertion sort: " << endl;
    L.printList();

    double elapsed_binarysort = double(end_binarysort - start_binarysort) / CLOCKS_PER_SEC;
    double elapsed_insertionsort = double(end_insertionsort - start_insertionsort) / CLOCKS_PER_SEC;

    cout<<"time for binarysort:"<<elapsed_binarysort<<endl;
    cout<<"time for insertionsort:"<<elapsed_insertionsort<<endl;

}
