#include <bits/stdc++.h>
using namespace std;
int dirx[4] = {0, 1, 0, -1};
int diry[4] = {1, 0, -1, 0};
char board[15][15];
bool f(int a, int b)
{
    if(a<1||a>3||b<4||b>6) return false;
    int flag = 0;
    for(int i = a+1;i<=10;i++)
    {
        if((board[i][b]=='R'||board[i][b]=='G')&&flag == 0) return false;
        if(board[i][b] == 'C'&&flag == 1) return false;
        if(board[i][b] != '.') flag++;
        if(flag>1) break;
    }
    flag = 0;
    for(int i = a-1;i>0;i--)
    {
        if((board[i][b]=='R'||board[i][b]=='G')&&flag == 0) return false;
        if(board[i][b] == 'C'&&flag == 1) return false;
        if(board[i][b] != '.') flag++;
    }
    flag = 0;
    for(int i = b+1;i<=9;i++)
    {
        if(board[a][i] == 'R'&&flag == 0) return false;
        if(board[a][i] == 'C'&&flag == 1) return false;
        if(board[a][i] != '.') flag++;
        if(flag>1) break;
    }
    flag = 0;
    for(int i = b-1;i>0;i--)
    {
        if(board[a][i] == 'R'&&flag == 0) return false;
        if(board[a][i] == 'C'&&flag == 1) return false;
        if(board[a][i] != '.') flag++;
        if(flag>1) break;
    }
    if(board[a+1][b+1] == '.' && (board[a+2][b+1] == 'H' || board[a+1][b+2] == 'H')) return false;
    if(board[a+1][b-1] == '.' && (board[a+2][b-1] == 'H' || board[a+1][b-2] == 'H')) return false;
    if(board[a-1][b+1] == '.' && (board[a-2][b+1] == 'H' || board[a-1][b+2] == 'H')) return false;
    if(board[a-1][b-1] == '.' && (board[a-2][b-1] == 'H' || board[a-1][b-2] == 'H')) return false;
    return true;
}
int main()
{
    int n, m, k;
    while(1)
    {
        cin>>n>>m>>k;
        bool flag = false;
        if(!(n&&m&&k)) return 0;
        memset(board,'.',sizeof(board));
        for(int i = 0;i<n;i++)
        {
            char ch;
            int a, b;
            cin>>ch>>a>>b;
            board[a][b] = ch;
        }
        for(int i = 0;i<4;i++)
        {
            if(f(m+dirx[i],k+diry[i])) flag = true;
        }
        if(!flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
