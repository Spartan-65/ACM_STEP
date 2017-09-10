#include <bits/stdc++.h>
using namespace std;
#define base 10000
const int maxn=40;
int q[maxn][maxn];
void mul(int *a,int x)
{
    int temp=0;
    for(int i=maxn-1;i>=0;i--)
    {
        temp+=x*a[i];
        a[i]=temp%base;
        temp/=base;
    }
}

void div(int *a, int x)
{
    int t=0;
    for(int i=0;i<maxn;i++)
    {
        t=t*base+a[i];
        a[i]=t/x;
        t%=x;
    }
}
int main()
{
    q[0][maxn-1]=q[1][maxn-1]=1;
    for(int i=2;i<maxn;i++)
    {
        memcpy(q[i],q[i-1],maxn*sizeof(int));
        mul(q[i],4*i-2);
        div(q[i],i+1);
    }
    int n,ca=0;
    while(~scanf("%d",&n))
    {
        if(n==-1) return 0;
        int i=0,ans[maxn];
        memcpy(ans,q[n],maxn*sizeof(int));
        mul(ans,2);
        while(ans[i]==0) i++;
        printf("%d %d %d",++ca,n,ans[i++]);
        for(;i<maxn;i++)printf("%04d",ans[i]);
        printf("\n");
    }
}
