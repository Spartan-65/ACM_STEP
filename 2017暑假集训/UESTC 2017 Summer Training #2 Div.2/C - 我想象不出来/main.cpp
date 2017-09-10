#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int C[50][50][30];
char a[maxn][maxn];
int n;
bool vis[50][50];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int w=n/2;
        memset(C,0,sizeof(C));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
            for(int j=0;j<n;j++)
            {
                int x=abs(i-w),y=abs(j-w);
                int t=x*x+y*y;
                if(a[i][j]=='.') C[x][y][26]++;
                else if(a[i][j]=='#') C[x][y][27]++;
                else
                {
                    C[x][y][a[i][j]-'a']++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<=w;i++)
            for(int j=0;j<=w;j++)
            {
                if(vis[i][j]) continue;
                if(i==0&&j==0) continue;
                int m=0;
                if(i==j)
                {
                    for(int k=0;k<30;k++)
                    {
                        if(C[j][i][k]>m) m=C[i][j][k];
                    }
                }
                else
                {
                    for(int k=0;k<30;k++)
                    {
                        if(C[i][j][k]+C[j][i][k]>m) m=C[i][j][k]+C[j][i][k];
                    }
                }
                if(i==j||(i==0||j==0)) ans+=(4-m);
                else ans+=(8-m);
                vis[i][j]=vis[j][i]=1;
            }
        cout<<ans<<endl;
    }
    return 0;
}
