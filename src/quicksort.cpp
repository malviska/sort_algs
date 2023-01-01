#include "quicksort.hpp"
#include "item_loaded.hpp"

template <class ClassItem>

void QuickSort<ClassItem>::Partition(int left, int right, int *i, int *j, ClassItem *A)
{
  ClassItem x, w;
  *i = left;
  *j = right;
  x = A[(*i + *j) / 2]; /* obtem o pivo x */
  do
  {
    while (x.getKey() > A[*i].getKey())
    {
      (*i)++;
      comparisions++;
    };
    while (x.getKey() < A[*j].getKey())
    {
      (*j)--;
      comparisions++;
    };
    comparisions += 2;
    if (*i <= *j)
    {
      w = A[*i];
      A[*i] = A[*j];
      A[*j] = w;
      (*i)++;
      (*j)--;
      swaps += 3;
    }
  } while (*i <= *j);
}

template <class ClassItem>

void QuickSort<ClassItem>::Order(int left, int right, ClassItem *A)
{
  int i, j;
  Partition(left, right, &i, &j, A);
  if (left < j)
    Order(left, j, A);
  if (i < right)
    Order(i, right, A);
}

template <class ClassItem>

QuickSort<ClassItem>::QuickSort(ClassItem *A, int n)
{
  struct rusage resources;
  if ((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
    perror("getrusage failed");
  double utimeStart = (double)resources.ru_utime.tv_sec + 1.e-6 * (double)resources.ru_utime.tv_usec;
  double stimeStart = (double)resources.ru_stime.tv_sec + 1.e-6 * (double)resources.ru_stime.tv_usec;

  Order(0, n - 1, A);

  if ((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
    perror("getrusage failed");
  double utimeEnd = (double)resources.ru_utime.tv_sec + 1.e-6 * (double)resources.ru_utime.tv_usec;
  double stimeEnd = (double)resources.ru_stime.tv_sec + 1.e-6 * (double)resources.ru_stime.tv_usec;
  utime = utimeEnd - utimeStart;
  stime = stimeEnd -stimeStart;
  total_time = utime + stime;
}

template <class ClassItem>

QuickSort<ClassItem>::QuickSort()
{
}

template class QuickSort<ItemLoaded>;
