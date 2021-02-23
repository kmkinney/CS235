#include <iostream>
using namespace std;

const size_t size = 5;


int sum_major_diagonal(int matrix[size][size]) {
}

int sum_minor_diagonal(int matrix[size][size]) {
}

int sum_lower_triangle(int matrix[size][size]) {
}

int sum_upper_triangle(int matrix[size][size]) {
}

int main() {
  int matrix[][size] = {{ 1,  2,  3,  4, 15},
		        { 6,  7,  8,  9, 10},
		        {11, 12, 13, 14, 15},
		        {16, 17, 18, 19, 20},
		        {21, 22, 23, 24, 25}};

  cout << "Sum of major diagonal " << sum_major_diagonal(matrix) << endl;
  cout << "Sum of minor diagonal " << sum_minor_diagonal(matrix) << endl;
  cout << "Sum of lower triangle " << sum_lower_triangle(matrix) << endl;
  cout << "Sum of upper triangle " << sum_upper_triangle(matrix) << endl;
}

