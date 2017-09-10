#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
long long num[maxn],ans[maxn];
int Set[maxn],q[maxn];
bool vis[maxn];
long long Max;
int Find(int x)
{
    if(x==Set[x]) return x;
    return Set[x]=Find(Set[x]);
}
void join(int x,int y)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy)
    {
        Set[fy]=fx;
        num[fx]+=num[fy];
    }
}
void Work(int x)
{
    vis[x]=1;
    Max=max(Max,num[x]);
    if(vis[x+1])
    {
        join(x,x+1);
        Max=max(Max,num[Find(x)]);
    }
    if(vis[x-1])
    {
        join(x,x-1);
        Max=max(Max,num[Find(x)]);

    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        Max=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&num[i]);
            Set[i]=i;
        }
        for(int i=n;i>0;i--)
        {
            scanf("%d",&q[i]);
        }
        for(int i=1;i<=n;i++)
        {
            Work(q[i]);
            ans[i]=Max;
        }
        for(int i=n-1;i>=0;i--)
            cout<<ans[i]<<endl;
    }
    return 0;
}
