#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ji=n/2,ou=n/2;
        if(n&1)ji++;
        long long ans= (long long)ji*(ji-1)/2*ou;
        if(ou>=3) ans+=(long long)ou*(ou-1)/2*(ou-2)/3;
        printf("%lld\n",ans);
    }
    return 0;
}
