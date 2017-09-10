#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
vector<pair<int ,int> > E[maxn];
int inq[maxn],d[maxn];
void init()
{
    for(int i = 0;i<maxn;i++) E[i].clear();
    for(int i = 0;i<maxn;i++) inq[i]=0;
    for(int i = 0;i<maxn;i++) d[i]=1e9;
}

int main()
{
    int n,m,s,t;
    while(~scanf("%d%d%d",&n,&m,&s))
    {
        init();
        for(int i = 0;i<m;i++)
        {
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            E[x].push_back(make_pair(y,z));
            //E[y].push_back(make_pair(x,z));
        }
        //scanf("%d%d",&s,&t);
        queue<int> q;
        q.push(s);d[s]=0;inq[s]=1;
        while(!q.empty())
        {
            int now=q.front();
            q.pop();inq[now]=0;
            for(int i = 0;i<E[now].size();i++)
            {
                int v=E[now][i].first;
                if(d[v]>d[now]+E[now][i].second)
                {
                    d[v]=d[now]+E[now][i].second;
                    if(inq[v]) continue;
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
        for(int i = 1;i<=n;i++)
            if(d[i]!=1e9)printf("%d ",d[i]);
            else printf("2147483647 ");
        printf("\n");
    }
    return 0;
}
