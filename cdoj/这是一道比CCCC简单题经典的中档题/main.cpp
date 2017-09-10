#include <bits/stdc++.h>
using namespace std;
const int maxn=50005;
int n,w;
int dp[maxn];
int main()
{
    while(~scanf("%d%d",&n,&w))
    {
        for(int i = 0;i<n;i++)
        {
            int c,p,x;
            scanf("%d%d%d",&c,&p,&x);
            if(c*x>=w)
            {
                for(int j = c;j<=w;j++)
                    dp[j]=max(dp[j],dp[j-c]+p);
            }
            else
            {
                int t=1;
                while(t<=x)
                {

                    for(int j = w;j>=t*c;j--)
                    {
                        dp[j]=max(dp[j],dp[j-t*c]+t*p);
                    }
                    x-=t;
                    t*=2;
                }
                for(int j = w;j>=c*x;j--) dp[j]=max(dp[j],dp[j-c*x]+x*p);
            }
        }
        printf("%d\n",dp[w]);
    }

    return 0;
}
