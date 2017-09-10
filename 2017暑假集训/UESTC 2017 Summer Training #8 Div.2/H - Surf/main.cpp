#include <bits/stdc++.h>
using namespace std;
const int maxn=2*1e6+5;
int dp[maxn],a[maxn],b[maxn];
int main()
{
    int n;
    memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        scanf("%d",&x);
        scanf("%d%d",&a[x],&b[x]);
		
    }
    for(int i=maxn-1;i>=0;i--)
    {
        dp[i]=dp[i+1];
        dp[i]=max(dp[i],dp[i+b[i]]+a[i]);
    }
    cout<<dp[0]<<endl;
    return 0;
}
