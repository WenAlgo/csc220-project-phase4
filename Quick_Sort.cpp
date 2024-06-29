#include <iostream>
using namespace std;
#include <chrono>
#include <vector>

struct order {
  vector<int> left;
  vector<int> right;
};

void quick(vector<int> &F, int size, int pivot) {
  if (size == 0) {
    return;
  }

  order *idk = new order();
  for (int i = 0; i < size - 1; i++) {
    if (F[i] <= pivot) {
      idk->left.push_back(F[i]);
    } else {
      idk->right.push_back(F[i]);
    }
  }

  if (!idk->left.empty()) {
    quick(idk->left, idk->left.size(), idk->left[idk->left.size() - 1]);
  }
  cout << pivot << " ";
  if (!idk->right.empty()) {
    quick(idk->right, idk->right.size(), idk->right[idk->right.size() - 1]);
  }
}
// MAIN
int main() {
  vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout << "a sorted: ";
  auto start1 = std::chrono::high_resolution_clock::now(); // Start time
  quick(a, a.size(), a[a.size() - 1]);
  cout << endl;
  auto end1 = std::chrono::high_resolution_clock::now(); // End time
  std::chrono::duration<double> duration1 = end1 - start1;
  std::cout << "Execution time: " << duration1.count() << " seconds"
            << std::endl;
  cout << endl;

  vector<int> b = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  cout << "b sorted: ";
  auto start2 = std::chrono::high_resolution_clock::now(); // Start time
  quick(b, b.size(), b[b.size() - 1]);
  auto end2 = std::chrono::high_resolution_clock::now(); // End time
  std::chrono::duration<double> duration2 = end2 - start2;
  std::cout << endl
            << "Execution time: " << duration2.count() << " seconds"
            << std::endl;
  cout << endl;

  vector<int> c = {12, 45, 23, 56, 34, 89, 77, 19, 4};
  cout << "c sorted: ";
  auto start3 = std::chrono::high_resolution_clock::now(); // Start time
  quick(c, c.size(), c[c.size() - 1]);
  auto end3 = std::chrono::high_resolution_clock::now(); // End time
  std::chrono::duration<double> duration3 = end3 - start3;
  std::cout << endl
            << "Execution time: " << duration3.count() << " seconds"
            << std::endl;
  cout << endl;

  return 0;
}
