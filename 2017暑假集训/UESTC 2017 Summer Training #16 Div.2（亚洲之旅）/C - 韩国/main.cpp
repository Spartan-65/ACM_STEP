#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn];
bool vis[maxn];
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));

        int n;scanf("%d",&n);for(int i=0;i<=n;i++) a[i]=i;
        for(int i=1;i<=n;i++)
        {
            int t;scanf("%d",&t);
            a[i]=t;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                int t=a[i];
                while(i!=a[t])
                {
                    vis[t]=1;
                    t=a[t];
                }
                vis[i]=1;
                vis[t]=1;
                ans++;
                //cout<<i<<endl;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
