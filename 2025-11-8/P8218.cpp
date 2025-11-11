#include <iostream>
using namespace std;

const int max_num=100005;
int a[max_num],pre[max_num];

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<endl;
    }
    return 0;
}
