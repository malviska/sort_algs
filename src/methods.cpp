#include "methods.hpp"

int generateKey(int size)
{
  return std::rand() % size;
}

void InsertionSort(Item *A, int n)
{
  int i, j;
  Item aux;
  for (i = 1; i < n; i++)
  {
    aux = A[i];
    j = i - 1;
    while ((j >= 0) && (aux.getKey() < A[j].getKey()))
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = aux;
  }
}

void SelectionSort(ItemLoaded *A, int i, int j, int* mtrs)
{
  int Min, comps =0, swaps = 0;
  mtrs[0] = 0;
  mtrs[1] = 0;
  for (int k = i; k <= j - 1; k++)
  {
    Min = k;
    for (int p = k + 1; p <= j; p++)
    {
      if (A[p].getKey() < A[Min].getKey())
      {
        comps++;
        Min = p;
      }
    }
    Swap(A[k], A[Min]);
    swaps += 3 /*2nd metric: Copies between registry*/;
  }
  mtrs[0] = comps;
  mtrs[1] = swaps;
}

void generateRealNumber(double &number)
{
  number = ((double)std::rand()) / (RAND_MAX);
}

void generateAlphaNumeric(char *val)
{
  char ch;
  for (int k = 0; k < 200; k++)
  {
    ch = rand() % 94 + 32;
    val[k] = ch;
  }
}