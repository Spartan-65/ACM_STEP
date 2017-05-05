#include <bits/stdc++.h>
using namespace std;
const char *dirs="NESW";const char *turns="FLR";
const int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
int dir_id(char c){return strchr(dirs,c)-dirs;}
int turn_id(char c){return strchr(turns,c)-turns;}

struct node{
    int r, c, dir;
    node(int r, int c, int dir):r(r),c(c),dir(dir){}
    node(){}
};

node walk(node& u, int turn)
{
    int dir = u.dir;
    if(turn == 1) dir=(dir+3)%4;
    if(turn ==2 ) dir=(dir+1)%4;
    return node(u.r+dr[dir],u.c+dc[dir],dir);
}
node p[10][10][4];
int d[10][10][4];
bool Cross[10][10][4][3];
int r0,c0,r1,c1,r2,c2;
int dir;
bool inside(int r, int c)
{ return r>0&&r<10&&c>0&&c<10; }
void print(node u)
{
    vector<node> a;
    for(;;){
        a.push_back(u);
        if(d[u.r][u.c][u.dir]==0) break;
        u=p[u.r][u.c][u.dir];
    }
    a.push_back(node(r0,c0,dir));
    int cnt=0;
    for(int i = a.size()-1;i>=0;i--)
    {
        if(cnt%10==0) printf(" ");
        printf(" (%d,%d)",a[i].r,a[i].c);
        if(++cnt%10==0) printf("\n");
    }
    if(a.size()%10) printf("\n");
}
void solve()
{
    memset(d,-1,sizeof(d));
    memset(p,0,sizeof(p));
    queue<node>q;
    node u = node(r1,c1,dir);
    d[r1][c1][dir]=0;
    q.push(u);
    while(!q.empty())
    {

        u=q.front();q.pop();
        if(u.r==r2&&u.c==c2){
            print(u);
            return ;
        }
        for(int i=0;i<3;i++)
        {
            node v= walk(u,i);
            if(Cross[u.r][u.c][u.dir][i]&&inside(v.r,v.c)&&d[v.r][v.c][v.dir]<0)
            {
                d[v.r][v.c][v.dir]=d[u.r][u.c][u.dir]+1;
                p[v.r][v.c][v.dir]=u;
                q.push(v);
            }
        }
    }
    //print(u);
    printf("  No Solution Possible\n");
}

int main()
{
    char str[30];
    while(~scanf("%s",str)&&strcmp(str,"END"))
    {
        printf("%s\n",str);
        char ch;
        cin>>r0>>c0>>ch>>r2>>c2;
        dir = dir_id(ch);
        r1=r0+dr[dir];
        c1=c0+dc[dir];
        int r, c;
        char str2[30];
        memset(Cross,false,sizeof(Cross));
        while(cin>>r){
            if(r == 0){
                break;
            }
            cin >> c;
            while(cin >> str2){
                if(str2[0] == '*')
                    break;
                int dirID = dir_id(str2[0]);
                int len = strlen(str2);
                for(int i = 1;i < len;i++){
                    int turnID = turn_id(str2[i]);
                    Cross[r][c][dirID][turnID] = true;
                }
            }
        }
        solve();
    }
    return 0;
}
