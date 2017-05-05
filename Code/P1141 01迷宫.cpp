#include <bits/stdc++.h>
using namespace std;
bool Map[1005][1005];
int v[1000][1000];
int ans[100001];
int dir[4][2]{0,1,1,0,-1,0,0,-1};
int n;
struct f
{
	int i,j;
	bool last;
};
void bfs(int c,int i, int j)
{
	queue<f> q;
	f t;
	t.i=i,t.j=j,t.last=Map[i][j];
	q.push(t);
	v[i][j]=c;
	int sum=1;
	while(!q.empty())
	{
		t=q.front();q.pop();
		for(int k = 0;k<4;k++)
		{
			int ti=dir[k][0]+t.i,tj=dir[k][1]+t.j;
			if(ti<0||ti>=n||tj<0||tj>=n) continue;
			if(v[ti][tj]||t.last==Map[ti][tj]) continue;
			sum++;
			f next{ti,tj,Map[ti][tj]};
			q.push(next);
			v[ti][tj]=c;
		}
	}
	ans[c]=sum;
}
int main()
{
	int m;
	cin>>n>>m;
	for(int i = 0;i<n;i++)
	{
		string s;
		cin>>s;
		for(int j = 0;j<n;j++)
		{
			char ch=s[j];
			if(ch=='1') Map[i][j]=1;
			else Map[i][j]=0;
		
		}
	}
	for(int i = 1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		if(!v[a-1][b-1])bfs(i,a-1,b-1);
		else ans[i]=ans[v[a-1][b-1]];
		cout<<ans[i]<<endl;
	}
	return 0;
}
