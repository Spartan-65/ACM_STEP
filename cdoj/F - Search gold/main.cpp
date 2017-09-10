#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int mp[maxn][maxn],dp[maxn][maxn];
int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dp[i][j]=-1e9;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&mp[i][j]);
        dp[0][0]=mp[0][0];
        int M=0;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
            {
                if(i>0) dp[i][j]=max(dp[i][j],dp[i-1][j]+mp[i][j]);
                if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]+mp[i][j]);
                if(i>1&&j>0) dp[i][j]=max(dp[i][j],dp[i-2][j-1]+mp[i][j]);
                if(i>0&&j>1) dp[i][j]=max(dp[i][j],dp[i-1][j-2]+mp[i][j]);
                if(dp[i][j]<=0) dp[i][j]=-1e9;
                M=max(M,dp[i][j]);
            }
            cout<<M<<endl;
    }
    return 0;
}
