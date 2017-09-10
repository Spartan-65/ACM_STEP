#include <bits/stdc++.h>
using namespace std;
int n;
#define debug 1
#define base 10000
const int maxn=205;
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
    q[0][maxn-1]=q[1][maxn-1]=1;
    for(int i=2;i<maxn;i++)
    {
        memcpy(q[i],q[i-1],maxn*sizeof(int));
        mul(q[i],4*i-2);
        div(q[i],i+1);
    }
}
void print(int *ans)
{
    int i=0;
    while(ans[i]==0)i++;
    printf("%d",ans[i++]);
    for(;i<maxn;i++)printf("%04d",ans[i]);
    printf("\n");
}
int main()
{
    init();
    int n;
    while(~scanf("%d",&n),n)
    {
        int ans[maxn];
        memcpy(ans,q[n],maxn*sizeof(int));
        for(int i=2;i<=n;i++) mul(ans,i);
        print(ans);
    }
    return 0;
}
