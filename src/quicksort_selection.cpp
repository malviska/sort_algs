#include "quicksort_selection.hpp"

void QuickSortSelection::Order(int left, int right, ItemLoaded *A)
{
  int i, j;
  int mtrs[2];
  Partition(left, right, &i, &j, A);
  if (left < j)
  {
    if ((j - left) <= subvecSizes)
    {
      SelectionSort(A, left, j, mtrs);
      comparisions += mtrs[0];
      swaps += mtrs[1];
    }
    else
      Order(left, j, A);
  }
  if (i < right)
  {
    if ((right - i) <= subvecSizes)
    {
      SelectionSort(A, i, right, mtrs);
      comparisions += mtrs[0];
      swaps += mtrs[1];
    }
    else
      Order(i, right, A);
  }
}

QuickSortSelection::QuickSortSelection(ItemLoaded *A, int n, int k)
{
  struct rusage resources;
  subvecSizes = k;
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
  stime = stimeEnd - stimeStart;
  total_time = utime + stime;
}