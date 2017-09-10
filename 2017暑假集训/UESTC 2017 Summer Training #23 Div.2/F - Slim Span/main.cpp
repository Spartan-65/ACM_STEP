#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
struct line
{
    int x,y,w;
}a[10000];
int Set[maxn];
int n,m;
bool cmp(line a,line b){return a.w<b.w;}
int Find(int x)
{
    if(x==Set[x]) return x;
    return Set[x]=Find(Set[x]);
}
int main()
{
    freopen("F.in","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) return 0;
        for(int i=0;i<m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
        sort(a,a+m,cmp);
        int ans=1e9;
        for(int i=0;i<m;i++)
        {
            int Max=0,Min=1e9,Count=0;
            for(int i=1;i<maxn;i++) Set[i]=i;
            for(int j=i;j<m;j++)
            {
                int x=Find(a[j].x),y=Find(a[j].y);
                if(x!=y)
                {
                    Max=max(Max,a[j].w);
                    Min=min(Min,a[j].w);
                    Set[x]=y;
                    if(++Count==n-1)
                        break;
                }
            }
            if(Count==n-1)
                ans=min(ans,Max-Min);
        }
        if(ans==1e9) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
