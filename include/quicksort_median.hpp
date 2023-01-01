
#include"item_loaded.hpp"
#include"quicksort.hpp"

#ifndef QUICKSORTMEDIAN_H
#define QUICKSORTMEDIAN_H


class QuickSortMedian : public QuickSort<ItemLoaded> {
    public:
        QuickSortMedian(ItemLoaded *A, int n, int k);
    protected:
        void Partition(int left, int right, int *i, int *j, ItemLoaded *A);
        int Median(int i, int j, int k);
        int indices;
        int size;
};

#endif