#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        stack<unsigned long long>stk;
        for(int i=0;i<n;i++)
        {
            string action;
            cin>>action;
            if(action=="push")
            {
                unsigned long long x;
                cin>>x;
                stk.push(x);
            }
            else if(action=="pop")
            {
                if(stk.empty())
                {
                    cout<<"Empty"<<endl;
                }
                else
                {
                    stk.pop();
                }
            }
            else if(action=="query")
            {
                if(stk.empty())
                {
                    cout<<"Anguei!"<<endl;
                }
                else
                {
                    cout<<stk.top()<<endl;
                }
            }
            else
            {
                cout<<stk.size()<<endl;
            }
        }
    }
}