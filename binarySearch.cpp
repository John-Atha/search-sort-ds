#include <iostream>
using namespace std;

class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    
    int BS(int arr[], int start, int end, int K) {
        if (end<start) {
            return -1;
        }
        else if (end==start) {
            if (arr[start]==K) {
                return 1;
            }
            return -1;
        }
        else {
            int middle = ((end-start)/2) + start;
            if (arr[middle]==K) {
                return 1;
            }
            else if (arr[middle]>K) {
                return BS(arr, start, middle-1, K);
            }
            else {
                return BS(arr, middle+1, end, K);
            }
        }
    }
    
    int searchInSorted(int arr[], int N, int K) {
        return BS(arr, 0, N-1, K);                
    }
};