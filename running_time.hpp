#pragma once
#include <iostream>
#include <chrono>
#include "Sort.hpp"


using namespace std::chrono;


void running_time(void (*function)(Sequence<unsigned int> *sequence, bool (*function1)(T data, T value)))
{
    Sequence<unsigned int> *sequence = new ArraySequence<T>();
    sequence->generator(100000);
    auto start = high_resolution_clock::now();
    function(sequence, function1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
}