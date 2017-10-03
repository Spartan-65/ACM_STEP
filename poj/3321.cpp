#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+8;
struct data{
	int to,next;
}e[maxn<<1];
int n,cnt;
int last[maxn];
void init(){
	cnt=0;
}
void insert(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
int main()
{
	scanf("%d",&n);
	init();
	for(int i =1;i<n;i++)
	{
		int u,v;scanf("%d",&u,&v);
		insert(u,v);
	}
	return 0;
}
