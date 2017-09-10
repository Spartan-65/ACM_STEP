/*
#include <bits/stdc++.h>
using namespace std;
const int maxn=21;
int n,m;
int dp[maxn][maxn];
bool mus[maxn];
double ans;
bool solo(int y)
{
    for(int j = 0;j<n;j++)
    {
        if(mus[j]==1)
        {
            if(y&(1<<j))continue;
            return false;
        }
    }
    return true;
}
void solve()
{
    for(int i = 0;i<(1<<n);i++)
    {
        if(!solo(i)) continue;
        double sum=0;
        int k=0;
        for(int j = 0;j<n;j++)
        {
            if(i&(1<<j))
            {
                k++;
                for(int p=1;p<=n;p++)
                {
                    if(i&(1<<(p-1)))
                        sum+=dp[j+1][p];
                }
            }
        }
        ans=max(ans,((sum*1.0)/(k*(2*n-k))));
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,0,sizeof(dp));
        memset(mus,0,sizeof(mus));
        int u,v,w;
        ans=0;
        for(int i = 0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            dp[u][v]=w;
        }
        for(int i =0;i<n;i++)
        {
            scanf("%d",&u);
            if(u)
            {
                mus[i]=1;
            }
        }
        solve();
        printf("%.4lf\n",ans);
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> p;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int mx=0,my=0;
        int mp=0;
        for(int i = 0;i<n;i++)
        {
            int x,y,xx,yy;
            scanf("%d%d%d%d",&x,&y,&xx,&yy);
            int tx=xx-x,ty=yy-y;
            if(!p.count(make_pair(tx,ty))) p[make_pair(tx,ty)]=0;
            p[make_pair(tx,ty)]++;
            if(p[make_pair(tx,ty)]>mp)
            {
                mp=p[make_pair(tx,ty)];
                mx=tx;
                my=ty;
            }
        }
        printf("%d %d\n",mx,my);
    }
    return 0;
}




















