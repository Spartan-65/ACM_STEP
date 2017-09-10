#include <bits/stdc++.h>
using namespace std;

long long C(int k,int n)
{
    if(k==0) return 1;
    if(n==k) return 1;
    if(k>(n-k)) k=n-k;
    long long ans=1;

    for(int i=0;i<k;i++)
    {
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}

int main()
{
    int n,p;
    while(~scanf("%d%d",&n,&p))
    {
        long long ans=0;
        int ji=0,ou=0;
        for(int i=0;i<n;i++)
        {
            int t;scanf("%d",&t);
            if(t&1) ji++;
            else ou++;
        }
        if(p)
        {
            for(int i=0;i<=ou;i++)
            {
                for(int j=1;j<=ji;j+=2)
                {
                    ans+=(C(i,ou)*C(j,ji));
                }
            }
        }
        else
        {
            for(int i=0;i<=ou;i++)
            {
                for(int j=0;j<=ji;j+=2)
                    ans+=(C(i,ou)*C(j,ji));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
