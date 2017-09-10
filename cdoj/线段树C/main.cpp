#include <bits/stdc++.h>

using namespace std;
#define N 100000
int add[N<<2],mul[N<<2];
int c;
struct node
{
    int l,r,n;
}T[N<<2];
int p;
void build(int l, int r, int k)
{
    T[k].l=l;
    T[k].r=r;
    T[k].n=0;
    add[k]=0,mul[k]=1;
    if(l==r) return ;
    int mid=(l+r)/2;
    build(l,mid,2*k);
    build(mid+1,r,2*k+1);
}
void ins(int n,int d, int k)
{
    if(T[k].l==T[k].r&&T[k].l==d)
    {
        T[k].n=(T[k].n+n)%p;
        return;
    }
    int mid=(T[k].l+T[k].r)/2;
    if(mid<d) ins(n,d,2*k+1);
    else ins(n,d,2*k);
    T[k].n=(T[2*k].n+T[2*k+1].n)%p;
}
void pushdown(int k)
{
    if(add[k]!=0&&mul[k]!=1){
        add[k<<1]=(add[k<<1]*mul[k]+add[k])%p;
        add[k<<1|1]=(add[k<<1|1]*mul[k]+add[k])%p;
        mul[k<<1]=mul[k<<1]*mul[k]%p;
        mul[k<<1|1]=mul[k<<1|1]*mul[k]%p;
        T[k<<1].n=(T[k<<1].n*mul[k]+add[k]*(T[k<<1].r-T[k<<1].l+1))%p;
        T[k<<1|1].n=(T[k<<1|1].n*mul[k]+add[k]*(T[k<<1|1].r-T[k<<1|1].l+1))%p;
        add[k]=0,mul[k]=1;
    }

}
void update(int l,int r,int k,int m)
{
    if(l==T[k].l&&r==T[k].r)
    {
        if(m==2)
        {
            T[k].n=(T[k].n+c*(r-l+1))%p;
            add[k]=(add[k]+c)%p;
        }
        else {
            T[k].n=(T[k].n*c)%p;
            add[k]=(add[k]*c)%p;
            mul[k]=(mul[k]*c)%p;
        }
        return;
    }
    pushdown(k);
    int mid=(T[k].l+T[k].r)/2;
    if(l>mid) update(l,r,2*k+1,m);
    else if(r<=mid) update(l,r,2*k,m);
    else{
        update(l,mid,2*k,m);
        update(mid+1,r,2*k+1,m);
    }
    T[k].n=(T[2*k].n+T[2*k+1].n)%p;
}

int query(int l, int r,int k)
{
    if(l==T[k].l&&r==T[k].r)
    {
        return T[k].n;
    }
    pushdown(k);

    int mid=(T[k].l+T[k].r)/2;
    if(mid>=r) return query(l,r,2*k)%p;
    else if(mid<l) return query(l,r,2*k+1)%p;
    else return (query(l,mid,2*k)+query(mid+1,r,2*k+1))%p;
}

int main()
{
    int n;
    while(~scanf("%d%d",&n,&p))
    {
        build(1,n,1);
        for(int i = 1;i<=n;i++)
        {
            int t;
            scanf("%d",&t);
            ins(t,i,1);
        }
        scanf("%d",&n);
        while(n--)
        {
            int x,l,r;
            scanf("%d%d%d",&x,&l,&r);
            if(x!=3)
            {
                scanf("%d",&c);
                update(l,r,1,x);
            }
            else printf("%d\n",query(l,r,1));
        }
    }
    return 0;
}
