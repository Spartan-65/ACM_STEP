#include <bits/stdc++.h>

using namespace std;
const int maxn=210;
int Map[maxn][maxn];
int R,C;
char ch;
const char alp[]="WAKJSD";
int cur;
char str[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
map<char, int> cnt;
const int s[16][4]={
    {0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},
    {0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},
    {1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},
    {1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}

};
bool f(int x, int y){
    return x>=0&&x<=R+1&&y>=0&&y<=C+1;
}
void print()
{
    for(int i = 0;i<=R;i++)
    {
        for(int j = 0;j<=C;j++){
            if(Map[i][j]>=0)putchar(' ');
            printf("%d",Map[i][j]);
        }

        puts("");
    }
    puts("");
}
void dfs(int x, int y)
{
    if(!f(x, y)||Map[x][y]!=0) return;
    Map[x][y]=-1;
    for(int i = -1;i<=1;i++)
        for(int j=-1;j<=1;j++)
        if(!i||!j){
        if(i==j)continue;
        else dfs(x+i,y+j);
        }
}
void dfs2(int x, int y)
{

    if(!f(x,y)||Map[x][y]!=1)return;
    Map[x][y]=-1;
    for(int i=-1;i<=1;i++)
        for(int j = -1;j<=1;j++)
        {
            if(!i||!j){
            if(Map[x+i][y+j]==0){cur++;dfs(x+i,y+j);}
            else dfs2(x+i,y+j);
            }
        }
}

int main()
{
    int Case=0;
    while(~scanf("%d%d",&R,&C))
    {
        cnt.clear();
        memset(Map,0,sizeof(Map));
        if(!R&&!C) return 0;
        for(int i=1;i<=R;i++)
        {
            getchar();
            int len=1;
            for(int j=1;j<=C;j++)
            {
                scanf("%c",&ch);
                for(int k = 0;k<16;k++){
                    if(ch==str[k]){ for(int x=0;x<4;x++) Map[i][len++]=s[k][x];break;}
                    }
            }
        }

        C <<= 2;
        //print();
        dfs(0,0);
        //print();
        for(int i=1;i<=R;i++)
        {
            for(int j= 1;j<=C;j++)
                if(Map[i][j]==1)
                {
                    cur=0;
                    dfs2(i,j);
                    cnt[alp[cur]]++;
                }
        }
        printf("Case %d: ",++Case);
        for(map<char, int>::iterator i=cnt.begin();i!=cnt.end();i++) while(i->second--) printf("%c",i->first);
        puts("");
    }
    return 0;
}
