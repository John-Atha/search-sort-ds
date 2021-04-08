#include <iostream>
using namespace std;
#include <vector>

void solve() {
    int N;
    cin >> N;
    vector<int> arr;
    for (int j=0; j<N; j++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    for (int j=0; j<N-1; j++) {
        bool found=false;
        for (int k=j+1; k<N; k++) {
            if (arr[k]<arr[j]) {
                cout << k+1 << " ";
                found=true;
                break;
            }
        }
        if (!found) {
            cout << "-1 ";
        }
    }
    cout << "-1" << endl;
}


int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        solve();
    }
}