#include <bits/stdc++.h>
using namespace std;
#define ll long long
int len;
int calc(long long n)
{
    int C=0;
    while(n)
    {
        C++;
        n>>=1;
    }
    return C;
}
int main()
{
    long long l,r;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&l,&r);
        long long ans=0;
        len=calc(r);
        long long temp=0;
        for(int i=0;i<len;i++)
        {
            if(r&((ll)1<<i)) ans|=(ll)1<<i,temp|=(ll)1<<i;
            else
            {
                if((r-temp)>l) ans|=(ll)1<<i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
