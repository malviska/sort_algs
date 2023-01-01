#include "heapsort.hpp"

template <class ItemClass>

void HeapSort<ItemClass>::make(int left, int right, ItemClass *A)
{
  int i, j;
  ItemClass x;
  i = left;
  j = i * 2;
  x = A[i];
  swaps++;
  while (j <= right)
  {
    if (j < right)
      if (A[j].getKey() < A[j + 1].getKey())
      {
        j++;
        comparisions++;
      }
    if (x.getKey() >= A[j].getKey())
    {
      comparisions++;
      break;
    }
    swaps++;
    A[i] = A[j];
    i = j;
    j = i * 2;
  }
  swaps++;
  A[i] = x;
}

template <class ItemClass>

void HeapSort<ItemClass>::HeapBuild(ItemClass *A, int n)
{
  int left;
  left = n / 2 + 1;
  while (left > 0)
  {
    left--;
    make(left, n, A);
  }
}

template <class ItemClass>

HeapSort<ItemClass>::HeapSort(ItemClass *A, int n)
{
  struct rusage resources;
  if ((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
    perror("getrusage failed");
  double utimeStart = (double)resources.ru_utime.tv_sec + 1.e-6 * (double)resources.ru_utime.tv_usec;
  double stimeStart = (double)resources.ru_stime.tv_sec + 1.e-6 * (double)resources.ru_stime.tv_usec;

  int left, right;
  ItemClass x;
  HeapBuild(A, n); /* constroi o heap */
  left = 0;
  right = n;
  while (right > 0)
  { /* ordena o vetor */
    x = A[0];
    A[0] = A[right];
    A[right] = x;
    right--;
    swaps += 3;
    make(left, right, A);
  }
  if ((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
    perror("getrusage failed");
  double utimeEnd = (double)resources.ru_utime.tv_sec + 1.e-6 * (double)resources.ru_utime.tv_usec;
  double stimeEnd = (double)resources.ru_stime.tv_sec + 1.e-6 * (double)resources.ru_stime.tv_usec;
  utime = utimeEnd - utimeStart;
  stime = stimeEnd - stimeStart;
  total_time = utime + stime;
}

template <class ItemClass>
HeapSort<ItemClass>::HeapSort() {}

template class HeapSort<ItemLoaded>;