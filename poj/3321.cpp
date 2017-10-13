#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+8;
struct data{
	int to,next;
}e[maxn<<1];
int n,cnt,m,id;
int last[maxn],q[maxn],st[maxn],ed[maxn];
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

void dfs(int x,int fa)
{
    cout<<"begin"<<endl;
    cout<<x<<' '<<fa<<endl;
    q[++id]=x;
    st[x]=id;
    for(int i=last[x];i;i=e[i].next)
    {
        if(e[i].to!=fa)
        {
            dfs(e[i].to,x);
        }
    }
    ed[x]=id;
    cout<<x<<' '<<id<<endl;
}

int main()
{
	scanf("%d",&n);
	init();
	for(int i =1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		ins(u,v);
	}
	dfs(1,0);
	scanf("%d",&m);
	char ch[10];
	//build(1,1,n);
	return 0;
}
