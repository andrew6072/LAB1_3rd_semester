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
    Sequence<int> *sq = new ArraySequence<int>();
    ArraySorter<int> *sort = new ArraySorter<int>();
    // sq->generator(10000);

    // auto start = high_resolution_clock::now();
    // sort->shellSort(sq, ascending);

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by selection quick sorting: " << duration.count() << " microseconds\n";
    sort->running_time(ascending);
    return 0;
}