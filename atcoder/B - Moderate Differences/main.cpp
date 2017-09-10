#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,b,c,d;
    while(~scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d))
    {
        int t=b-a;
        bool flag=false;
        for(int i=0;i<n;i++)
        if(t>=i*c-(n-1-i)*d&&t<=i*d-(n-1-i)*c) {flag=true; break;}
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
