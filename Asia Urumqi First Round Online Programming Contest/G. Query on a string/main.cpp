#include <bits/stdc++.h>
using namespace std;
int Len;
const int maxn=100008;
int ans;
string s1,s2;
struct node{
    int l,r;
    string sl,sr;
    int n;
}T[maxn<<2];
int fi(const char* a,const char* b)
{
    int cnt = 0;
    int i=0,j=0;
    while(a[i]!='\0')
    {
        j = 0;
        bool flag = true;
        while(b[j]!='\0')
        {
            if(a[i]!=b[j])
            {
                flag = false;
                break;
            }
            j++;
        }
        if(flag)
            cnt++;
        i++;
    }
    return cnt;
}
void up(int k)
{
    int ls=k<<1,rs=k<<1|1;
    T[k].l = T[ls].n;
    T[k].r = T[rs].n;
    string ts = (T[ls].sl+T[rs].sr);
    T[k].n=T[ls].n+T[rs].n+fi(ts.c_str(), s2.c_str());
    T[k].sl = T[ls].sl;
    T[k].rl = T[rs].sr;
}

void build(int l,int r,int k)
{
    T[k].l=l,T[k].r=r;
    T[k].sl.clear();T[k].sr.clear();
    T[k].n=0;
    if(l==r)
    {
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,k<<1);
    build(mid+1,r,k<<1|1);
}
void update(int k,char ch,int d)
{
    if(T[k].l==d&&T[k].r==d)
    {
        T[k].sl=T[k].sr=ch;
        return ;
    }
    int mid=(T[k].l+T[k].r)>>1;
    if(d<=mid) update(k<<1,ch,d);
    else update(k<<1|1,ch,d);
    up(k);
}
void query(int l,int r,int k)
{
    if(T[k].l==l&&T[k].r==r)
    {
        ans+=T[k].n;
        return;
    }
    int mid=(T[k].l+T[k].r)>>1;
    if(r<=mid) query(l,r,k<<1);
    else if(l>mid) query(l,r,k<<1|1);
    else{
        query(l,mid,k<<1);
        query(mid+1,r,k<<1|1);
    }
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        cin>>s1>>s2;
        build(1,s1.size(),1);
        Len=s2.size();
        for(int i=0;i<s1.size();i++)
        {
            update(1,s1[i],i+1);
        }
        while(n--)
        {
            char ch;int a,b;
            cin>>ch>>a;
            if(ch=='Q') {
                cout<<ch<<endl;
                scanf("%d",&b);
                query(a,b,1);
                printf("%d\n",ans);
            }
            else{
                cout<<ch<<endl;
                cin>>ch;
                update(1,ch,a);
            }
        }
    }
    return 0;
}
