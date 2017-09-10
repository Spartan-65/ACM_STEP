#include <bits/stdc++.h>
using namespace std;
const int maxn=60005;
long long d[maxn];
int n,m;
bool inv[maxn];
vector<pair<int,int> > E[maxn];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=m;i++)
        {
            int k;
            scanf("%d",&k);
            while(k--)
            {
                int x;
                scanf("%d",&x);
                E[x].push_back(make_pair(n+i,0));
                E[n+m+i].push_back(make_pair(x,0));
                //cout<<x<<"->"<<n+i<<' '<<n+m+i<<"->"<<x<<endl;
            }
        }
        int temp;
        scanf("%d",&temp);
        for(int i=0;i<temp;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            E[x].push_back(make_pair(y,z));
            E[y].push_back(make_pair(x,z));
        }
        scanf("%d",&temp);
        for(int i=0;i<temp;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            E[n+x].push_back(make_pair(n+m+y,z));
            E[n+y].push_back(make_pair(n+m+x,z));
        }
        for(int i=0;i<maxn;i++) d[i]=1e12;
        memset(inv,0,sizeof(inv));
        int s,t;
        scanf("%d%d",&s,&t);
        queue<int> q;
        q.push(s),d[s]=0;inv[s]=1;
        while(!q.empty())
        {
            int now=q.front();q.pop();inv[now]=0;
            for(int i=0;i<E[now].size();i++)
            {
                int v=E[now][i].first;
                if(d[v]>E[now][i].second+d[now])
                {
                    d[v]=E[now][i].second+d[now];
                    if(inv[v]) continue;
                    inv[v]=1;
                    q.push(v);
                }
            }
        }
        if(d[t]==1e12) printf("-1\n");
        else printf("%lld\n",d[t]);
    }
}
