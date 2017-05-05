#include <bits/stdc++.h>

using namespace std;

int n,m;
int M[105][105],v[105][105];
int Max;
int dir[4][2]={0,1,1,0,-1,0,0,-1};

int dfs(int x, int y)
{
    for(int i = 0;i<4;i++)
    {
        int tx=dir[i][0]+x,ty=dir[i][1]+y;
        if(tx<0||ty<0||tx>=n||ty>=m) continue;
        if(M[tx][ty]<M[x][y])
        {
            if(v[tx][ty]) v[x][y]=max(v[tx][ty]+1,v[x][y]);
            else v[x][y]=max(dfs(tx,ty)+1,v[x][y]);

        }
    }
    return v[x][y];
}


int main()
{
    cin>>n>>m;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
        scanf("%d",&M[i][j]);
    Max=0;
    memset(v,0,sizeof(v));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            //if(!v[i][j])
            dfs(i,j);
            Max=max(Max,v[i][j]);
        }

    }
    cout<<Max+1<<endl;
    return 0;
}
