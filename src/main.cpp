/*!!!ATTENTION: THE BINARY DATA ARE MADE ON BIN!!!*/

#include <cstring>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include "quicksort.hpp"
#include "quicksort_median.hpp"
#include "quicksort_selection.hpp"
#include "quicksort_stack.hpp"
#include "quicksort_stack_smart.hpp"
#include "mergesort.hpp"
#include "heapsort.hpp"

void quicksort(ItemLoaded *A, int size, int k, int m, QuickSort<ItemLoaded> &metrics)
{
  metrics = QuickSort<ItemLoaded>(A, size);
}

void quicksort_median(ItemLoaded *A, int size, int k, int m, QuickSort<ItemLoaded> &metrics)
{
  metrics = QuickSortMedian(A, size, k);
}

void quicksort_selection(ItemLoaded *A, int size, int k, int m, QuickSort<ItemLoaded> &metrics)
{
  metrics = QuickSortSelection(A, size, m);
}

void quicksort_stack(ItemLoaded *A, int size, int k, int m, QuickSort<ItemLoaded> &metrics)
{
  metrics = QuickSortStack(A, size);
}

void quicksort_stack_smart(ItemLoaded *A, int size, int k, int m, QuickSort<ItemLoaded> &metrics)
{
  metrics = QuickSortStackSmart(A, size);
}

void parseArgs(int argc, char **argv, char **A)
{
  int opt;
  while ((opt = getopt(argc, argv, "v:s:k:m:i:o:")) != -1)
  {
    switch (opt)
    {
    case 'v':
      A[0] = optarg;
      break;
    case 's':
      A[1] = optarg;
      break;
    case 'i':
      A[2] = optarg;
      break;
    case 'o':
      A[3] = optarg;
      break;
    case 'k':
      A[4] = optarg;
      break;
    case 'm':
      A[5] = optarg;
      break;
    case '?':
      printf("Invalid Option: %c", optopt);
      break;
    }
  }
}

/*As funções abaixo escrevem no arquivo output*/

void HeapSortWrite(std::ifstream& input, std::ofstream& output, int name, int k, int m){
  std::string val;
  while (getline(input, val))
  {
    ItemLoaded *unorderedArray;
    int size = std::stoi(val);
    unorderedArray = new ItemLoaded[size];
    for (int i = 0; i < size; i++)
    {
      unorderedArray[i].generate(size);
    }
    HeapSort<ItemLoaded> metrics = HeapSort<ItemLoaded>(unorderedArray, size);
    output << name << ","
           << k << ","
           << m << ","
           << size << ","
           << metrics.comparisions << ","
           << metrics.swaps << ","
           << metrics.stime << ","
           << metrics.utime << ","
           << metrics.total_time << "\n";
    delete[] unorderedArray;
  }
  input.close();
  output.close();
}

void MergeSortWrite(std::ifstream& input, std::ofstream& output, int name, int k, int m){
  std::string val;
  while (getline(input, val))
  {
    ItemLoaded *unorderedArray;
    int size = std::stoi(val);
    unorderedArray = new ItemLoaded[size];
    for (int i = 0; i < size; i++)
    {
      unorderedArray[i].generate(size);
    }
    MergeSort<ItemLoaded> metrics =  MergeSort<ItemLoaded>(unorderedArray, size);
    output << name << ","
           << k << ","
           << m << ","
           << size << ","
           << metrics.comparisions << ","
           << metrics.swaps << ","
           << metrics.stime << ","
           << metrics.utime << ","
           << metrics.total_time << "\n";
    delete[] unorderedArray;
  }
  input.close();
  output.close();
}

void QuickSortWrite(void (*Sort)(ItemLoaded * A, int size, int k, int m, QuickSort<ItemLoaded> &Statistics), std::ifstream& input, std::ofstream& output, int name, int k, int m){
  std::string val;
  while (getline(input, val))
  {
    QuickSort<ItemLoaded> metrics;
    ItemLoaded *unorderedArray;
    int size = std::stoi(val);
    unorderedArray = new ItemLoaded[size];
    for (int i = 0; i < size; i++)
    {
      unorderedArray[i].generate(size);
    }
    Sort(unorderedArray, size, k, m, metrics);
    output << name << ","
           << k << ","
           << m << ","
           << size << ","
           << metrics.comparisions << ","
           << metrics.swaps << ","
           << metrics.stime << ","
           << metrics.utime << ","
           << metrics.total_time << "\n";
    delete[] unorderedArray;
  }
  input.close();
  output.close();
}


int main(int argc, char **argv)
{
  char * Method = argv[1];
  char ** Args = (char **) malloc(6*sizeof(char*));
  for(int k = 0; k<6; k++){
    Args[k] = (char *) malloc(1000*sizeof(char));
  }
  parseArgs(argc, argv, Args);
  std::string val;
  std::ifstream input, outTest;
  std::ofstream output;
  int name = atoi(Args[0]);
  std::srand(atoi(Args[1]));
  input.open(Args[2]);
  output.open(Args[3], std::ios::app);
  int k = atoi(Args[4]);
  int m = atoi(Args[5]);
  outTest.open(Args[3], std::ios::in);
  bool empty = outTest.peek() == EOF;
  if (1 == empty)
  {
    output << "version,k,m,size,comps,swaps,stime,utime,totaltime\n";
  }
  outTest.close();
  if (strcmp(Method, "quicksort") == 0)
  {
    switch (atoi(Args[0]))
    {
    case 1:
      QuickSortWrite(&quicksort, input, output, name, k, m);
      break;
    case 2:
      QuickSortWrite(&quicksort_median, input, output, name, k, m);
      break;
    case 3:
      QuickSortWrite(&quicksort_selection, input, output, name, k, m);
      break;
    case 4:
      QuickSortWrite(&quicksort_stack, input, output, name, k, m);
      break;
    case 5:
     QuickSortWrite(&quicksort_stack_smart, input, output, name, k, m);
      break;
    }
  }
  else if (strcmp(Method, "mergesort") == 0) MergeSortWrite(input, output, 6, k, m);
  else if (strcmp(Method, "heapsort") == 0) HeapSortWrite(input, output, 7, k, m);
  else{
    std::cout<<"Not valid option"<<Method<<"\n";
  }
  free(Args);
  return 0;
}