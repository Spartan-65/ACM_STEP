#include <bits/stdc++.h>
//#include <windows.h>
using namespace std;
const int maxm=1005;
const int maxn=208;
int Set[maxn];
int n,m;
struct node{
    int u,v,w;
}e[maxm];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int Find(int x)
{
    if(x==Set[x]) return x;
    return Set[x]=Find(Set[x]);
}
void init()
{
    for(int i=0;i<=n;i++)
        Set[i]=i;
}
void print()
{
    for(int i=1;i<=n;i++) cout<<i<<' '<<Set[i]<<endl;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        }
        sort(e,e+m,cmp);
        int ans=1e9;
        //for(int i=0;i<m;i++){cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;}
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<m;j++)
            {
                init();
                bool flag=false;int a=e[j].w;
                for(int k=j;k<m;k++)
                {
                    int fx=Find(e[k].u),fy=Find(e[k].v);
                    Set[fx]=fy;
                    if(Find(1)==Find(n)){flag=true;ans=min(ans,e[k].w-a); break;}
                }
                if(flag) break;
            }

        }
        printf("%d\n",ans);
    }

    return 0;
}
