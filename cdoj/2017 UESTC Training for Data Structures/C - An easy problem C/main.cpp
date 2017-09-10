#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
long long add[maxn<<2],mul[maxn<<2],p,c,ans;
struct node
{
    int l,r;
    long long n;
}T[maxn<<2];
void build(int k,int l,int r)
{
    T[k].l=l;
    T[k].r=r;
    T[k].n=0;
    add[k]=0,mul[k]=1;
    if(l==r)
    {
        scanf("%lld",&T[k].n);
        return;
    }
    int mid=(l+r)/2;
    build(2*k,l,mid);
    build(2*k+1,mid+1,r);
    T[k].n=(T[2*k].n+T[2*k+1].n)%p;
}
void lazy(int k)
{
    if(mul[k]==1&&add[k]==0) return;
    add[k<<1]=(add[k<<1]*mul[k]+add[k])%p;
    add[k<<1|1]=(add[k<<1|1]*mul[k]+add[k])%p;
    mul[k<<1]=(mul[k<<1]*mul[k])%p;
    mul[k<<1|1]=(mul[k<<1|1]*mul[k])%p;
    T[k<<1].n=(mul[k]*T[k<<1].n+add[k]*(T[k<<1].r-T[k<<1].l+1))%p;
    T[k<<1|1].n=(mul[k]*T[k<<1|1].n+add[k]*(T[k<<1|1].r-T[k<<1|1].l+1))%p;
    add[k]=0,mul[k]=1;
}
void update(int l,int r,int k,int op)
{
    if(l==T[k].l&&r==T[k].r)
    {
        if(op==1)
        {
            T[k].n*=c;T[k].n%=p;
            mul[k]*=c;mul[k]%=p;
            add[k]*=c;add[k]%=p;
        }
        else
        {
            T[k].n=(T[k].n+c*(T[k].r-T[k].l+1))%p;
            add[k]+=c;add[k]%=p;
        }
        return ;
    }
    lazy(k);
    int mid=(T[k].l+T[k].r)>>1;
    if(r<=mid) update(l,r,2*k,op);
    else if(l>mid) update(l,r,2*k+1,op);
    else{
        update(l,mid,2*k,op);
        update(mid+1,r,2*k+1,op);
    }
    T[k].n=(T[k<<1].n+T[k<<1|1].n)%p;

}
long long qurey(int l,int r,int k)
{
    if(T[k].l==l&&T[k].r==r)
    {
        return T[k].n%p;
    }
    lazy(k);
    int mid=(T[k].l+T[k].r)>>1;
    if(r<=mid) return qurey(l,r,2*k);
    else if(l>mid) return qurey(l,r,2*k+1);
    else{
        return (qurey(l,mid,2*k)+qurey(mid+1,r,2*k+1))%p;
    }
}
int main()
{
    scanf("%d%lld",&n,&p);
    build(1,1,n);
    int q;scanf("%d",&q);
    while(q--){
        int op,a,b;scanf("%d%d%d",&op,&a,&b);
        if(op==3){
            printf("%lld\n",qurey(a,b,1));
        }
        else {
            scanf("%lld",&c);
            update(a,b,1,op);
        }
    }
    return 0;
}
