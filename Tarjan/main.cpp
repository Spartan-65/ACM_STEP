#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+8;
int id=0,id_c=0;
stack<int> st;
int dfn[maxn],low[maxn],color[maxn];
vector<int> e[maxn];
bool vis[maxn];
void Tarjan(int x)
{
    dfn[x]=++id;
    low[x]=id;
    st.push(x);
    vis[x]=1;
    for(int i=0;i<e[x].size();i++)
    {
        int temp=e[x][i];
        if(temp==2) print();
        if(!dfn[temp])
        {
            Tarjan(temp);
            low[x]=min(low[x],low[temp]);
        }
        else if(vis[temp]) low[x]=min(low[x],dfn[temp]);
    }
    if(dfn[x]==low[x])
    {
        color[x]=++id_c;
        int t;
        do
        {
            t=st.top();
            color[t]=id_c;
            vis[t]=0;
            st.pop();
        }while(t!=x);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        e[u].push_back(v);
    }
    Tarjan(1);
    for(int i=0;i<n;i++)
    {
        cout<<i<<' '<<color[i]<<endl;
    }
    return 0;
}
