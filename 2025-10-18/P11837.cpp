/*
    Created: 10/22/2025
    Solved: 10/23/2025
*/

#include <iostream>
#include <algorithm>

using namespace std;

int a[200005];

/*
    var-list
    a = the number list
    N = length of the number list
    t = temporary value
    m = missing value of [0, i-1]
*/

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i ++) {
        int t;
        cin >> t;
        if (t <= N) {
            a[t] ++;
        }
    }
    int m = 0; 
    for (int i = 0; i < N + 1; i ++) {
        cout << max(m, a[i]) << endl;
        if (a[i] == 0) {
            m ++;
        }
    }
}