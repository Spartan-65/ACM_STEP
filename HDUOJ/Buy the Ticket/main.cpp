#include <bits/stdc++.h>
using namespace std;
#define debug 1
const int base=10000;
const int maxn=205;
int m,n;
int q[maxn][maxn];
void mul(int *a,int x)
{
    int temp=0;
    for(int i=maxn-1;i>=0;i--)
    {
        temp+=a[i]*x;
        a[i]=temp%base;
        temp/=base;
    }
}
void div(int *a,int x)
{
    int temp=0;
    for(int i=0;i<maxn;i++)
    {
        temp=temp*base+a[i];
        a[i]=temp/x;
        temp%=x;
    }
}
void init()
{
    q[1][maxn-1]=q[0][maxn-1]=1;
    for(int i=2;i<maxn;i++)
    {
        memcpy(q[i],q[i-1],maxn*sizeof(int));
        mul(q[i],i);
    }
}
void print(int *a)
{
    int i=0;
    while(a[i]==0) i++;
    printf("%d",a[i++]);
    for(;i<maxn;i++)
    printf("%04d",a[i]);
    printf("\n");
}

int main()
{
    #if debug
    freopen("test.in","r",stdin);
    #endif
    int ca=0;
    init();
    while(~scanf("%d%d",&m,&n),m||n)
    {
        printf("Test #%d:\n",++ca);
        if(n>m){printf("0\n");continue;}
        int ans[maxn];
        memcpy(ans,q[m+n],maxn*sizeof(int));
        mul(ans,m-n+1);
        div(ans,m+1);
        print(ans);
    }
    return 0;
}
