#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll a,b;
ll work(int a,int b,int l)
{
    ll ans=0;
    for(int i=0;i<l;i++)
    {
        if(i%(a+b)<a) ans=(ans<<1)|1;
        else ans<<=1;
    }
    return ans;
}
void init()
{
    ll num=1;
    v.push_back(1);
    for(int i=1;i<63;i++)
    {
        num=(num<<1)|1;
        v.push_back(num);
    }
    for(int i=1;i<=63;i++)
    {
        for(int j=1;j<=63;j++)
        {
            for(int k=i+j;k<=63;k++)
            {
                if(k%(i+j)==0||k%(i+j)==i)
                v.push_back(work(i,j,k));
            }
        }
    }
    sort(v.begin(),v.end());
}

int main()
{
    init();
    while(~scanf("%lld%lld",&a,&b))
    {
        int t1=lower_bound(v.begin(),v.end(),a)-v.begin();
        int t2=upper_bound(v.begin(),v.end(),b)-v.begin();
        printf("%d\n",t2-t1);
    }
    return 0;
}
