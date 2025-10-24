/*
    Created: 10/24/2025
    Solved: 10/24/2025
*/

#include <iostream>
#include <algorithm>

using namespace std;

/*
    var-list
    n = number of people
    p = people struct
    i = original index
    t = time spent
    tt = total time spent
    a = list
*/

int n;
long long tt = 0;
struct p {
    int i, t;
};
p a[1005];

bool cmp(p a, p b) {
    if (a.t != b.t) return a.t < b.t;
    return a.i < b.i;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i].t;
        a[i].i = i + 1;
    }
    sort(a, a+n, cmp);
    for (int i = 0; i < n; i ++) {
        cout << a[i].i << " ";
        tt += a[i].t * (n - 1 - i);
    }
    cout << endl;
    printf("%.2f\n", (double)tt/n);
    return 0;
}