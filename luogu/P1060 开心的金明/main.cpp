#include <bits/stdc++.h>
using namespace std;
int dp[30001];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<m;i++)
        {
            int v,w;
            scanf("%d%d",&v,&w);
            for(int j = n;j>=v;j--)
                dp[j]=max(dp[j],dp[j-v]+v*w);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
