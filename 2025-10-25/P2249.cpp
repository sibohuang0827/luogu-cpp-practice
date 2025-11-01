#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>nArr(n);
    for(int i=0;i<n;i++)cin>>nArr[i];
    vector<int>mArr(m);
    for(int i=0;i<m;i++)cin>>mArr[i];
    for(int i=0;i<m;i++)
    {
        int targetValue=mArr[i],leftIndex=0,rightIndex=n-1,ans=-1;
        while(leftIndex<=rightIndex)
        {
            int midIndex=(leftIndex+rightIndex)/2;
            if(nArr[midIndex]>=targetValue)
            {
                if(nArr[midIndex]==targetValue)
                {
                    ans=midIndex+1;
                }
                rightIndex=midIndex-1;

            }
            else 
            {
                leftIndex=midIndex+1;
            }
        }
        cout<<ans<<" ";
    }
}