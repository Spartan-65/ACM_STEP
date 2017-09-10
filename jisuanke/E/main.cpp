#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int r, c,t;
int sr,sc,er,ec;
char a[maxn][maxn];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int ans;
int vis[maxn][maxn];
struct node
{
    int r,c,step;
};
void bfs()
{
    queue<node> q;
    node u;
    q.push({sr,sc,0});
    while(!q.empty())
    {
        u=q.front(); q.pop();
        if(u.r==er&&u.c==ec) {ans=u.step;return;}
        bool flag=false;
        if((u.step+1)%t==0) flag=true;
        for(int i = 0;i<4;i++)
        {
            int tr=u.r+dir[i][0],tc=u.c+dir[i][1];
            if(tr<0||tr>=r||tc<0||tc>=c) continue;
            if((a[tr][tc]!='#'||flag))
            {
                q.push({tr,tc,u.step+1});
                vis[tr][tc]++;
            }
        }
    }
}

int main()
{
    int num;
    scanf("%d",&num);
    while(num--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d",&r,&c,&t);
        t+=1;ans=1e9;
        for(int i = 0;i<r;i++)
        {
            scanf("%s",a[i]);
            for(int j = 0;j<c;j++)
            {
                if(a[i][j]=='U') sr=i,sc=j;
                if(a[i][j]=='G') er=i,ec=j;
            }
        }
        bfs();
        if(ans==1e9) cout<<"Please give me another chance!"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
