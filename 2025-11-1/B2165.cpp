#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

char s[1000005];

bool match(char openCh, char closeCh)
{
    return(openCh=='('&&closeCh==')')||(openCh=='['&&closeCh==']')||(openCh=='{'&&closeCh=='}');
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>s;
        int len=strlen(s);
        stack<char>st;
        bool OK=true;
        for(int i=0;i<len;i++)
        {
            char now=s[i];
            if(now=='('||now=='['||now=='{')
            {
                st.push(now);
            }
            else
            {
                if(st.empty()||!match(st.top(),now))
                {
                    OK=false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if(!st.empty())OK=false;
        if(OK)
        {
            cout<<"YES"<<endl;
        } 
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}