#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int main()
{
    freopen("dales.in","r",stdin);
    freopen("dales.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;

        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int ans1=0,ans2=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]<a[i+1])
            {
                int j=i;
                for(j=i;j<n-1;j++)
                    if(a[j]>=a[j+1]) break;
                int k=j;
                for(;k<n-1;k++)
                    if(a[k]<=a[k+1]) break;
                ans1=max(ans1,min(j-i,k-j));
                i=k-1;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                int j=i;
                for(;j<n-1;j++)
                    if(a[j]<=a[j+1]) break;
                int k=j;
                for(;k<n-1;k++)
                    if(a[k]>=a[k+1]) break;
                ans2=max(ans2,min(j-i,k-j));
                i=k-1;
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
