#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
int m,n;
int mp[maxn][maxn];
int step[maxn][maxn];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
bool vis[maxn][maxn];
struct node
{
    int x,y,step;
};
void bfs()
{
    queue<node> q;
    q.push(node{1,1,0});
    int C=0;
    step[1][1]=0;
    while(!q.empty())
    {
        node u=q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=dir[i][0]*(mp[u.x][u.y])+u.x;
            int ty=dir[i][1]*(mp[u.x][u.y])+u.y;
            if(tx<1||tx>n||ty<1||ty>m) continue;
            if(step[tx][ty]==-1)
            {
                step[tx][ty]=u.step+1;
                q.push(node{tx,ty,step[tx][ty]});
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(step,-1,sizeof(step));
        for(int i=1;i<=n;i++)
        {
            char s[maxn];
            scanf("%s",s+1);
            for(int j=1;j<=m;j++)
                mp[i][j]=s[j]-'0';
        }
        bfs();
        if(step[n][m]==-1) cout<<"IMPOSSIBLE"<<endl;
        else cout<<step[n][m]<<endl;
    }
    return 0;
}
