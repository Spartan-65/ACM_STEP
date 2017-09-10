#include <bits/stdc++.h>

using namespace std;
const int maxn=10000+10;
vector<int>grap[maxn];
stack<int> S;

int low[maxn];
int num[maxn];
bool vis[maxn];
bool instack[maxn];
int Index;
int cnt_scc;
int belong[maxn];


void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        grap[i].clear();
    }
    while(!S.empty())
    {
        S.pop();
    }
    memset(instack,0,sizeof(instack));
    memset(vis,0,sizeof(vis));
    memset(low,-1,sizeof(low));
    memset(num,-1,sizeof(num));
    memset(belong,-1,sizeof(belong));
    Index = 0;
    cnt_scc = 0;
}

void tarjan(int v)
{
    low[v] = num[v] = ++Index;
    S.push(v);
    instack[v] = 1;
    vis[v] = 1;

    for(int i=0; i<grap[v].size(); i++)
    {
        int w = grap[v][i];
        if(!vis[w])
        {
            tarjan(w);
            low[v] = min(low[v],low[w]);
        }
        else if(instack[w])
        {
            low[v] = min(low[v],num[w]);
        }
    }
    int u;
    if(low[v] == num[v])
    {
        ++cnt_scc;
        do
        {
            u = S.top();
            belong[u] = cnt_scc;
            S.pop();
            instack[u] = 0;
        }while(u != v);
    }
}
int main()
{
    int T;scanf("%d",&T);
    int ind[maxn];
    int outd[maxn];
    while(T--)
    {
        int n,m;scanf("%d%d",&n,&m);
        init(n);
        memset(ind,0,sizeof(ind));
        memset(outd,0,sizeof(outd));
        for(int i=0;i<m;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            grap[a].push_back(b);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                tarjan(i);
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<grap[i].size(); j++)
            {
                int k = grap[i][j];
                if(belong[i] != belong[k])
                {
                    ind[belong[k]]++;
                    outd[belong[i]]++;
                }
            }
        }

        int a=0,b=0;
        for(int i=1; i<=cnt_scc; i++)
        {
            if(!ind[i])
            {
                a++;
            }
            if(!outd[i])
            {
                b++;
            }
        }
        if(cnt_scc == 1)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",max(a,b));
        }
    }
    return 0;
}
