#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int c[maxn];
int topo[maxn], t;
int G[maxn][maxn];
int n, m;

void dfs(int u)
{
    c[u]=-1;
    for(int v= 1;v<=n;v++){
        if(G[u][v]){
            if(!c[v]) dfs(v);
        }
    }
    c[u]=1; topo[--t]=u;
}
void toposort()
{
    t=n;
    memset(c, 0, sizeof(c));
    for(int u = 1;u<=n;u++)
        if(!c[u]) dfs(u);
}



int main()
{

    while(~scanf("%d%d",&n,&m))
    {
        if(!(n||m)) break;
        memset(G,0,sizeof(G));
        for(int i = 0;i<m;i++)
        {
            int u, v;scanf("%d%d",&u, &v);
            G[u][v]=1;
        }
        toposort();

        for(int i = 0 ;i<n-1;i++)
            printf("%d ",topo[i]);
        printf("%d\n",topo[n-1]);
    }

    return 0;

}
