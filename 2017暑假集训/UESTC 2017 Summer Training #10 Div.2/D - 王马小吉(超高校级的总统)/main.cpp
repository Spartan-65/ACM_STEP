#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int Min=100000;
        for(int i=1;i<=n;i++)
        {
            int t=n;
            int ans=ceil(log2(i));
            if(ans!=log2(i)) t-=(pow(2,ans)-i);
            ans+= ceil(t*1.0/i);
            Min=min(Min,ans);
            //cout<<i<<' '<<t<<' '<<ans<<endl;
        }
        cout<<Min<<endl;
    }

    return 0;
}
