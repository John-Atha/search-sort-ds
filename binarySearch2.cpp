#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/* global variables */
int N, Q;
/* the main vector */
vector<int> a;
/* a vector keeping the sums, calculating them in O(N), such as that: sum of larger elements of a[i] = sums[N-1-i]*/
vector<int> sums;

/* initialize the main vector A*/
void initA() {
    a.clear();
    //cout << "N: " << endl;
    cin >> N;
    //cout << "a[]: " << endl;
    for (int i=0; i<N; i++) {
        int j;
        cin >> j;
        a.push_back(j);
    }
    sort(a.begin(), a.end());
}

/* initialize vector of sums */
void initSums() {
    sums.clear();
    int prev=0;
    for (int i=0; i<N; i++) {
        prev = prev + a[N-1-i];
        sums.push_back(prev);
    }
}

int BS(int start, int end, int q) {
    
    // should not happen
    if (start>end) {
        return -1;
    }

    // we reached a result
    else if (start==end) {
        if (a[start]>q) {
            return start;
        }
        return -1;
    }

    // normal case
    else {
        int middle = start + (end-start)/2;
        if (q < a[middle]) {
            return BS(start, middle, q);
        }
        else {
            return BS(middle+1, end, q);
        }
    }

}

/* calculates with BS the index of the smallest larger element than q in tha vector A*/
int findIndex(int q) {
    int index =  BS(0, N-1, q);
    //cout << "index:" << index << endl;
    return index;
}

void init() {
    initA();
    initSums();
}

void solve() {
    init();
    int q;
    //cout << "Q: " << endl;
    cin >> Q;
    //cout << "Q[]: " << endl;
    for (int i=0; i<Q; i++) {
        cin >> q;
        int index = findIndex(q);
        if (index!=-1) {
            cout << sums[N-1-findIndex(q)] << endl;           
        }
        else {
            cout << 0 << endl;
        }
    }
}

int main() {
    int T;
    cin >> T;
    //cout << "T: " << T << endl;
    for (int i=0; i<T; i++) {
        //cout << "Test case: " << i+1 << endl;
        solve();
    }    
}