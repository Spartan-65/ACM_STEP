#include <bis/stdc++.h>
using namespace std;
const int maxn=2*1e6+5;
int dp[maxn];
int n;
int s[maxn],e[maxn];
int main()
{
	while(~scanf("%d",&n))
	{
		memset(dp,0,sizeof(dp));
		memset(e,0,sizeof(e));
		memset(s,0,sizeof(s));
		for(int i=0;i<n;i++)
		{
			int x;scanf("%d",&x);
			scanf("%d%d",s[x],e[x]);
		}
		
		for(int i=maxn-2;i>=0;i--)
		{
			dp[i]=dp[i+1];
			dp[i]=max(dp[i],dp[i+s[i]]+e[i]);
		}
		cout<<dp[0]<<endl;
	}
	return 0;
}