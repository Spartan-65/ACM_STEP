#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+5;
int n,m;
__int64 lazy[maxn<<2];

struct node
{
    int l,r;
    __int64 n;
}T[maxn<<2];
__int64 ans;

void build(int l, int r, int k)
{
    T[k].l=l;
    T[k].r=r;
    if(l==r)
    {
        __int64 t;
        scanf("%I64d",&t);
        T[k].n=t;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*k);
    build(mid+1,r,2*k+1);
    T[k].n=T[2*k].n+T[2*k+1].n;
}
void update_lazy(int x)
{
    T[2*x].n+=(lazy[x]*(T[2*x].r-T[2*x].l+1));
    T[2*x+1].n+=(lazy[x]*(T[2*x+1].r-T[2*x+1].l+1));
    lazy[2*x]+=lazy[x];
    lazy[2*x+1]+=lazy[x];
    lazy[x]=0;
}
void update(int n,int l,int r,int k)
{
    if(l==T[k].l&&r==T[k].r)
    {
        T[k].n+=(n*(T[k].r-T[k].l+1));
        lazy[k]+=n;
        return;
    }
    if(lazy[k]) update_lazy(k);
    int mid=(T[k].l+T[k].r)>>1;
    if(mid<l)
    {
        update(n,l,r,2*k+1);
    }
    else if(mid>=r)
    {
        update(n,l,r,2*k);
    }
    else
    {
        update(n,l,mid,2*k);
        update(n,mid+1,r,2*k+1);
    }
    T[k].n=(T[2*k].n+T[2*k+1].n);
}
void f(int l,int r,int k)
{
    if(T[k].l==l&&T[k].r==r)
    {
        ans+=T[k].n;
        return;
    }
    if(lazy[k]) update_lazy(k);
    int mid=(T[k].l+T[k].r)>>1;
    if(l>mid)
    {
        f(l,r,2*k+1);
    }
    else if(r<=mid)
    {
        f(l,r,2*k);
    }
    else
    {
        f(l,mid,2*k);
        f(mid+1,r,2*k+1);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(lazy,0,sizeof(lazy));
        build(1,n,1);
        for(int i = 0;i<m;i++)
        {
            char ch;
            cin>>ch;
            if(ch=='Q')
            {
                int a,b;
                cin>>a>>b;
                ans=0;
                f(a,b,1);
                printf("%I64d\n",ans);
            }
            else
            {
                int a,b,c;
                scanf("%d%d%d",&a,&b,&c);
                update(c,a,b,1);
            }
        }
    }
    return 0;
}
