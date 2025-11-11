#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int n,k;
int L[maxn];

bool check(int l)
{
    long long cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+=L[i]/l;
        if(cnt>=k)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    // input
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>L[i];
    }

    //algorithm
    int left=1,right=0;
    for(int i=0;i<n;i++)
    {
        right=max(right,L[i]);
    }
    if(!check(1)){
        cout<<0<<endl;
    }
    else
    {
        while(left<right)
        {
            int mid=(left+right+1)/2;
            if(check(mid))
            {
                left=mid;
            }
            else
            {
                right=mid-1;
            }
        }
        cout<<left<<endl;
    }
}