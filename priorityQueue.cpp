#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int N, K, M;
vector<int> arr;
priority_queue<int> sums;

void queueClear() {
    while (!sums.empty()) {
        sums.pop();
    }
}

void printVector(vector<int> arr) {
    for (int i=0; i<int(arr.size()); i++) {
        if (i!=int(arr.size())-1) {
            cout << arr[i] << " ";
        }
        else {
            cout << arr[i] << endl;
        }
    }
}

void printQueue() {
    for (int i=0; i<M; i++) {
        cout << sums.top() << " ";
        sums.pop();
    }
    cout << endl;
}

void readInput() {
    cin >> N;
    cin >> K;
    cin >> M;
    //cout << "N: " << N << endl;
    //cout << "K: " << K << endl;
    //cout << "M: " << M << endl;
    int x;
    arr.clear();
    queueClear();
    for (int i=0; i<N; i++) {
        cin >> x;
        arr.push_back(x);
    }
    //cout << "arr: "; 
    //printVector(arr);
}

void computeQueue() {
    int currSum = 0;
    for (int i=0; i<K; i++) {
        currSum+=arr[i];
    }
    sums.push(currSum);
    //cout << "currSum: " << currSum << endl;
    //cout << "queue: ";
    int prevSum = currSum;
    for (int i=K; i<int(arr.size()); i++) {
        currSum = prevSum - arr[i-K]+arr[i];
        prevSum = currSum;
        //cout << "currSum: " << currSum << endl;
        //cout << "queue: ";
        sums.push(currSum);
    }
}

void oneTest() {
    readInput();
    computeQueue();
    printQueue();
}

int main() {
    int T;
    cin >> T;
    //cout << "T: "<< T << endl;
    for (int i=0; i<T; i++) {
        oneTest();
    }
}