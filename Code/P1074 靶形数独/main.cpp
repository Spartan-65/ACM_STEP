#include <bits/stdc++.h>

using namespace std;

int M[10][10];
bool r[10][10],c[10][10],dist[10][10];
int cnt=81;
int ans=-1;
const int w[9][9]=
{{6,6,6,6, 6,6,6,6,6}
,{6,7,7,7, 7,7,7,7,6}
,{6,7,8,8, 8,8,8,7,6}
,{6,7,8,9, 9,9,8,7,6}
,{6,7,8,9,10,9,8,7,6}
,{6,7,8,9, 9,9,8,7,6}
,{6,7,8,8, 8,8,8,7,6}
,{6,7,7,7, 7,7,7,7,6}
,{6,6,6,6, 6,6,6,6,6}
};
int getdist(int i,int j)
{
    return (i/3)*3+(j/3);
}
void solve()
{
    int sum = 0;
    for(int i = 0;i<9;i++)
    for(int j = 0;j<9;j++)
    {
        sum+=(M[i][j]*w[i][j]);
    }
    ans=max(sum,ans);
}
void print()
{
    for(int i = 0;i<9;i++)
    {
        for(int j = 0;j<9;j++) cout<<M[i][j]<<' ';
        cout<<endl;
    }
}
void dfs(int n)
{
    if(n>cnt)
    {
        solve();
        return ;
    }
    //print();
    int x,y;
    int t,Min=81;
    for(int i = 0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if(!M[i][j])
            {
                t=0;
                for(int k=1;k<=9;k++)
                {
                    if(!r[i][k]&&!c[j][k]&&!dist[getdist(i,j)][k]) t++;
                }
                if(t<Min)
                {
                    Min=t;
                    x=i;
                    y=j;
                    //cout<<x<<' '<<y<<endl;
                }
            }
        }
    for(int i = 1;i<=9;i++)
    {
        if(!r[x][i]&&!c[y][i]&&!dist[getdist(x,y)][i])
        {
            //cout<<n<<' '<<x<<' '<<y<<' '<<i<<endl;
            M[x][y]=i;
            r[x][i]=1;
            c[y][i]=1;
            dist[getdist(x,y)][i]=1;
            dfs(n+1);
            M[x][y]=0;
            r[x][i]=c[y][i]=dist[getdist(x,y)][i]=0;
        }
    }
}

int main()
{
    memset(M,0,sizeof(M));
    memset(r,0,sizeof(r));
    memset(c,0,sizeof(c));
    memset(dist,0,sizeof(dist));
    for(int i = 0;i<9;i++)
        for(int j = 0;j<9;j++)
        {
            cin>>M[i][j];
            if(M[i][j])
            {
                cnt--;
                r[i][M[i][j]]=1;
                c[j][M[i][j]]=1;
                dist[getdist(i,j)][M[i][j]]=1;
            }
        }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
