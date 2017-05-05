#include <bits/stdc++.h>

using namespace std;
#define maxn 100000
int p;
int ans;
struct node
{
    int l,r,n;
}T[maxn<<2];

void build(int l, int r, int k)
{
    T[k].l=l;
    T[k].r=r;
    T[k].n=0;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(l,mid,2*k);
    build(mid+1,r,2*k+1);
}

void ins(int n,int d,int k,int m)
{
    if(T[k].l==T[k].r&&T[k].l==d)
    {
        if(m==2)T[k].n=(T[k].n+n)%p;
        else T[k].n=(T[k].n*n)%p;
        return;
    }
    int mid=(T[k].l+T[k].r)>>1;
    if(mid>=d) ins(n,d,2*k,m);
    else ins(n,d,2*k+1,m);
    T[k].n=(T[2*k].n+T[2*k+1].n)%p;
}

void sea(int l,int r,int k)
{
    if(T[k].l==l&&T[k].r==r)
    {
        ans=(ans+T[k].n)%p;
        return ;
    }
    int mid=(T[k].l+T[k].r)>>1;
    if(r<=mid) sea(l,r,2*k);
    else if(l>mid) sea(l,r,2*k+1);
    else{
        sea(l,mid,2*k);
        sea(mid+1,r,2*k+1);
    }
}

int main()
{
    int n;
    while(~scanf("%d%d",&n,&p))
    {
        build(1,n,1);
        for(int i = 1;i<=n;i++)
        {
            int t;scanf("%d",&t);ins(t,i,1,2);
        }
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int x,l,r;
            scanf("%d%d%d",&x,&l,&r);
            if(x==3)
            {
                ans=0;
                sea(l,r,1);
                printf("%d\n",ans);
            }
            if(x==2)
            {
                int t;
                scanf("%d",&t);
                for(int j = l;j<=r;j++)
                    ins(t,j,1,2);
            }
            if(x==1)
            {
                int t;
                scanf("%d",&t);
                for(int j = l;j<=r;j++)
                    ins(t,j,1,1);
            }
        }
    }
    return 0;
}
