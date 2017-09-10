#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m,a[maxn][maxn];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            char s[maxn];scanf("%s",s+1);
            for(int j=1;j<=m;j++)
            {
                a[i][j]=s[j]-'0';
                if(a[i][j]) ans++;
            }
        }
        ans*=2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]>a[i][j-1]) ans+=(a[i][j]-a[i][j-1]);
                if(a[i][j]>a[i][j+1]) ans+=(a[i][j]-a[i][j+1]);
                if(a[i][j]>a[i-1][j]) ans+=(a[i][j]-a[i-1][j]);
                if(a[i][j]>a[i+1][j]) ans+=(a[i][j]-a[i+1][j]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
