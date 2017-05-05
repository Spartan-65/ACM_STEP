#include <bits/stdc++.h>
using namespace std;
#define N 50000
int Max,Min;
struct node
{
    int l,r,M,m;
}T[N<<2];

void build(int l,int r,int k)
{
    T[k].l=l;
    T[k].r=r;
    T[k].M=0;
    T[k].m=0;
    if(l==r) return;
    int mid=(l+r)/2;
    build(l,mid,2*k);
    build(mid+1,r,2*k+1);
}
void ins(int n, int d,int k)
{
    if(T[k].l==T[k].r&&T[k].l==d)
    {
        T[k].M=T[k].m=n;
        return;
    }
    int mid=(T[k].l+T[k].r)/2;
    if(mid>=d)ins(n,d,2*k);
    else ins(n,d,2*k+1);
    T[k].M=max(T[2*k].M,T[2*k+1].M);
    T[k].m=min(T[2*k].m,T[2*k+1].m);
}
void sea(int l,int r,int k)
{
    if(T[k].l==l&&T[k].r==r)
    {
        Max=T[k].M;
        Min=T[k].m;
        return;
    }
    int mid=(T[k].l+T[k].r)/2;
    if(mid>=r) sea(l,r,2*k);
    else if(mid<l) sea(l,r,2*k+1);
    else{
        sea(l,mid,2*k);
        int M1=Max,m1=Min;
        sea(mid+1,r,2*k+1);
        int M2=Max,m2=Min;
        Max=max(M1,M2);
        Min=min(m1,m2);
    }
}
int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        build(1,n,1);
        for(int i = 1;i<=n;i++)
        {
            int t; scanf("%d",&t);ins(t,i,1);
        }

        for(int i = 0;i<q;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            sea(a,b,1);
            printf("%d\n",Max-Min);
        }
    }
    return 0;
}
