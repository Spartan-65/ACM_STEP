#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans=0;

void dfs(int t,int num,int sum)
{
    if(t>=n) return ;
    if(num>=k) return;
    if(sum>n) return;
    if(k-1==num&&n-sum>=t) {ans++; return;}
    for(int i = t;i<=n-sum;i++)
        dfs(i,num+1,sum+i);
}

int main()
{

    while(~scanf("%d%d",&n,&k))
    {
        dfs(1,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
