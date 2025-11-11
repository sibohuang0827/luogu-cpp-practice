#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int action;
    cin>>action;
    queue<int>q;
    for(int i=0;i<action;i++)
    {
        char t;
        cin>>t;
        if(t=='1')
        {
            int x;
            cin>>x;
            q.push(x);
        }
        else if(t=='2')
        {
            if(q.empty())cout<<"ERR_CANNOT_POP"<<endl;
            else q.pop();
        }
        else if(t=='3')
        {
            if(q.empty())
            cout<<"ERR_CANNOT_QUERY"<<endl;
            else cout<<q.front()<<endl;
        }
        else 
        {
            cout<<q.size()<<endl;
        }
    }
    return 0;
}