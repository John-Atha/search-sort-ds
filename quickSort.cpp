// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;    
}

/* Function to print an array */
void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


/*  picks as pivot the last element of the array
    when it is finished:
        * all elements smaller than pivot are before it
        * all elements larger than pivot are after it 
        * the pivot element is in the correct position (same as the final sorted array)  */    
int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j=low; j<high; j++) {
        if (arr[j]<pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, high);
    return i+1;        
}

void quickSort(int arr[], int low, int high) {
    if (low<high) {
        int pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index-1);
        quickSort(arr, pivot_index+1, high);
    }
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    quickSort(arr, 0, 7-1);
    cout << "final answer:";
    printArray(arr, 7);
}