#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int n;
        cin>>n;
        vector<int>psh;
        vector<int>pp;
        stack<int>stk;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            psh.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            pp.push_back(temp);
        }
        /*
        We have 
        psh = 1 2 3 4
        pp = 2 4 1 3
        stk = empty
        */
        int ppi=0,pshi=0;
        while(true)
        {
            if(!stk.empty()&&stk.top()==pp[ppi])
            {
                stk.pop();
                ppi++;
            }
            else if(pshi<psh.size())
            {
                stk.push(psh[pshi]);
                pshi++;
            }
            else 
            {
                break;
            }
        }
        if(ppi==pp.size()){
            cout<<"Yes"<<endl;
        } 
        else 
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}