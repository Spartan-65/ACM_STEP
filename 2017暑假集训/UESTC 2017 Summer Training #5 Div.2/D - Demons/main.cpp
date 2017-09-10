#include <bits/stdc++.h>
using namespace std;
struct node{
    int next,d,c;
};
const int maxn=10005;
int n,m;
int d[maxn],c[maxn];
bool vis[maxn];
void init()
{
    for(int i=0;i<maxn;i++)
        d[i]=c[i]=1e9,vis[i]=0;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) return 0;
        init();vector<node> v[maxn];
        for(int i=0;i<m;i++)
        {
            int x,y,d,c;
            scanf("%d%d%d%d",&x,&y,&d,&c);
            v[x].push_back(node{y,d,c});
            v[y].push_back(node{x,d,c});
        }
        queue<int> q;
        q.push(1);
        d[1]=c[1]=0;vis[1]=1;
        while(!q.empty())
        {
            int u=q.front();q.pop();vis[u]=0;
            for(int i=0;i<v[u].size();i++)
            {
                int nx=v[u][i].next;
                if(d[nx]==d[u]+v[u][i].d&&c[nx]>v[u][i].c){
                        c[nx]=v[u][i].c;
                }
                if(d[nx]>d[u]+v[u][i].d)
                {
                    d[nx]=d[u]+v[u][i].d;
                    c[nx]=v[u][i].c;
                    if(vis[nx]) continue;
                    vis[nx]=1;
                    q.push(nx);
                }
            }
        }
        int ans=0;
        for(int i=2;i<=n;i++) ans+=c[i];
        cout<<ans<<endl;
    }
    return 0;
}
