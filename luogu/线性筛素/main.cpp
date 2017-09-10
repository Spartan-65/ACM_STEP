#include <bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
bool q[maxn]={0};

void init(int n)
{
    q[0]=q[1]=1;
    for(int i = 2;i<=n;i++)
        if(!q[i])
            for(int j = i<<1;j<=n;j+=i)
                q[j]=1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i = 0;i<m;i++)
    {
        int t;
        scanf("%d",&t);
        if(!q[t]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
