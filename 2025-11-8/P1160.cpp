#include <iostream>
using namespace std;
const int maxn=100005;
struct node
{
    int L,R;
    bool inq;
};
node a[maxn];
int head;

void InsertLeft(int i,int K)
{
    int LK=a[K].L;
    a[i].R=K,a[i].L=LK;
    a[K].L=i;
    if(LK)
    {
        a[LK].R=i;
    }
    else 
    {
        head=i;
    }
    a[i].inq=true;
}

void InsertRight(int i,int K)
{
    int RK=a[K].R;
    a[i].R=RK,a[i].L=K;
    a[K].R=i;
    if(RK)
    {
        a[RK].L=i;
    }
    a[i].inq=true;
}

void Remove(int K)
{
    if(!a[K].inq) return;
    int LK=a[K].L,RK=a[K].R;
    if(LK) a[LK].R=RK;
    else head=RK;
    if(RK) a[RK].L=LK;
    a[K].L=0,a[K].R=0;
    a[K].inq=false;
}

int main()
{
    int N;
    cin>>N;
    head=1;
    a[1].inq=true;
    for(int i=2;i<=N;i++)
    {
        int K,P;
        cin>>K>>P;
        if(P==0)
        {
            InsertLeft(i,K);
        }
        if(P==1)
        {
            InsertLeft(i,K);    
        }
    }
    int M;
    cin>>M;
    for(int i=1;i<=M;i++)
    {
        int K;
        cin>>K;
        Remove(K);
    }
    for(int i=head;i!=0;i=a[i].R)
    {
        cout<<i<<" ";
    }
    return 0;
}