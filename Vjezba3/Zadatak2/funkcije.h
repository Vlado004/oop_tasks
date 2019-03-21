#ifndef FUNKCIJE_H
#define FUNKCIJE_H

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

vector<int> unos_vectora(vector<int> &vector, bool unos, int donja = 0, int gornja = 100, int br_elem = 5);

void ispis_vectora(vector<int> &vector);

vector<int> pronadi(vector<int> prvi, vector<int>drugi, vector<int> novi);

int compare(const void* a, const void* b);

#endif