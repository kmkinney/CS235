/** Driver function to test all sorts. */

#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include "Random.h"
#include "BubbleSort.h"
#include <utility>
#include "HeapSort.h"
#include "InsertionSort3.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "SelectionSortArray.h"
#include "ShellSort2.h"
#include "QuickSort.h"
#include <ctime>

using namespace std;

typedef void (*psort)(int*, size_t);

psort sorts[] = {KW::selection_sort_array
		 , KW::bubble_sort<int>
		 , KW::insertion_sort3<int>
		 , KW::shell_sort2<int>
		 , KW::merge_sort<int>
		 , KW::heap_sort<int>
		 , KW::quick_sort<int> 
};

char* sort_names[] = {"selection_sort"
		      ,
		      "bubble_sort"
		      ,
		      "insertion_sort3"
		      ,
		      "shell_sort2"
		      ,
		      "merge_sort"
		      ,
		      "heap_sort"
		      ,
		      "quick_sort"
};

const int num_sorts = sizeof(sort_names)/sizeof(char*);

template<typename RI>
  bool verify(RI first, RI last);

template<typename RI>
  void dump_table(RI first, RI last);

int main(int argc, char* argv[]) {
  vector<int> aVec;
  int num_items;
  Random rand;
  if (argc < 2) {
    // Fill vector aVec with random numbers.
    cout << "Enter vector size: ";
    cin >> num_items;
    for (int i = 0; i < num_items; i++) {
      aVec.push_back(rand.next_int(2 * num_items));
    }
  } else {
    ifstream in(argv[1]);
    int num;
    while (in >> num)
      aVec.push_back(num);
    num_items = aVec.size();
  }
  vector<int> copyVec = aVec;   // A copy of aVec.

  // Sort and verify using standard sorting algorithm.
  long int start = clock();
  int* begin = &(*copyVec.begin());
  int* end = begin + copyVec.size();
  std::sort(begin, end);
  cout << "time for standard sort: " << (clock() - start) << endl;
  if (verify(copyVec.begin(),copyVec.end()))
    cout << "standard sort successful\n";
  else {
    cout << "standard sort failed\n";
    dump_table(copyVec.begin(), copyVec.end());
  }
  

  // Sort and verify using KW sorting functions.
  for (int i = 0; i < num_sorts; i++) {
    copyVec = aVec;
    start = clock();
    sorts[i](&(*copyVec.begin()), copyVec.size());
    cout << "time for KW sort: " << sort_names[i] << "  "
	 << (clock() - start) << endl;
    if (verify(copyVec.begin(), copyVec.end()))
      cout << "KW sort successful\n";
    else {
      cout << "KW sort failed\n";
      dump_table(copyVec.begin(), copyVec.end());
    }
  }
  return 0;
}

template<typename RI>
  bool verify(RI first, RI last) {
  while (first != last - 2) {
    if (*(first + 1) < *first)
      return false;
    ++first;
  }
  return true;
}

template<typename RI>
  void dump_table(RI first, RI last) {
  while (first != last) {
    cout << *first++ << endl;
  }

}
