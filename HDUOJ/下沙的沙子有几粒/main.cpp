#include <bits/stdc++.h>
using namespace std;
const int maxn=30;
long long  dp[maxn][maxn];
void init()
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<maxn;i++) dp[i][0]=1;
    for(int i=1;i<maxn;i++)
        for(int j=i;j<maxn;j++)
            dp[j][i]=dp[j-1][i]+dp[j][i-1];
}
int main()
{
    init();
    int n,m;
    while(~scanf("%d%d",&m,&n))
        printf("%lld\n",dp[m][n]);
    init();
}
