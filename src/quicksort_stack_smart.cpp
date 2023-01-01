#include "quicksort_stack_smart.hpp"

QuickSortStackSmart::QuickSortStackSmart(ItemLoaded *A, int n)
{
  struct rusage resources;
  if ((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
    perror("getrusage failed");
  double utimeStart = (double)resources.ru_utime.tv_sec + 1.e-6 * (double)resources.ru_utime.tv_usec;
  double stimeStart = (double)resources.ru_stime.tv_sec + 1.e-6 * (double)resources.ru_stime.tv_usec;
  stack = new Index[n - 1];
  Index index;
  int left = 0, right = n - 1, i, j;
  index.left = left;
  index.right = right;
  Pile(index);
  do
    if (right > left)
    {
      Partition(left, right, &i, &j, A);
      if ((j - left) > (right - i))
      {
        index.right = j;
        index.left = left;
        Pile(index);
        left = i;
      }
      else
      {
        index.left = i;
        index.right = right;
        Pile(index);
        right = j;
      }
    }
    else
    {
      index = Unstack();
      right = index.right;
      left = index.left;
    }
  while (stackSize > -1);
  if ((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
    perror("getrusage failed");
  double utimeEnd = (double)resources.ru_utime.tv_sec + 1.e-6 * (double)resources.ru_utime.tv_usec;
  double stimeEnd = (double)resources.ru_stime.tv_sec + 1.e-6 * (double)resources.ru_stime.tv_usec;
  utime = utimeEnd - utimeStart;
  stime = stimeEnd - stimeStart;
  total_time = utime + stime;
}
