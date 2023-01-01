#include "item_loaded.hpp"
#include "quicksort_stack.hpp"
#include "methods.hpp"

#ifndef QUICKSORTSTACKSMART_H
#define QUICKSORTSTACKSMART_H

class QuickSortStackSmart : public QuickSortStack
{
public:
  QuickSortStackSmart(ItemLoaded *A, int n);
};

#endif