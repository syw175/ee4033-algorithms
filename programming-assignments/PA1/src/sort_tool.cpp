// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>

// Constructor
SortTool::SortTool() {}

// Insertion sort method
// TO RUN TEST CASES
void SortTool::InsertionSort(vector<int>& data)
{
    // Function : Insertion sort
    // Iterate through the vector from the second element to the last element
    for (int i = 1; i < data.size(); i++)
    {
        int temp = data[i];
        // Iterate through the sorted partition from the last to the first element
        int j = i - 1;
        while (j >= 0 && data[j] > temp)
        {
            // Shift the element to the right if it is greater than the current element
            data[j + 1] = data[j];
            j--;
        }
        // At this point, we have either reached the beginning of the array or data[j] <= temp
        data[j + 1] = temp;
    }
    return;
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data)
{
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high)
{
    // Function : Quick sort subvector
    // If low is smaller than high, then there are at least two elements to sort
    if (low < high)
    {
        // Partition the vector into subvectors based on the pivot
        int pivot = Partition(data, low, high);
        // Recursively sort the subvectors
        QuickSortSubVector(data, low, pivot - 1);
        QuickSortSubVector(data, pivot + 1, high);
    }
    return;
}

// UNTESTED
int SortTool::Partition(vector<int>& data, int low, int high)
{
    // Function : Partition the vector 
    int pivot = data[high];
    int i = low - 1;
    // Iterate through the vector from the low index to the high index
    for (int j = low; j < high; j++)
    {
        // If the current element <= pivot, swap it with the elemment at index i + 1 
        if (data[j] <= pivot)
        {
            i++;
            swap(data[i], data[j]);
        }
    }
    // Swap to put the pivot in the correct location
    swap(data[i + 1], data[high]);
    // Return the index of the pivot
    return i + 1;
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data)
{
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high)
{
    // Function : Merge sort subvector
    if (low < high)
    {
        // Calculate the middle index
        int middle = (low + high) / 2;
        // Recursively sort the subvectors
        MergeSortSubVector(data, low, middle);
        MergeSortSubVector(data, middle + 1, high);
        // Merge the two sorted subvectors
        Merge(data, low, middle, middle + 1, high);
    }
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high)
{
    // Function : Merge two sorted subvector
    return;
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data)
{
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--)
    {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
// TO RUN TEST CASES
void SortTool::MaxHeapify(vector<int>& data, int root)
{
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // Calculate index values for left and right child nodes
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int largestIndex = root;

    // If there is only one node in the tree
    if (left >= heapSize && right >= heapSize)
        return;

    // Calculate the largest value between root, left child, and right child
    if (left < heapSize && data[left] > data[largestIndex])
        largestIndex = left;
    if (right < heapSize && data[right] > data[largestIndex])
        largestIndex = right;
    
    // For the case that the root is non-max value, continue heapify
    if (largestIndex != root)
    {
        swap(data[root], data[largestIndex]);
        MaxHeapify(data, largestIndex);
    }
}

//Build max heap
// TO RUN TEST CASES
void SortTool::BuildMaxHeap(vector<int>& data)
{
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // Start from the last parent node and heapify
    for (int i = (heapSize - 1) / 2; i >= 0; i--)
        MaxHeapify(data, i);
}
