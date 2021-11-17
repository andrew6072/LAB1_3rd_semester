#include <iostream>
#include <chrono>
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Sort.hpp"
using namespace std;
using namespace std::chrono;

int main()
{
    // Sequence<int> *sq = new ListSequence<int>();
    // ArraySorter<int> *sort = new ArraySorter<int>();
    //  sq->generator(10000);

    // auto start = high_resolution_clock::now();
    // sort->shellSort(sq, ascending);

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by selection quick sorting: " << duration.count() << " microseconds\n";
    // sort->running_time(ascending);
    ListSequence<int> *myList = new ListSequence<int>();
    myList->push_back(1);
    myList->push_back(7);
    myList->push_back(2);
    myList->push_back(8);
    myList->push_back(3);
    myList->push_back(9);
    myList->print();
    ListSorter<int> *listSort = new ListSorter<int>();
    listSort->mergeSort(myList, descending);
    myList->print();
}