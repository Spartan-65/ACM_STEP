#include <bits/stdc++.h>
using namespace std;
#define N 50000
int ans;
struct tree
{
    int l,r,n;
}T[N<<2];

void build(int l, int r, int k)
{
    //cout<<l<<' '<<r<<' '<<k<<endl;
    T[k].l=l;
    T[k].r=r;
    T[k].n=0;
    if(l==r) return;
    int mid=(l+r)/2;
    build(l,mid,2*k);
    build(mid+1,r,2*k+1);
}

void ins(int n,int d,int k)
{
    //cout<<d<<' '<<k<<endl;
    int mid;
    if(T[k].l==T[k].r&&T[k].l==d)
    {
        T[k].n+=n;
        return;
    }
    //cout<<"mark"<<endl;
    mid=(T[k].l+T[k].r)/2;
    if(d<=mid) ins(n,d,2*k);
    else ins(n,d,2*k+1);
    T[k].n=T[2*k].n+T[2*k+1].n;
    //cout<<T[k].l<<' '<<T[k].r<<endl;
    //cout<<T[k].n<<endl;
    //cout<<endl;
}

void sea(int l,int r,int k)
{
    //cout<<ans<<endl;
    int mid;
    if(T[k].l==l&&T[k].r==r)
    {
        ans+=T[k].n;
        return;
    }
    mid=(T[k].l+T[k].r)/2;
    if(mid>=r) sea(l,r,2*k);
    else if(mid<l) sea(l,r,2*k+1);
    else{
        sea(l,mid,k*2);
        sea(mid+1,r,k*2+1);
    }
}
int main()
{
    int Count=0;
    int n,Q,t;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        build(1,n,1);
        for(int i =1;i<=n;i++)
        {
            scanf("%d",&t);
            ins(t,i,1);
        }
        printf("Case %d:\n",++Count);
        while(1)
        {
            ans=0;
            char s[20];
            int a, b;
            scanf("%s",&s);
            if(s[0]=='E') break;
            scanf("%d%d",&a,&b);
            if(s[0]=='Q') sea(a,b,1),printf("%d\n",ans);

            if(s[0]=='A') ins(b,a,1);
            if(s[0]=='S') ins(-b,a,1);
        }
    }
    return 0;
}
