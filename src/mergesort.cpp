#include "mergesort.hpp"

template <class ItemClass>

void MergeSort<ItemClass>::merge(ItemClass *A, int i, int m, int j)
{

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = m - i + 1;
  int n2 = j - m;

  ItemClass *L, *M;
  L = new ItemClass[n1];
  M = new ItemClass[n2];

  for (int d = 0; d < n1; d++)
  {
    L[d] = A[i + d];
    swaps++;
  }
  for (int e = 0; e < n2; e++)
  {
    M[e] = A[m + 1 + e];
    swaps++;
  }

  // Maintain current index of sub-arrays and main array
  int d, e, k;
  d = 0;
  e = 0;
  k = i;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (d < n1 && e < n2)
  {
    if (L[d].getKey() <= M[e].getKey())
    {
      A[k] = L[d];
      d++;
    }
    else
    {
      A[k] = M[e];
      e++;
    }
    comparisions++;
    swaps++;
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (d < n1)
  {
    A[k] = L[d];
    d++;
    k++;
    swaps++;
  }

  while (e < n2)
  {
    A[k] = M[e];
    e++;
    k++;
    swaps++;
  }
  delete[] L;
  delete[] M;
}

template <class ItemClass>

void MergeSort<ItemClass>::Order(ItemClass *A, int i, int j)
{
  if (i < j)
  {
    // m is the point where the array is divided into two subarrays
    int m = i + (j - i) / 2;

    Order(A, i, m);
    Order(A, m + 1, j);

    // Merge the sorted subarrays
    merge(A, i, m, j);
  }
}

template <class ItemClass>

MergeSort<ItemClass>::MergeSort(ItemClass *A, int n)
{
  struct rusage resources;
  if ((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
    perror("getrusage failed");
  double utimeStart = (double)resources.ru_utime.tv_sec + 1.e-6 * (double)resources.ru_utime.tv_usec;
  double stimeStart = (double)resources.ru_stime.tv_sec + 1.e-6 * (double)resources.ru_stime.tv_usec;

  Order(A, 0, n - 1);

  if ((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
    perror("getrusage failed");
  double utimeEnd = (double)resources.ru_utime.tv_sec + 1.e-6 * (double)resources.ru_utime.tv_usec;
  double stimeEnd = (double)resources.ru_stime.tv_sec + 1.e-6 * (double)resources.ru_stime.tv_usec;
  utime = utimeEnd - utimeStart;
  stime = stimeEnd - stimeStart;
  total_time = utime + stime;
}

template <class ItemClass>

MergeSort<ItemClass>::MergeSort()
{
}

template class MergeSort<ItemLoaded>;