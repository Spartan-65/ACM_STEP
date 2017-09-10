#include <bits/stdc++.h>
using namespace std;
int n;
int Map[35][35];
int dir[4][2]{0,1,1,0,0,-1,-1,0};
struct f
{
    int i,j;

};
bool bush(f x)
{
    if(x.i<0||x.j<0||x.i>n+1||x.j>n+1||Map[x.i][x.j]==1||Map[x.i][x.j]==3) return false;
    return true;
}
void print()
{
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=n;j++)
            cout<<Map[i][j]<<' ';
            cout<<endl;
    }

}
void bfs()
{

    queue<f> q;
    Map[0][0]=3;
    f x;
    x.i=0,x.j=0;
    q.push(x);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i = 0;i<4;i++)
        {
            f next;
            next.i=x.i+dir[i][0];
            next.j=x.j+dir[i][1];
            if(bush(next))
            {
                q.push(next);
                Map[next.i][next.j]=3;
            }
        }
        //print();
    }
}

int main()
{
    cin>>n;
    memset(Map,0,sizeof(Map));

    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
                cin>>Map[i][j];
    bfs();
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
            if(Map[i][j]==3) printf("0 ");
            else if(Map[i][j]==0) printf("2 ");
            else printf("1 ");
        printf("\n");
    }
    return 0;
}
