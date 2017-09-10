#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int x[maxn],y[maxn],r[maxn];
int n,d[maxn];
int gcd(int n,int m)
{
    return n%m?gcd(m,n%m):m;
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&r[i]);
        }
        d[0]=1;
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])==(r[i]+r[j])*(r[i]+r[j]))
                {
                    if(d[j]==0)
                    {
                        d[j]=-d[i];
                    }
                    else if(d[j]==d[i])
                    {
                        flag=1;
                        break;
                    }
                    else{}
                }
            }
            if(flag) break;
        }
        if(flag) cout<<"The input gear cannot move."<<endl;
        else if(d[n-1])
        {
            printf("%d:%d\n",r[0]*d[n-1]/gcd(r[0],r[n-1]),r[n-1]/gcd(r[0],r[n-1]));
        }
        else cout<<"The input gear is not connected to the output gear."<<endl;
    }

    return 0;
}
