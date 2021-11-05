#pragma once
#include <iostream>
#include "Sequence.hpp"
#include"ArraySequence.hpp"
#include "ListSequence.hpp"
using namespace std;

vector<int> generate_vector(int n)
{
    vector<int> vect(n);
    vect.clear();
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int a;
        a = (rand() % 10001) + 1;
        vect.push_back(a);
    }
    return vect;
}

void print_vector(vector<int> vect)
{
    for (int x : vect)
    {
        cout << x << "| ";
    }
    cout << endl;
}
