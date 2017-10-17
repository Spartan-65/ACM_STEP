#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=1e6+8;
struct data{
	int to,next;
}e[maxn<<1];
int n,cnt,m,id;
int last[maxn],q[maxn],st[maxn],ed[maxn];
int rl[maxn<<2],rr[maxn<<2],sum[maxn<<2];
//vector<int> E[maxn];
typedef vector<int> ve;
vector<ve> E(maxn);
void init(){
	cnt=id=0;
	memset(last,0,sizeof(last));
	memset(ed,0,sizeof(ed));
	memset(st,0,sizeof(st));
}
void ins(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x)
{
    q[++id]=x;
    st[x]=id;
    for(int i=0;i<E[x].size();i++)
    {
        dfs(E[x][i]);
    }
    ed[x]=id;
}
void build(int k,int l,int r)
{
    int mid=(l+r)>>1;
    rl[k]=l;rr[k]=r;
    if(l==r)
    {
        sum[k]=1;
        return ;
    }
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
int query(int k,int a,int b)
{
    int l=rl[k],r=rr[k],mid=(l+r)>>1;
    if(l==a&&r==b) return sum[k];
    if(b<=mid) return query(k<<1,a,b);
    else if(a>mid) return query(k<<1|1,a,b);
    else return query(k<<1,a,mid)+query(k<<1|1,mid+1,b);
}

void modify(int k,int x)
{
    int l=rl[k],r=rr[k],mid=(l+r)>>1;
    if(l==r)
    {
        sum[k]^=1;
        return;
    }
    if(x<=mid) modify(k<<1,x);
    else modify(k<<1|1,x);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
int main()
{
	scanf("%d",&n);
	init();
	for(int i =1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		//ins(u,v);
		E[u].push_back(v);
	}
	dfs(1);
	build(1,1,n);
	scanf("%d",&m);
	char ch;

	while(m--)
    {
        int x;
        scanf("%*c%c%d",&ch,&x);
        if(ch=='Q')
            printf("%d\n",query(1,st[x],ed[x]));
        else modify(1,st[x]);
    }
	return 0;
}
