#include <bits/stdc++.h>
using namespace std;
const int maxn=3000;
char mp[maxn][maxn];
int n,m;
int si,sj;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
bool vis[maxn][maxn];
struct node
{
    int x,y;
}a[maxn][maxn];
bool dfs(const int x,const int y)
{
    int xx=(x%n+n)%n,yy=(y%m+m)%m;
    if(mp[xx][yy]=='#') return false;
    if(vis[xx][yy]) return a[xx][yy].x!=x||a[xx][yy].y!=y;
    vis[xx][yy]=1;
    a[xx][yy].x=x,a[xx][yy].y=y;
    for(int i=0;i<4;i++)
        if(dfs(x+dir[i][0],y+dir[i][1])) return true;
    return false;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            scanf("%s",&mp[i]);
            for(int j=0;j<m;j++)
                if(mp[i][j]=='S') si=i,sj=j;
        }
        if(dfs(si,sj)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
