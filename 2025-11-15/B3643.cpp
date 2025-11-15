#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int edge[maxn][maxn];
vector<int> adj[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int from, to;
        cin >> from >> to;
        edge[from][to] = edge[to][from] = 1;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << edge[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        cout << adj[i].size();
        for (int to:adj[i]) {
            cout << " " << to;
        }
        cout << endl;
    }
    return 0;
}