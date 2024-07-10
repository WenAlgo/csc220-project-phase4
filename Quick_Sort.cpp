#include <iostream>
using namespace std;
#include <time.h>
#include <vector>

struct order {              //This is to split the vector based on the pivot. So #'s less than will go to the left vector, vice versa
  vector<int> left;
  vector<int> right;
};
//QUICK SORT FUNCTION  
void quick(vector<int> &F, int size, int pivot, vector<int> &Orig, int &count) {
  if (size == 0) {          //Base case
    return;
  }
  //seperating #'s into left and right vectors
  order *split = new order();               //we create an order struct that has 2 vectors, left and right
  for (int i = 0; i < size - 1; i++) {      //here we iterate through the vector and seperate the #'s into their appropiate vectors
    if (F[i] <= pivot) {  
      split->left.push_back(F[i]);
    } 
    else {
      split->right.push_back(F[i]);
    }
  }
//recuring through left and right vectors & sorting original vector
  if (!split->left.empty()) {     //if the left vector is not empty, we can send the left vector to continue sorting through
    quick(split->left, split->left.size(), split->left[split->left.size() - 1], Orig, count);    
  }
  Orig[count] = pivot;            //after the left side is dealt with the pivot is always greater than the left vectors, and less than the right vector. Here we edit the origional vector. 
  count++;                        //count is to keep track of the indexes in the original vector.
  if (!split->right.empty()) {    // if the right vector is empty, we can send the right vector to contine srting throug
    quick(split->right, split->right.size(), split->right[split->right.size() - 1], Orig, count);
  }
  delete split;          
}

// MAIN
int main() {
  // sorted
  vector<int> a = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int c_a = 0;        //conunt
  clock_t start1 = clock();
  quick(a, a.size(), a[a.size() - 1], a, c_a);
  clock_t end1 = clock();
  cout << "a sorted: ";
  for (int i : a) {cout << i << " ";}
  cout << endl<< "Execution time for sorted: "<< double(end1 - start1) / CLOCKS_PER_SEC << " secs" << endl<< endl;
  // reverse sorted
  vector<int> b = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1};
  int c_b = 0;
  clock_t start2 = clock();
  quick(b, b.size(), b[b.size() - 1], b, c_b);
  clock_t end2 = clock();
  cout << "b sorted: ";
  for (int i : b) {cout << i << " ";}
  cout << endl<< "Execution time for reverse sorted: "<< double(end2 - start2) / CLOCKS_PER_SEC << " secs" << endl<< endl;
  // random
  vector<int> c = {12, 45,  23, 56, 34, 89, 77, 19, 4,  91, 85, 100, 72, 64, 50, 93, 80, 17, 44, 57};
  int c_c = 0;
  clock_t start3 = clock();
  quick(c, c.size(), c[c.size() - 1], c, c_c);
  clock_t end3 = clock();
  cout << "c sorted: ";
  for (int i : c) {cout << i << " ";}
  cout << endl<< "Execution time for random: "<< double(end3 - start3) / CLOCKS_PER_SEC << " secs" << endl<< endl;

  return 0;
}
