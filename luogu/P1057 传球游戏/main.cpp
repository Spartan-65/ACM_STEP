/*…ÓÀ—+º«“‰*/
/*
#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans;
bool flag[40][40];
int book[40][40];
int dfs(int num,int d)
{
    if(flag[num][d]) return book[num][d];
    int t=0;
    if(d==m)
    {
        if(num==0) return 1;
        return 0;
    }
    else{

        t+=dfs((num-1+n)%n,d+1);
        t+=dfs((num+1)%n,d+1);
        book[num][d]=t;
        flag[num][d]=1;
    }
    return t;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        ans=0;
        memset(flag,0,sizeof(flag));
        dfs(0,0);
        printf("%d\n",book[0][0]);
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,f[40][40];
    scanf("%d%d",&n,&m);
    f[0][0]=1;
    for(int i = 1;i<=m;i++)
        for(int j=0;j<n;j++)
        {
            f[i][j]=f[i-1][(j-1+n)%n]+f[i-1][(j+1)%n];
        }
    printf("%d\n",f[m][0]);
    return 0;
}







