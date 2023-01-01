#include "item_loaded.hpp"
#include <sys/resource.h>

#ifndef MERGESORT_H
#define MERGESORT_H

template <class ItemClass>

class MergeSort
{
public:
  MergeSort();
  MergeSort(ItemClass *A, int n);
  void Order(ItemClass *A, int i, int j);
  void merge(ItemClass *A, int p, int q, int r);
  int comparisions = 0, swaps = 0, rc = 0;
  double utime = 0, stime = 0, total_time = 0;
};

#endif