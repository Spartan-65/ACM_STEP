#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct node{
    int l,r;
    int lm[2],rm[2];
    int m[2];
    int len;
}T[maxn<<2];
bool ch[maxn<<2];
void up(int k)
{
    T[k].lm[1]=T[k<<1].lm[1];
    if(T[k<<1].len==T[k<<1].lm[1])
        T[k].lm[1]+=T[k<<1|1].lm[1];

    T[k].lm[0]=T[k<<1].lm[0];
    if(T[k<<1].lm[0]==T[k<<1].len)
        T[k].lm[0]+=T[k<<1|1].lm[0];

    T[k].rm[1]=T[k<<1|1].rm[1];
    if(T[k<<1|1].rm[1]==T[k<<1|1].len)
        T[k].rm[1]+=T[k<<1].rm[1];

    T[k].rm[0]=T[k<<1|1].rm[0];
    if(T[k<<1|1].rm[0]==T[k<<1|1].len)
        T[k].rm[0]+=T[k<<1].rm[0];

    T[k].m[0]=max(max(T[k<<1].m[0],T[k<<1|1].m[0]),T[k<<1].rm[0]+T[k<<1|1].lm[0]);
    T[k].m[1]=max(max(T[k<<1].m[1],T[k<<1|1].m[1]),T[k<<1].rm[1]+T[k<<1|1].lm[1]);
}
void Swap(int k)
{
    swap(T[k].lm[0],T[k].lm[1]);
    swap(T[k].rm[0],T[k].rm[1]);
    swap(T[k].m[0],T[k].m[1]);
    ch[k]=!ch[k];
}
void pd(int k)
{
    if(ch[k])
    {
        Swap(k<<1);
        Swap(k<<1|1);
        ch[k]=0;
    }
}
void build(int k,int l,int r)
{
    T[k].l=l;
    T[k].r=r;
    T[k].m[0]=T[k].m[1]=T[k].lm[0]=T[k].lm[1]=T[k].rm[0]=T[k].rm[1]=0;
    T[k].len=(r-l+1);
    ch[k]=0;
    if(l==r)
    {
        scanf("%d",&T[k].m[1]);
        if(T[k].m[1]){
            T[k].lm[1]=T[k].rm[1]=1;
        }
        else {
            T[k].m[0]=T[k].lm[0]=T[k].rm[0]=1;
        }
        return ;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    up(k);
}
void update(int l,int r,int k)
{
    if(T[k].l==l&&T[k].r==r)
    {
        Swap(k);
        return ;
    }
    pd(k);
    int mid=(T[k].l+T[k].r)>>1;
    if(r<=mid)update(l,r,k<<1);
    else if(l>mid)update(l,r,k<<1|1);
    else{
        update(l,mid,k<<1);
        update(mid+1 ,r,k<<1|1);
    }
    up(k);
}
int query(int l,int r,int k)
{
    if(l==T[k].l&&r==T[k].r)
    {
        return T[k].m[1];
    }
    pd(k);
    int mid=(T[k].l+T[k].r)>>1;
    if(r<=mid) query(l,r,k<<1);
    else if(l>mid) query(l,r,k<<1|1);
    else{
        int M=min(mid-l+1,T[k<<1].rm[1])+min(r-mid,T[k<<1|1].lm[1]);
        int left=query(l,mid,k<<1);
        int right=query(mid+1,r,k<<1|1);
        return max(max(left,right),M);
    }
}
int main()
{
    int n;scanf("%d",&n);
    build(1,1,n);
    int m;scanf("%d",&m);
    while(m--)
    {
        int x,a,b;scanf("%d%d%d",&x,&a,&b);
        if(x)update(a,b,1);
        else printf("%d\n",query(a,b,1));
    }
    return 0;
}
