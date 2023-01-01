#include "quicksort_median.hpp"
#include "item_loaded.hpp"
#include "methods.hpp"

void QuickSortMedian::Partition(int left, int right, int *i, int *j, ItemLoaded *A){
  ItemLoaded x, w;
  *i = left;
  *j = right;

  x = A[Median(left, right, indices)];
  do{
    while (x.getKey() > A[*i].getKey())
      {(*i)++; comparisions++;}
    while (x.getKey() < A[*j].getKey())
      {(*j)--; comparisions++;}
    comparisions += 2;
    if (*i <= *j){
      w = A[*i];
      A[*i] = A[*j];
      A[*j] = w;
      (*i)++;
      (*j)--;
      swaps += 3;
    }
  } while (*i <= *j);
}

int QuickSortMedian::Median(int i, int j, int k){
  if(j-i < 3){
    return j;
  }
  Item *values;
  values = new Item[k];
  for (int h = 0; h < k; h++){
    values[h].generate((rand() % (j-i)) + i);
  }
  InsertionSort(values, k);
  int median = values[k / 2].getKey();
  delete [] values;
  return median;
}

QuickSortMedian::QuickSortMedian(ItemLoaded *A, int n, int k){
  struct rusage resources;
  indices = k;
  size = n;
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
