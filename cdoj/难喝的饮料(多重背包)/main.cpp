#include <bits/stdc++.h>
using namespace std;
const int maxn=20005;
int dp[maxn];



int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 0;i<n;i++)
        {
            int t,v,w;
            scanf("%d%d%d",&t,&v,&w);
            if(t==1)
            {
                for(int j=w;j<=m;j++)
                    dp[j]=max(dp[j],dp[j-w]+v);
            }
            else
            {
                for(int j = m;j>=w;j--)
                    dp[j]=max(dp[j],dp[j-w]+v);
            }
        }
        printf("%d\n",dp[m]);
    }

    return 0;
}
