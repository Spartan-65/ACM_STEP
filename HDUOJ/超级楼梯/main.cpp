#include <bits/stdc++.h>
using namespace std;
const int maxn=50;
long long dp[maxn];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[1]=dp[2]=1;
    for(int i=3;i<maxn;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    int t,n;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}
