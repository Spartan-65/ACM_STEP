#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n,m;
    freopen("kids.in","r",stdin);
    freopen("kids.out","w",stdout);
    while(~scanf("%lf%lf",&n,&m))
    {
        double t=(n-1)/n,ans=1;
        for(int i=0;i<m;i++)
        {
            ans*=t;
        }
        ans=1-ans;
        ans=n*ans;
        printf("%.10lf\n",ans);
    }

    return 0;
}
