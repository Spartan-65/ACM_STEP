#include <bits/stdc++.h>
using namespace std;

int n,m;
int si,sj,ei,ej,init_dir;
char ch;
int M[55][55];
int path[55][55][4];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
bool flag=true;
struct f
{
    int i,j;
    int d;
};


void bfs()
{
    queue<f> q;
    f u;
    u.i=si,u.j=sj,u.d=init_dir;
    path[u.i][u.j][u.d]=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.front();q.pop();
        //cout<<u.i<<' '<<u.j<<' '<<u.d<<endl;
        //cout<<path[u.i][u.j][u.d]<<endl;
        if(u.i==ei&&ej==u.j)
        {
            cout<<path[u.i][u.j][u.d]<<endl;
            flag=false;
            return ;
        }
        if(!path[u.i][u.j][(u.d+3)%4])
        {
            path[u.i][u.j][(u.d+3)%4]=path[u.i][u.j][u.d]+1;
            f v=u;
            v.d=(u.d+3)%4;
            q.push(v);
        }
        if(!path[u.i][u.j][(u.d+1)%4])
        {
            path[u.i][u.j][(u.d+1)%4]=path[u.i][u.j][u.d]+1;
            f v=u;
            v.d=(u.d+1)%4;
            q.push(v);
        }
        for(int i = 1;i<=3;i++)
        {
            int ti=u.i+dir[u.d][0]*i,tj=u.j+dir[u.d][1]*i;
            if(ti>=1&&ti<n&&tj>=1&&tj<m&&!path[ti][tj][u.d]&&!M[ti][tj])
            {
                path[ti][tj][u.d]=path[u.i][u.j][u.d]+1;
                f v=u;
                v.i=ti,v.j=tj;
                q.push(v);
            }
            else break;
        }
    }
    cout<<"-1"<<endl;
}
int main()
{
    cin>>n>>m;
    memset(M,0,sizeof(M));
    memset(path,0,sizeof(path));
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
        {
            cin>>M[i][j];
            if(M[i][j])
            {
                M[i-1][j-1]=M[i-1][j]=M[i][j-1]=1;
            }
        }
    char ch;
    cin>>si>>sj>>ei>>ej>>ch;
    if(ch=='N') init_dir=0;
    else if(ch=='E') init_dir=1;
    else if(ch=='S') init_dir=2;
    else init_dir=3;
    bfs();
    return 0;
}

