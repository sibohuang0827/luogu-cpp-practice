#include <iostream>
#include <algorithm>
using namespace std;

const int mashedArrNum=100005;
int shedArr[mashedArrNum];

bool check(int distance, int n, int m)
{
    int cnt=1;
    int last=shedArr[0];
    for(int i=1;i<n+1;i++)
    {
        if(shedArr[i]-last>=distance)
        {
            cnt++;
            last=shedArr[i];
            if (cnt>=m)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>shedArr[i];
    sort(shedArr, shedArr+n);
    int left=0,right=shedArr[n-1]-shedArr[0];
    while(left<right)
    {
        int mid=(left+right+1)/2;
        if(check(mid,n,m))
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