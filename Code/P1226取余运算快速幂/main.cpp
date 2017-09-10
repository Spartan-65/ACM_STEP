#include <bits/stdc++.h>

using namespace std;
long long b,p,k;
long long pow2()
{
    long long r=1,base=b;
    while(p)
    {
        if(p&1) r=r*base%k;
        base=base*base%k;
        p>>=1;
    }
    return r;
}
int main()
{
    scanf("%lld%lld%lld",&b,&p,&k);
    printf("%lld^%lld mod %lld=",b,p,k);
    printf("%lld\n",pow2());
    return 0;
}
