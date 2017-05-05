#include <bits/stdc++.h>

using namespace std;
int dir[4][2]={1,0,0,1,-1,0,0,-1 };
int sx,sy,fx,fy;
int m,n;
int Count;
int Map[10][10];
void print()
{
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=m;j++) cout<<Map[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;

}
void dfs(int x, int y)
{
    //print();
    if(Map[y][x]==0) return ;
    if(x==fx&&y==fy) {Count++; return ;}
    Map[y][x]=0;
    for(int i = 0;i<4;i++)
    {
        int xx, yy;
        xx=x+dir[i][0],yy=y+dir[i][1];
        if(Map[yy][xx]){
            dfs(xx,yy);
            Map[yy][xx]=1;
        }
    }
}
int main()
{
    int t;
    while(cin>>n>>m>>t)
    {
        Count=0;
        memset(Map,0,sizeof(Map));
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=m;j++)
                Map[i][j]=1;
        cin>>sx>>sy>>fx>>fy;
        for(int i = 0;i<t;i++)
        {
            int x,y;
            cin>>x>>y;
            Map[y][x]=0;
        }
        dfs(sx,sy);
        cout<<Count<<endl;
    }
    return 0;
}
