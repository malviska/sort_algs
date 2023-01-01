#include<string>
#include<cstdlib>
#include<ctime>
#include"item.hpp"
#include"item_loaded.hpp"

#ifndef METHODS_H
#define METHODS_H
#define Swap(A, B) {ItemLoaded c = A; A = B; B = c; }

typedef struct
{
  int right;
  int left;
}Index;

int generateKey(int size);
void InsertionSort(Item* A, int n);
void SelectionSort(ItemLoaded* A, int i, int j, int* mtrs);
void generateRealNumber(double& num);
void generateAlphaNumeric(char * str);




#endif