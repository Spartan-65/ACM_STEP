#include <bits/stdc++.h>

using namespace std;

int n,m;
int M[105][105],v[105][105];
int Max;
int dir[4][2]={0,1,1,0,-1,0,0,-1};

void dfs(int x, int y, int Count)
{
    if(x<0||y<0||x>=n||y>=m) return ;
    if(Count>v[x][y]) v[x][y]=Count;
    else return ;
    for(int i = 0;i<4;i++)
    {
        int tx=dir[i][0]+x,ty=dir[i][1]+y;
        if(M[tx][ty]<M[x][y]) dfs(tx,ty,Count+1);
    }
    Max=Max>Count?Max:Count;
}


int main()
{
    cin>>n>>m;
    int mi,mj;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
        {
            scanf("%d",&M[i][j]);
        }
    Max=0;
    memset(v,0,sizeof(v));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
            if(!v[i][j]) dfs(i,j,1);
    }
    cout<<Max<<endl;
    return 0;
}
