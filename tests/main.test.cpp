#include "heapsort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
#include "quicksort_median.hpp"
#include "quicksort_selection.hpp"
#include "quicksort_stack.hpp"
#include "quicksort_stack_smart.hpp"
#include "item_loaded.hpp"
#include "methods.hpp"
#include <iostream>

#define SIZE 10000

bool isSorted(ItemLoaded *A, int size)
{
  for (int i = SIZE - 1; i > 0; i--)
  {
    if (A[i - 1].getKey() > A[i].getKey())
      return false;
  }
  return true;
}

int main()
{
  std::cout << "==========UNIT TEST 1==========\n";
  std::cout << "SORTING ARRAYS BY KEY\nArray Size: " << SIZE << "\n\n";
  std::srand(100034);
  ItemLoaded *values;
  values = new ItemLoaded[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    values[i].generate(SIZE);
  }
  std::cout << "QUICKSORT\n";
  std::string result = isSorted(values, SIZE) == false ? "Random Unsorted Vec generated" : "Random Sorted Vec generated 0_0";
  std::cout << result << "\n";
  QuickSort<ItemLoaded> Statistics = QuickSort<ItemLoaded>(values, SIZE);
  std::cout << "Metrics:\ncomps: " << Statistics.comparisions << "\n"
            << "memory copies: " << Statistics.swaps << "\n"
            << "sysTime: " << Statistics.stime << "\n"
            << "userTime: " << Statistics.utime << "\n"
            << "totalTime: " << Statistics.total_time << "\nSORTED: ";

  result = isSorted(values, SIZE) == true ? "Success!" : "Error!";
  std::cout << result << "\n\n";
  delete[] values;
  std::cout << "QUICKSORT MEDIAN with k = 3\n";
  std::srand(100034);
  values = new ItemLoaded[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    values[i].generate(SIZE);
  }
  result = isSorted(values, SIZE) == false ? "Random Unsorted Vec generated" : "Random Sorted Vec generated 0_0";
  std::cout << result << "\n";
  Statistics = QuickSortMedian(values, SIZE, 3);
  std::cout << "Metrics:\ncomps: " << Statistics.comparisions << "\n"
            << "memory copies: " << Statistics.swaps << "\n"
            << "sysTime: " << Statistics.stime << "\n"
            << "userTime: " << Statistics.utime << "\n"
            << "totalTime: " << Statistics.total_time << "\nSORTED: ";
  result = isSorted(values, SIZE) == true ? "Success!" : "Error!";
  std::cout << result << "\n\n";
  delete[] values;
  std::cout << "QUICKSORT MEDIAN with k = 5\n";
  std::srand(100034);
  values = new ItemLoaded[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    values[i].generate(SIZE);
  }
  result = isSorted(values, SIZE) == false ? "Random Unsorted Vec generated" : "Random Sorted Vec generated 0_0";
  std::cout << result << "\n";
  Statistics = QuickSortMedian(values, SIZE, 5);
  std::cout << "Metrics:\ncomps: " << Statistics.comparisions << "\n"
            << "memory copies: " << Statistics.swaps << "\n"
            << "sysTime: " << Statistics.stime << "\n"
            << "userTime: " << Statistics.utime << "\n"
            << "totalTime: " << Statistics.total_time << "\nSORTED: ";
  result = isSorted(values, SIZE) == true ? "Success!" : "Error!";
  std::cout << result << "\n\n";
  delete[] values;
  std::cout << "QUICKSORT MEDIAN with k = 7\n";
  std::srand(100034);
  values = new ItemLoaded[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    values[i].generate(SIZE);
  }
  result = isSorted(values, SIZE) == false ? "Random Unsorted Vec generated" : "Random Sorted Vec generated 0_0";
  std::cout << result << "\n";
  Statistics = QuickSortMedian(values, SIZE, 7);
  std::cout << "Metrics:\ncomps: " << Statistics.comparisions << "\n"
            << "memory copies: " << Statistics.swaps << "\n"
            << "sysTime: " << Statistics.stime << "\n"
            << "userTime: " << Statistics.utime << "\n"
            << "totalTime: " << Statistics.total_time << "\nSORTED: ";
  result = isSorted(values, SIZE) == true ? "Success!" : "Error!";
  std::cout << result << "\n\n";
  delete[] values;
  std::cout << "QUICKSORT SELECTION with m = 10\n";
  std::srand(100034);
  values = new ItemLoaded[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    values[i].generate(SIZE);
  }
  result = isSorted(values, SIZE) == false ? "Random Unsorted Vec generated" : "Random Sorted Vec generated 0_0";
  std::cout << result << "\n";
  Statistics = QuickSortSelection(values, SIZE, 10);
  std::cout << "Metrics:\ncomps: " << Statistics.comparisions << "\n"
            << "memory copies: " << Statistics.swaps << "\n"
            << "sysTime: " << Statistics.stime << "\n"
            << "userTime: " << Statistics.utime << "\n"
            << "totalTime: " << Statistics.total_time << "\nSORTED: ";
  result = isSorted(values, SIZE) == true ? "Success!" : "Error!";
  std::cout << result << "\n\n";
  delete[] values;
  std::cout << "QUICKSORT SELECTION with m = 100\n";
  std::srand(100034);
  values = new ItemLoaded[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    values[i].generate(SIZE);
  }
  result = isSorted(values, SIZE) == false ? "Random Unsorted Vec generated" : "Random Sorted Vec generated 0_0";
  std::cout << result << "\n";
  Statistics = QuickSortSelection(values, SIZE, 100);
  std::cout << "Metrics:\ncomps: " << Statistics.comparisions << "\n"
            << "memory copies: " << Statistics.swaps << "\n"
            << "sysTime: " << Statistics.stime << "\n"
            << "userTime: " << Statistics.utime << "\n"
            << "totalTime: " << Statistics.total_time << "\nSORTED: ";
  result = isSorted(values, SIZE) == true ? "Success!" : "Error!";
  std::cout << result << "\n\n";
  delete[] values;
  std::cout << "QUICKSORT STACK\n";
  std::srand(100034);
  values = new ItemLoaded[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    values[i].generate(SIZE);
  }
  result = isSorted(values, SIZE) == false ? "Random Unsorted Vec generated" : "Random Sorted Vec generated 0_0";
  std::cout << result << "\n";
  Statistics = QuickSortStack(values, SIZE);
  std::cout << "Metrics:\ncomps: " << Statistics.comparisions << "\n"
            << "memory copies: " << Statistics.swaps << "\n"
            << "sysTime: " << Statistics.stime << "\n"
            << "userTime: " << Statistics.utime << "\n"
            << "totalTime: " << Statistics.total_time << "\nSORTED: ";
  result = isSorted(values, SIZE) == true ? "Success!" : "Error!";
  std::cout << result << "\n\n";
  delete[] values;
  std::cout << "QUICKSORT STACK SMART\n";
  std::srand(100034);
  values = new ItemLoaded[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    values[i].generate(SIZE);
  }
  result = isSorted(values, SIZE) == false ? "Random Unsorted Vec generated" : "Random Sorted Vec generated 0_0";
  std::cout << result << "\n";
  Statistics = QuickSortStackSmart(values, SIZE);
  std::cout << "Metrics:\ncomps: " << Statistics.comparisions << "\n"
            << "memory copies: " << Statistics.swaps << "\n"
            << "sysTime: " << Statistics.stime << "\n"
            << "userTime: " << Statistics.utime << "\n"
            << "totalTime: " << Statistics.total_time << "\nSORTED: ";
  result = isSorted(values, SIZE) == true ? "Success!" : "Error!";
  std::cout << result << "\n\n";

  delete[] values;

  std::cout << "MERGESORT\n";
  std::srand(100034);
  values = new ItemLoaded[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    values[i].generate(SIZE);
  }
  result = isSorted(values, SIZE) == false ? "Random Unsorted Vec generated" : "Random Sorted Vec generated 0_0";
  std::cout << result << "\n";
  MergeSort<ItemLoaded> Metrics = MergeSort<ItemLoaded>(values, SIZE);
  std::cout << "Metrics:\ncomps: " << Metrics.comparisions << "\n"
            << "memory copies: " << Metrics.swaps << "\n"
            << "sysTime: " << Metrics.stime << "\n"
            << "userTime: " << Metrics.utime << "\n"
            << "totalTime: " << Metrics.total_time << "\nSORTED: ";
  result = isSorted(values, SIZE) == true ? "Success!" : "Error!";
  std::cout << result << "\n\n";

  delete[] values;

  std::cout << "HEAPSORT\n";
  std::srand(100034);
  values = new ItemLoaded[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    values[i].generate(SIZE);
  }
  result = isSorted(values, SIZE) == false ? "Random Unsorted Vec generated" : "Random Sorted Vec generated 0_0";
  std::cout << result << "\n";
  HeapSort<ItemLoaded> MetricsNew = HeapSort<ItemLoaded>(values, SIZE);
  std::cout << "Metrics:\ncomps: " << MetricsNew.comparisions << "\n"
            << "memory copies: " << MetricsNew.swaps << "\n"
            << "sysTime: " << MetricsNew.stime << "\n"
            << "userTime: " << MetricsNew.utime << "\n"
            << "totalTime: " << MetricsNew.total_time << "\nSORTED: ";
  result = isSorted(values, SIZE) == true ? "Success!" : "Error!";
  std::cout << result << "\n";
  delete[] values;
}