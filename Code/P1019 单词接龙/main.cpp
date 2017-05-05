#include <bits/stdc++.h>
using namespace std;
string str,s[20];
int n,maxn,used[20]={0};

void dfs(string last)
{
    int len=0;
    int m;
    bool flag=false;
    for(int i = 0;i<n;i++)
    {
        flag=false;m=0;
        if(used[i]<2)
        {

            for(int j=last.size()-1;j>=0;j--)
            {
                if(last[j]==s[i][0])
                {
                    m = 1;
                    while(last[j+m]==s[i][m]) m++;
                    if(j+m==last.size()) flag=true;
                }
                if(flag) break;
            }
            if(flag)
            {
                //cout<<last<<'+'<<s[i]<<endl;
                //cout<<m<<endl;
                int t=str.size();
                str+=s[i].substr(m,s[i].size()-m);
                //cout<<str<<endl;
                //cout<<endl;
                len=str.size();
                used[i]++;
                dfs(s[i]);
                used[i]--;
                str.erase(t,s[i].size()-m);
            }
        }
    }
    maxn=maxn>len?maxn:len;
    //if(maxn==str.size()) cout<<str<<endl;
    return ;
}

int main()
{
    while(cin>>n)
    {
        maxn=0;
        memset(used,0,sizeof(used));
        for(int i = 0;i<n;i++) cin>>s[i];
        cin>>str;
        dfs(str);
        cout<<maxn<<endl;
    }
    return 0;
}
