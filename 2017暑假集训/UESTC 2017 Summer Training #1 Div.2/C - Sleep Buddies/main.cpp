#include <bits/stdc++.h>
using namespace std;
long long C[1025];
int calc(int x)
{
    int Count=0;
    while(x)
    {
        if(x&1) Count++;
        x>>=1;
    }
    return Count;
}
int main()
{
    int n,m;
    double k;
    while(~scanf("%d%d",&n,&m))
    {
        memset(C,0,sizeof(C));
        for(int i=0;i<n;i++)
        {
            int t,temp=0,q;
            scanf("%d",&t);
            for(int j=0;j<t;j++) {scanf("%d",&q);temp|=(1<<(q-1));}
            C[temp]++;
        }
        scanf("%lf",&k);
        long long ans=0;
        for(int i=1;i<1025;i++)
        {
            if(!C[i])continue;
            if(C[i]>1) ans+=((C[i]*(C[i]-1))>>1);

            for(int j=i+1;j<1025;j++)
            {
                int u=calc(i|j),v=calc(i&j);
                if(u*k>v) continue;
                ans+=(C[i]*C[j]);
            }

        }
        printf("%lld\n",ans);
    }
    return 0;
}
