#include <iostream>
using namespace std;

const int maxn=1000005;
int nextlist[maxn];

int main()
{
    int q;
    cin >> q;
    nextlist[1] = 0;
    while(q--) 
    {
        int op;
        cin >> op;

        if(op == 1)
        {
            int x, y;
            cin >> x >> y;
            nextlist[y] = nextlist[x];
            nextlist[x] = y;
        }
        else if(op == 2)
        {
            int x;
            cin >> x;
            cout << nextlist[x] << endl;
        }
        else if(op == 3)
        {
            int x;
            cin >> x;
            nextlist[x] = nextlist[nextlist[x]];
        }
    }
}