#include <bits/stdc++.h>

using namespace std;
int R, C;
const int maxn=100+5;
char filed[maxn][maxn];
void dfs(int r, int c)
{
    if(r<0||r>=R||c<0||c>=C||filed[r][c]!='@') return;
    filed[r][c]='*';
    for(int i=-1;i<=1;i++)
        for(int j = -1;j<=1;j++)
        if(i!=0||j!=0) dfs(r+i,c+j);
}
int main()
{
    while(~scanf("%d%d",&R,&C))
    {
        if(!R&&!C) return 0;
        int ans=0;
        memset(filed,'*',sizeof(filed));
        for(int i = 0;i<R;i++)
            scanf("%s",filed[i]);
        for(int i = 0;i<R;i++)
            for(int j = 0;j<C;j++)
            {
                if(filed[i][j]=='@') dfs(i,j),ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}
