#include "item_loaded.hpp"
#include "quicksort.hpp"
#include "methods.hpp"

#ifndef QUICKSORTSTACK_H
#define QUICKSORTSTACK_H

class QuickSortStack : public QuickSort<ItemLoaded>
{
public:
  QuickSortStack();
  ~QuickSortStack();
  QuickSortStack(ItemLoaded *A, int n);
protected:
  void Pile(Index item);
  Index Unstack();
  Index * stack;
  int stackSize = -1;
};

#endif