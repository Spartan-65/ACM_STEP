#include<bits/stdc++.h>
using namespace std;
int a[105];
int ans[50005];
int b[105];
long long int pow(int x)
{
    long long int ss=1;
    for(int i=0;i<x;i++)
    {
        ss=ss*2;
    }
    return ss;
}
int main()
{
    int T;
    scanf("%d",&T);
    long long int n,m;
    int cnt;
    long long int sum=0;
    while(T--)
    {
        scanf("%I64d%I64d",&n,&m);
        long long int maxx=m;
        int ll,rr;
        int cnt=0;
        while(m>0)
        {
            ans[cnt++]=(m&1);
            m/=2;
        }
        sum=0;
        for(int i=0;i<cnt;i++)
        {

            if(ans[i]==0)
            {
                if((maxx-sum-1)>=n)
                    ans[i]=1;
            }
            else
                sum+=pow(i);
        }
        sum=0;
        for(int i=0;i<cnt;i++)
        {
            if(ans[i])
            {
                sum+=pow(i);
            }
        }
        cout<<sum<<endl;
    }
}
