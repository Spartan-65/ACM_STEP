#include <bits/stdc++.h>
using namespace std;
const int maxn=600005;
int n,k;
int a[maxn];
int flag[maxn];
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        memset(flag,0,sizeof(flag));
        for(int i=1;i<=k;i++)
        {
            int t;scanf("%d",&a[i]);
            if(a[i]<=n/2)
                for(int j=2*a[i];j<=n;j+=a[i])
                {
                    flag[j]=i;
                }
        }
        bool ans=1;
        for(int i=1;i<=k;i++)
        {
            if(flag[a[i]])
            {
                printf("%d %d\n",i,flag[a[i]]);
                ans=0;
                break;
            }
        }
        if(ans) printf("0 0\n");
    }
    return 0;
}
