#include <bits/stdc++.h>
using namespace std;
double x[20],y[20];
int n;
double dis[20][20];
double ans=99999999;
bool vis[15];
void dfs(int d,double sum,int last)
{
    if(sum>ans) return;
    if(d==n)
    {
        if(ans>sum) ans=sum;
        return;
    }
    for(int i=1;i<=n;i++)
    if(!vis[i])
    {
        vis[i]=1;
        dfs(d+1,sum+dis[last][i],i);
        vis[i]=0;
    }
}
int main()
{

    scanf("%d",&n);
    memset(dis,0,sizeof(dis));
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(vis,0,sizeof(vis));
    for(int i = 1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(int i = 0;i<=n;i++)
    for(int j = 0;j<=n;j++)
    if(i==j)continue;
    else dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    dfs(0,0,0);
    printf("%.2lf\n",ans);
    return 0;
}
