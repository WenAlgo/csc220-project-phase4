#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

// Merging two arrays into a sorted array
void merge(vector<int> array1, vector<int> array2, vector<int>& newArray) {
    int i = 0, j = 0, k = 0;

    // Merge array1 and array2 into a sorted newArray
    while (i < array1.size() && j < array2.size()) {
        if (array1[i] <= array2[j]) {
            newArray[k++] = array1[i++];
        } else {
            newArray[k++] = array2[j++];
        }
    }

    // Add remaining items of array1 and array2 to newArray
    while (i < array1.size()) {
        newArray[k++] = array1[i++];
    }
    while (j < array2.size()) {
        newArray[k++] = array2[j++];
    }
}

// Merge Sort
void mergeSort(vector<int>& array) {
    // If array has zero or one element, return array immediately
    if(array.size() <= 1) 
        return;

    // Split the array into two halves
    int mid = array.size() / 2;
    vector<int> leftArray(mid); // Initialize leftArray with size mid
    vector<int> rightArray(array.size() - mid); // Initialize rightArray with size array.size() - mid
    
    for(int i = 0; i < mid; ++i) {
        leftArray[i] = array[i];
        // leftArray.push_back(array[i]);
    }
    for(int i = mid; i < array.size(); ++i) {
        rightArray[i - mid] = array[i];
        // rightArray.push_back(array[i]);
    }

    // Recursively merge two halves into a sorted array
    mergeSort(leftArray);
    mergeSort(rightArray);
    merge(leftArray, rightArray, array);
}

int main() {
    // sorted data
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    cout << "a sorted: ";
    clock_t start1 = clock(); // Start time
    mergeSort(a);
    clock_t end1 = clock(); // End time
    for (int i : a) {cout << i << " ";}
    cout << endl << "Execution time for sorted: "
        << double(end1 - start1) / CLOCKS_PER_SEC << " secs" << endl << endl;

    // reverse data
    vector<int> b = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "b sorted: ";
    clock_t start2 = clock(); // Start time
    mergeSort(b);
    clock_t end2 = clock(); // End time
    for (int i : b) {cout << i << " ";}
    cout << endl << "Execution time for reverse sorted: "
        << double(end2 - start2) / CLOCKS_PER_SEC << " secs" << endl<< endl;

    // random data
    vector<int> c = {12, 45, 23, 56, 34, 89, 77, 19, 4, 91, 85, 100, 72, 64, 50, 93, 80, 17, 44, 57};
    cout << "c sorted: ";
    clock_t start3 = clock(); // Start time
    mergeSort(c);
    clock_t end3 = clock(); // End time
    for (int i : c) {cout << i << " ";}
    cout << endl << "Execution time for random: "
        << double(end3 - start3) / CLOCKS_PER_SEC << " secs" << endl << endl;

    return 0;
}
