#include "item_loaded.hpp"
#include <sys/resource.h>

#ifndef HEAPSORT_H
#define HEAPSORT_H

template <class ItemClass>

class HeapSort
{
public:
  HeapSort();
  HeapSort(ItemClass *A, int size);
  void HeapBuild(ItemClass *A, int n);
  void make(int left, int right, ItemClass *A);
  int comparisions = 0, swaps = 0, rc = 0;
  double utime = 0, stime = 0, total_time = 0;
};

#endif