#include <bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int maxn=2005;
long long dp[maxn][maxn];
void init()
{
    memset(dp,0,sizeof(dp));
    dp[1][1]=26;
    for(int i=2;i<maxn;i++)
    {
        dp[i][1]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][3])*25%M;
        dp[i][2]=dp[i-1][1];dp[i][3]=dp[i-1][2];
    }
}
int main()
{
    init();
    long long n;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        printf("%lld\n",(dp[n][1]+dp[n][2]+dp[n][3])%M);
    }
    return 0;
}
