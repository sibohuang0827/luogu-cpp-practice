#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN=100005;
struct ship
{
    int t; //arrival time
    vector<int>nations;//船上的人的国家
};
int cnt[MAXN];
int ans=0;
queue<ship>q;

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int t,k;
        cin>>t>>k;
        ship s;
        s.t=t;
        for(int j=0;j<k;j++)
        {
            int tmp;
            cin>>tmp;
            s.nations.push_back(tmp);
        }
        for(int x:s.nations)
        {
            if(cnt[x]==0)
            {
                ans++;
            }
            cnt[x]++;
        }
        q.push(s);
        while(!q.empty()&&q.front().t<=s.t-86400)
        {
            for(int x:q.front().nations)
            {
                --cnt[x];
                if(cnt[x]==0)
                {
                    ans--;
                }
            }
            q.pop();    
        }
        cout<<ans<<endl;
    }
    return 0;
}