/*kruskalËã·¨ÊµÏÖ*/
/*
#include <bits/stdc++.h>
using namespace std;
int Set[5005];
int n,m;
struct node
{

    int u,v,w;
}a[200000];
bool cmp(node a, node b)
{
    return a.w<b.w;
}

int findset(int x)
{
    if(x==Set[x]) return x;
    return Set[x]=findset(Set[x]);
}

void init(int n)
{
    for(int i = 0;i<=n;i++) Set[i]=i;
}

int kruskal()
{
    int ans=0,Count=0;
    sort(a,a+m,cmp);
    for(int i = 0;i<m;i++)
    {
        int x=findset(a[i].u);
        int y=findset(a[i].v);
        if(x!=y)
        {
            ans+=a[i].w;
            Set[x]=y;
            Count++;
        }
    }
    if(Count<((n+1)/2)) return 0;
    else return ans;
}
int main()
{

    while(~scanf("%d%d",&n,&m))
    {
        init(n);
        for(int i = 0;i<m;i++)
            scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
        int ans=kruskal();
        if(ans) printf("%d\n",ans);
        else printf("orz\n");
    }
    return 0;
}
*/
/**/
