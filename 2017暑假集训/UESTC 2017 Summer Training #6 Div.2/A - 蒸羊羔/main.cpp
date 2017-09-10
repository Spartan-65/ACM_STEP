#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int Count=0;
        int len=s.length();
        for(int i=0;i<s.length();i++)
            if(s[i]=='0') Count++;
        len=min(Count,len-Count);
        cout<<len<<endl;
    }
    return 0;
}
