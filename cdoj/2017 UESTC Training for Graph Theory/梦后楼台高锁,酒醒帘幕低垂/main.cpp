#include <bits/stdc++.h>
using namespace std;
const int maxm=1005;
int n,m;
struct node{
    int u,v,w;
}e[maxm];
bool cmp(node a,node b)
{
    return a.w>b.w;
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
    }

    return 0;
}
