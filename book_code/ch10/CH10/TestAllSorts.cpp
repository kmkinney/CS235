/** Driver function to test all sorts. */

#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include "Random.h"
#include "BubbleSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "InsertionSort2.h"
#include "InsertionSort3.h"
#include "InsertionSort4.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "SelectionSortArray.h"
#include "ShellSort.h"
#include "ShellSort2.h"
#include "QuickSort.h"
#include "QuickSort2.h"
#include "DNFQuickSort.h"
#include <ctime>

using namespace std;

typedef void (*psort)(vector<int>::iterator, vector<int>::iterator);

psort sorts[] = {KW::selection_sort<vector<int>::iterator>,
		 KW::bubble_sort<vector<int>::iterator>,
		 KW::insertion_sort<vector<int>::iterator>,
		 KW::insertion_sort2<vector<int>::iterator>,
		 // KW::insertion_sort3<vector<int>::iterator>,
		 // KW::insertion_sort4<vector<int>::iterator>,
		 KW::shell_sort<vector<int>::iterator>,
		 KW::shell_sort2<vector<int>::iterator>,
		 KW::merge_sort<vector<int>::iterator>,
		 KW::heap_sort<vector<int>::iterator>,
		 KW::quick_sort<vector<int>::iterator>,
		 KW::quick_sort2<vector<int>::iterator>
		 //,
		 // KW::DNF_quick_sort<vector<int>::iterator>
};

char* sort_names[] = {"selection_sort",
		      "bubble_sort",
		      "insertion_sort",
		      "insertion_sort2",
		      //  "insertion_sort3",
		      //  "insertion_sort4",
		      "shell_sort",
		      "shell_sort2",
		      "merge_sort",
		      "heap_sort",
		      "quick_sort",
		      "quick_sort2"
		      //,
		      // "DNF_quick_sort"
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
  }
  vector<int> copyVec = aVec;   // A copy of aVec.

  // Sort and verify using standard sorting algorithm.
  long int start = clock();
  std::sort(copyVec.begin(), copyVec.end());
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
    sorts[i](copyVec.begin(), copyVec.end());
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
}
