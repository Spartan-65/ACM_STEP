#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,a[maxn],dp[maxn],ans[maxn];
int main()
{
    int t;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d",&n);
            for(int i = 0;i<n;i++) ans[i]=1e9;
            ans[0]=-1e9;
            for(int i=1;i<=n;i++)dp[i]=1;

            for(int i=1;i<=n;i++)
                scanf("%d",&a[i]);
            int len=0;
            for(int i=n;i>=1;i--)
            {
                for(int j=n;j>i;j--)
                {
                    if(a[j]>a[i]) dp[i]=max(dp[i],dp[j]+1),len=max(dp[i],len);
                }
                //for(int k=1;k<=n;k++) printf("%d ",dp[k]);
                //printf("\n");
            }
            int p=0;
            for(int i=1;i<=len;i++)
            {
                for(int j=p+1;j<=n;j++)
                {
                    if(dp[j]==len-i+1&&ans[i]>a[j]&&ans[i-1]<a[j])
                        {
                            ans[i]=a[j];
                            p=j;
                        }
                }
                //for(int k=1;k<=i;k++)
                    //printf("%d ",ans[k]);
                //printf("\n");
            }
            cout<<len<<' ';
            for(int i = 1;i<=len;i++)
                printf("%d ",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
