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

    // ListSorter<int> *sort = new ListSorter<int>();
    // sort->exportToFile();

    // ArraySorter<int> *sort2 = new ArraySorter<int>();
    // sort2->exportToFile();

    vector<int> myVector;
    myVector = generatorVector(100);
    std::sort(myVector.begin(), myVector.end());

    Sequence<int> *myArray = new ArraySequence<int>();

    myArray->generator(10);
    myArray->print();
    ArraySorter<int> *arraySort = new ArraySorter<int>();
    // std::cout << myArray->get(1) << "\n";
    arraySort->shellSort(myArray, ascending);
    myArray->print();

    // ListSequence<int> *myList = new ListSequence<int>();
    // myList->push_back(100);
    // myList->push_back(71);
    // myList->push_back(26);
    // myList->push_back(82);
    // myList->push_back(33);
    // myList->push_back(17);
    // myList->print();
    // ListSorter<int> *listSort = new ListSorter<int>();
    // listSort->mergeSort(myList, descending);
    // myList->print();

    // Sequence<int> *arr = new ArraySequence<int>();
    // arr->generator(10);
    // ArraySorter<int> *sort2 = new ArraySorter<int>();
    // sort2->mergeSort(arr, ascending);
    // arr->print();

    // Test for changing T to const T& in Sequence, ArraySequence and ListSequence
    // Sequence<string> *myArray = new ArraySequence<string>();
    // myArray->insertAt("Andrew", 0);
    // myArray->insertAt("fell", 1);
    // myArray->insertAt("in love", 2);
    // myArray->insertAt("with maths", 3);
    // myArray->set("THH", 3);
    // myArray->swap(0, 3);
    // myArray->print();
    // ListSequence<string> *myList = new ListSequence<string>();
    // myList->insertAt("Andrew", 0);
    // myList->insertAt("fell", 1);
    // myList->insertAt("in love", 2);
    // myList->insertAt("with maths", 3);
    // myList->set("THH", 3);
    // myList->print();
}