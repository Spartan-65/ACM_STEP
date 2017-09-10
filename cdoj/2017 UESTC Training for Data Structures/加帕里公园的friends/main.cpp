#include <bits/stdc++.h>
using namespace std;
const int maxn=500001;
struct node{
    int v,sum,ml,mr;
    int l,r;
    void Set(int x){
        v=sum=ml=mr=x;
    }
}T[maxn<<2];
void up(int k)
{
    int ls=k<<1,rs=k<<1|1;
    T[k].sum=T[ls].sum+T[rs].sum;
    T[k].v=max(max(T[ls].v,T[rs].v),T[ls].mr+T[rs].ml);
    T[k].ml=max(T[ls].ml,T[ls].sum+T[rs].ml);
    T[k].mr=max(T[rs].mr,T[rs].sum+T[ls].mr);
}
void build(int l,int r,int k)
{
    T[k].l=l,T[k].r=r;
    T[k].Set(0);
    if(l==r)
    {
        int t;scanf("%d",&t);
        T[k].Set(t);
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,k<<1);
    build(mid+1,r,k<<1|1);
    up(k);
}
void update(int d,int k,int x)
{
    if(T[k].l==d&&T[k].r==d)
    {
        T[k].Set(x);
        return ;
    }
    int mid=(T[k].l+T[k].r)>>1;
    if(d<=mid) update(d,k<<1,x);
    else update(d,k<<1|1,x);
    up(k);
}
node query(int l,int r,int k)
{
    if(l==T[k].l&&r==T[k].r)
    {
        return T[k];
    }
    int mid=(T[k].l+T[k].r)>>1;
    if(r<=mid) return query(l,r,k<<1);
    else if(l>mid) return query(l,r,k<<1|1);
    else
    {
        node L,R,M;
        L=query(l,mid,k<<1);
        R=query(mid+1,r,k<<1|1);
        M.sum=L.sum+R.sum;
        M.v=max(max(L.v,R.v),L.mr+R.ml);
        M.ml=max(L.ml,L.sum+R.ml);
        M.mr=max(R.mr,R.sum+L.mr);
        return M;
    }
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        build(1,n,1);
        while(m--)
        {
            int x,a,b;scanf("%d%d%d",&x,&a,&b);
            if(x==1)printf("%d\n",query(a,b,1).v);
            else update(a,1,b);
        }
    }
    return 0;
}
