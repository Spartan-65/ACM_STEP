#include <bits/stdc++.h>
using namespace std;
struct node
{
    string s;
    int step;

};
char a[15][15];
int r,c;
const char str[]="flash";
int dir[8][2]={1,-1,1,0,1,1,0,-1,0,1,-1,-1,-1,0,-1,1};
int fnum(char ch)
{
    for(int i=0;i<5;i++) if(ch==str[i]) return i;
}
bool dfs(int num,int rr, int cc)
{
    if(rr<0||rr>=r||cc<0||cc>=c) return false;
    if(num==4) return true;
    bool flag=false;
    for(int i = 0;i<8;i++)
    {
        int x=rr+dir[i][0],y=cc+dir[i][1];
        if(num+1==fnum(a[x][y])) if(dfs(num+1,x,y)) return true;
    }
}

int main()
{
    while(~scanf("%d%d",&r,&c))
    {
        for(int i = 0;i<r;i++)
        {
            scanf("%s",&a[i]);
            for(int j = 0;j<c;j++)
                if(a[i][j]<97) a[i][j]+=32;
        }
        bool flag=false;
        for(int i = 0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
                if(a[i][j]=='f')
                {
                    flag=dfs(0,i,j);
                    if(flag) break;
                }
                if(flag) break;
        }
        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
