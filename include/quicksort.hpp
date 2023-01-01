#include "item.hpp"
#include "item_loaded.hpp"
#include <sys/resource.h>

#ifndef QUICKSORT_H
#define QUICKSORT_H

template <class ClassItem>

class QuickSort
{
public:
  QuickSort();
  QuickSort(ClassItem *A, int n);
  int comparisions = 0; /*First metric: number of key comparisions*/
  int swaps = 0; /*2nd metric: memory swaps (copies between registry)*/
  int rc = 0;
  double utime = 0, stime = 0, total_time = 0; /*3rd metric: time complexity*/

protected:
  virtual void Partition(int left, int right, int *i, int *j, ClassItem *A);
  virtual void Order(int left, int right, ClassItem *A);
};

#endif