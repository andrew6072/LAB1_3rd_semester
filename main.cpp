#include <iostream>
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Sort.hpp"
using namespace std;

int main()
{
    Sequence<unsigned int> *sq = new ArraySequence<unsigned int>();
    sq->generator(10);
    sq->print();
    ArraySorter<unsigned int> *sort = new ArraySorter<unsigned int>();
    sort->shellSort(sq, descending);
    sq->print();

    cout << "---------sq2---------" << endl;
    ListSequence<unsigned int> *sq2 = new ListSequence<unsigned int>();
    sq2->generator(10);
    sq2->print();
    ListSorter<unsigned int> *sort2 = new ListSorter<unsigned int>();
    sort2->quickSort(sq2, ascending);
    sq2->print();
    return 0;
}