#include "item_loaded.hpp"
#include "quicksort.hpp"
#include "methods.hpp"

#ifndef QUICKSORTSELECTION_H
#define QUICKSORTSELECTION_H


class QuickSortSelection : public QuickSort<ItemLoaded> {
    public:
        QuickSortSelection(ItemLoaded *A, int n, int k);
    protected:
        void Order(int left, int right, ItemLoaded *A) override;
    private:
        int subvecSizes;
};

#endif