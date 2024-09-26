// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
//  Modify     [2023/9/12 Ming-Bang Fan]
//  Modify     [2024/9/2 Meng-Chen Wu]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>
// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
        for(int i = 1; i <= (data.size() - 1); i++) {
            int key = data[i];
            int j = i - 1;
            while(j >= 0 && data[j] > key) {
                    data[j + 1] = data[j];
                    j -= 1;
            }
            data[j + 1] = key;
        }
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data,int f){
    QuickSortSubVector(data, 0, data.size() - 1, f);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high, const int flag) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    // flag == 0 -> normal QS
    // flag == 1 -> randomized QS
    if(low < high) {
        int split = 0;
        if(flag == 0) {
            split = Partition(data, low, high);
        } else {
            split = RandomizedPartition(data, low, high);
        }
        QuickSortSubVector(data, low, split, flag);
        QuickSortSubVector(data, split + 1, high, flag);
    }
}
int SortTool::RandomizedPartition(vector<int>& data, int low, int high){
    // Function : RQS's Partition the vector 
    // TODO : Please complete the function
    int key = rand() % (high - low + 1) + low;
    int temp = data[high];
    data[high] = data[key];
    data[key] = temp;

    temp = key;
    key = high;
    high = temp;    // reallocate the index for readability

    int j = low;
    for(int i = low; i < high; i++) {
        if(data[i] <= data[key]) {
            temp = data[i];
            data[i] = data[j];
            j++;
        }
    }
    temp = data[j];
    data[j] = data[key];
    data[key] = temp;
    return j;   // new split point
}
int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    int key = high;
    int temp = 0;
    int j = low;
    for(int i = low; i < high; i++) {
        if(data[i] <= data[key]) {
            temp = data[i];
            data[i] = data[j];
            j++;
        }
    }
    temp = data[j];
    data[j] = data[key];
    data[key] = temp;
    return j;   // new split point
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if(low < high) {
        int middle1 = (low + high) / 2;
        int middle2 = middle1 + 1;
        MergeSortSubVector(data, low, middle1);
        MergeSortSubVector(data, middle2, high);
        Merge(data, low, middle1, middle2, high);
    }
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    int INT_MAX = 2147483647;
    vector<int> L;
    vector<int> R;
    for(int i = low; i <= middle1; i++) {
        L.push_back(data[i]);
    }
    for(int i = middle2; i <= high; i++) {
        R.push_back(data[i]);
    }
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    int i = 0;
    int j = 0;
    int k = low;
    while(i < L.size() - 1 || j < R.size() - 1) {
        if(L[i] <= R[j] && !(L[i] == INT_MAX && R[j] == INT_MAX)) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }
}

// bottom-up style implementation of merge sort
void SortTool::BottomUpMergeSort(vector<int>& data) 
{
  /*TODO :
    Implement merge sort in bottom-up style, in other words,
    without recursive function calls.
    Hint: 
    1. Divide data to n groups of one data each group
    2. Iteratively merge each pair of 2 neighbor groups into one larger group
    3. Finally we obtain exactly one sorted group
  */
}

// Heap sort method, be aware that you are NOT required to implement heap sort in PA1
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
}
