#include <bits/stdc++.h>
using namespace std;
const int maxn=1008;
char str[maxn][300];
int n,ru[30];
vector<int> e[30];
int len[maxn];
priority_queue<int, vector<int>,greater<int> > q;
int main()
{
    scanf("%d",&n);
    memset(ru,0,sizeof(ru));
    for(int i=0;i<n;i++) {scanf("%s",str[i]);len[i]=strlen(str[i]); }
    for(int i=0;i<n-1;i++)
    {
        int j=0;
        for(;j<len[i]&&j<len[i+1];j++)
        {
            if(str[i][j]!=str[i+1][j])
            {
                e[str[i][j]-'a'].push_back(str[i+1][j]-'a');
                ++ru[str[i+1][j]-'a'];
                break;
            }

        }
        if(len[i+1]==j&&j<len[i])
        {
            printf("-1\n");
            return 0;
        }
    }
    for(int i=0;i<26;i++)
        if(ru[i]==0) q.push(i);
    string ans="";
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        ans+=u+'a';
        for(int i=0;i<e[u].size();i++)
        {
            int v=e[u][i];
            if(--ru[v]==0)
                q.push(v);
        }
    }
    if(ans.size()!=26) printf("-1\n");
    else cout<<ans<<endl;
    return 0;
}
