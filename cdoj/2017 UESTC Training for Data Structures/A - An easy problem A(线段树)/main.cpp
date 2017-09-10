#include <bits/stdc++.h>
using namespace std;
const int maxn=50005;
struct node{
    int l,r,Max,Min;
}T[maxn<<2];

void build(int k,int l,int r)
{
    T[k].l=l;
    T[k].r=r;
    T[k].Max=0,T[k].Min=0;
    if(l==r) return ;
    int mid=(l+r)/2;
    build(2*k,l,mid);
    build(2*k+1,mid+1,r);
}
void ins(int n,int d,int k)
{
    if(T[k].l==d&&T[k].r==d)
    {
        T[k].Max=n;
        T[k].Min=n;
        return;
    }
    int mid=(T[k].l+T[k].r)/2;
    if(d<=mid){
        ins(n,d,2*k);
    }
    else {
        ins(n,d,2*k+1);
    }
    T[k].Max=max(T[2*k].Max,T[2*k+1].Max);
    T[k].Min=min(T[2*k].Min,T[2*k+1].Min);
}
int Find1(int l,int r,int k)
{
    if(T[k].l==l&&T[k].r==r)
    {
        return T[k].Max;
    }
    int mid=(T[k].l+T[k].r)/2;
    if(mid>=r) return Find1(l,r,2*k);
    else if(mid<l) return Find1(l,r,2*k+1);
    else return max(Find1(l,mid,2*k),Find1(mid+1,r,2*k+1));
}
int Find2(int l,int r, int k)
{
    if(T[k].l==l&&T[k].r==r)
    {
        return T[k].Min;
    }
    int mid=(T[k].l+T[k].r)/2;
    if(mid>=r)return Find2(l,r,2*k);
    else if(mid<l) return Find2(l,r,2*k+1);
    else return min(Find2(l,mid,2*k),Find2(mid+1,r,2*k+1));
}
int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        build(1,1,n);
        //cout<<"mark"<<endl;
        for(int i=1;i<=n;i++)
        {
            int t;scanf("%d",&t);
            ins(t,i,1);
        }
        for(int i=0;i<q;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            int Max=Find1(a,b,1);
            int Min=Find2(a,b,1);
            printf("%d\n",Max-Min);
        }
    }
}
