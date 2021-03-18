#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int min(int a, int b) {
    return a<b ? a : b;
}

void printArr(int arr[], int N) {
    cout << "A[]: " << endl;
    for (int i=0; i<N-1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[N-1] << endl;
}

void print_queue(queue<int> q) {
  queue<int> copy;
  while (!q.empty()) {
    cout << q.front() << " ";
    copy.push(q.front());
    q.pop();
  }
  while (!copy.empty()) {
      q.push(copy.front());
      copy.pop();
  }
  cout << endl;
}

void merge(int arr[], int l, int m, int r) {
        cout << "I am merge with:  l:" << l <<  " m:" << m << " r:" << r << endl;
        printArr(arr, r+1);

        // arr1 : from l to m
        // arr2 : from m+1 to r
        queue<int> q1, q2;
        vector<int> merged;
        int i;
        cout <<"Filling queues: "<< endl;
        cout << "q1 with arr[" << l << "] to (with) arr[" << m <<"]: " << endl;
        for (i=l; i<=m; i++) {
            q1.push(arr[i]);
        }
        cout << "q2 with arr[" << m+1 << "] to (with) arr[" << r <<"]: " << endl;
        for (i=m+1; i<=r; i++) {
            q2.push(arr[i]);
        }
        // merge the arr1 and arr2 which are sorted inside
        /*  arr1: 2 4 7 9 10
            arr2: 1 6 9 18 52 
        */
        int counter = l;
        while(!q1.empty() && !q2.empty()) {
            cout << "q1: " << endl;
            print_queue(q1);
            cout << "q2: " << endl;
            print_queue(q2);
            if (q1.front()<q2.front()) {
                arr[counter]=q1.front();
                q1.pop();
            }
            else {
                arr[counter]=q2.front();
                q2.pop();
            }
            counter++;
        }
        while (!q1.empty()) {
            arr[counter]=q1.front();
            q1.pop();
            counter++;
        }
        while (!q2.empty()) {
            arr[counter]=q2.front();
            q2.pop();
            counter++;
        }
        cout << "I made it to: "<< endl;
        printArr(arr, r+1);
}

void mergeSort(int arr[], int l, int r) {
        cout << "I am mergeSort with:  l:" << l << " r:" << r << endl;
        printArr(arr, r+1);
        if (l==r) {
            return;
        }
        else if (l<r) {
            int middle = l + (r-l)/2;
            mergeSort(arr, l, middle);
            mergeSort(arr, middle+1, r);
            merge(arr, l, middle, r);
        }
}


int main() {
    int A[10];
    //int N = 5;
    A[0]=10;
    A[1]=9;
    A[2]=8;
    A[3]=7;
    A[4]=6;
    A[5]=5;
    A[6]=4;
    A[7]=3;
    A[8]=2;
    A[9]=1;
    mergeSort(A, 0, 9);
}