#include <bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+5;
vector<int> e[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    queue<int> q;
    int a[maxn],b[maxn];
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    q.push(1);a[1]=0;b[n]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<e[u].size();i++)
        {
            int v=e[u][i];
            if(a[v]==-1)
            {
                a[v]=a[u]+1;
                q.push(v);
            }
        }
    }
    q.push(n);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<e[u].size();i++)
        {
            int v=e[u][i];
            if(b[v]==-1)
            {
                b[v]=b[u]+1;
                q.push(v);
            }
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=b[i]) ans1++;
        else ans2++;
        //cout<<i<<' '<<a[i]<<' '<<b[i]<<endl;
    }
    //cout<<ans1<<' '<<ans2<<endl;
    if(ans1>ans2)cout<<"Fennec"<<endl;
    else cout<<"Snuke"<<endl;
    return 0;
}
