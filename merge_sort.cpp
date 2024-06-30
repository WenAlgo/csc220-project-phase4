#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Merging two arrays into a sorted array
vector<int> merge(vector<int> array1, vector<int> array2) {
    vector<int> newArray;
    int i = 0, j = 0;

    // Merge array1 and array2 into a sorted newArray
    while (i < array1.size() && j < array2.size()) {
        if (array1[i] <= array2[j]) {
            newArray.push_back(array1[i++]);
        } else {
            newArray.push_back(array2[j++]);
        }
    }

    // Add remaining items of array1 and array2 to newArray
    while (i < array1.size()) {
        newArray.push_back(array1[i++]);
    }
    while (j < array2.size()) {
        newArray.push_back(array2[j++]);
    }

    return newArray;
}

// Merge Sort
vector<int> mergeSort(vector<int> array) {
    // If array has zero or one element, return array immediately
    if(array.size() <= 1) 
        return array;

    // Split the array into two halves
    vector<int> leftArray, rightArray;
    int mid = array.size() / 2;
    for(int i = 0; i < mid; ++i) {
        leftArray.push_back(array[i]);
    }
    for(int i = mid; i < array.size(); ++i) {
        rightArray.push_back(array[i]);
    }

    // Recursively merge two halves into a sorted array
    return merge(mergeSort(leftArray), mergeSort(rightArray));
}

int main() {
    // sorted data
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "a sorted: ";
    auto start1 = std::chrono::high_resolution_clock::now(); // Start time
    mergeSort(a);
    auto end1 = chrono::high_resolution_clock::now(); // End time
    chrono::duration<double> duration1 = end1 - start1;
    cout << "Execution time: " << duration1.count() << " seconds" << endl;
    cout << endl;

    // reverse data
    vector<int> b = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "b sorted: ";
    auto start2 = chrono::high_resolution_clock::now(); // Start time
    mergeSort(b);
    auto end2 = chrono::high_resolution_clock::now(); // End time
    chrono::duration<double> duration2 = end2 - start2;
    cout << "Execution time: " << duration2.count() << " seconds" << endl;
    cout << endl;

    // random data
    vector<int> c = {12, 45, 23, 56, 34, 89, 77, 19, 4};
    cout << "c sorted: ";
    auto start3 = chrono::high_resolution_clock::now(); // Start time
    mergeSort(c);
    auto end3 = chrono::high_resolution_clock::now(); // End time
    chrono::duration<double> duration3 = end3 - start3;
    cout << "Execution time: " << duration3.count() << " seconds" << endl;
    cout << endl;

    return 0;
}
