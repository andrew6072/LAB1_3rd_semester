#pragma once
#include <bits/stdc++.h>
#include "selection_sort.cpp"
using namespace std;
using namespace std::chrono;

void running_time_searching(int (*function)(vector<int> vect, int a), int n)
{
    vector<int> vect;
    vect = generate_vector(n);
    selectionSort(vect);
    int a = vect[vect.size() - 8];
    auto start = high_resolution_clock::now();
    function(vect, a);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by searching " << n << ":" << duration.count() << " microseconds" << endl;
}

void running_time_sorting(void (*function)(vector<int> &vect))
{
    vector<int> vect;
    vect = generate_vector(1000);
    auto start = high_resolution_clock::now();
    function(vect);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by selection sorting 1000: " << duration.count() << " microseconds" << endl;

    vector<int> vect2;
    vect2 = generate_vector(2500);
    auto start2 = high_resolution_clock::now();
    function(vect2);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time taken by selection sorting 2500: " << duration2.count() << " microseconds" << endl;

    vector<int> vect3;
    vect3 = generate_vector(5000);
    auto start3 = high_resolution_clock::now();
    function(vect3);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Time taken by selection sorting 5000: " << duration3.count() << " microseconds" << endl;

    vector<int> vect4;
    vect4 = generate_vector(10000);
    auto start4 = high_resolution_clock::now();
    function(vect4);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout << "Time taken by selection sorting 10000: " << duration4.count() << " microseconds" << endl;
}

void running_time_sorting2(void (*function)(vector<int> &vect, int low, int high), int n)
{
    vector<int> vect;
    int len;
    vect = generate_vector(n);
    len = vect.size();
    auto start = high_resolution_clock::now();
    function(vect, 0, len - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by quick sorting " << n << ":" << duration.count() << " microseconds" << endl;
}