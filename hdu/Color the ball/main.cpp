#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+8;
int lazy[maxn<<2];
int ans;
struct node {
    int l,r;
    int n;
}T[maxn<<2];
void down(int k)
{
    if(!lazy[k])return ;
    lazy[k<<1]+=lazy[k];
    lazy[k<<1|1]+=lazy[k];
    T[k<<1].n+=(T[k<<1].r-T[k<<1].l+1)*lazy[k];
    T[k<<1|1].n+=(T[k<<1|1].r-T[k<<1|1].l+1)*lazy[k];
    lazy[k]=0;
}
void build(int l,int r,int k)
{
    T[k].l=l;
    T[k].r=r;
    if(l==r)
    {
        T[k].n=0;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,k<<1);
    build(mid+1,r,k<<1|1);
}
void update(int l,int r,int k)
{
    if(T[k].l==l&&T[k].r==r)
    {
        T[k].n+=(r-l+1);
        lazy[k]+=1;
        return;
    }
    down(k);
    int mid=(T[k].l+T[k].r)>>1;
    if(r<=mid) update(l,r,k<<1);
    else if(l>mid) update(l,r,k<<1|1);
    else {
        update(l,mid,k<<1);
        update(mid+1,r,k<<1|1);
    }
}
int query(int d,int k)
{
    if(T[k].l==d&&T[k].r==d){
        return T[k].n;
    }
    down(k);
    int mid=(T[k].r+T[k].l)>>1;
    if(d<=mid) return query(d,k<<1);
    else return query(d,k<<1|1);
}

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        memset(lazy,0,sizeof(lazy));
        build(1,n,1);
        for(int i=0;i<n;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            update(x,y,1);
        }
        printf("%d",query(1,1));
        for(int i=2;i<=n;i++)
        {
            printf(" %d",query(i,1));
        }
        printf("\n");
    }

    return 0;
}
