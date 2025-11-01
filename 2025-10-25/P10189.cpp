#include <iostream>
#include <algorithm>
using namespace std;

int c[1000005], t[1000005];
int late[1000005];

int main() {
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < N; i++) {
        late[i] = c[i] - t[i];
    }
    sort(late, late + N);
    for (int i = 0; i < Q; i++) {
        int V, S;
        cin >> V >> S;
        int cnt = (late + N) - upper_bound(late, late + N, S);
        if (cnt >= V) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}