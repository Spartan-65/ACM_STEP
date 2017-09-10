#include <bits/stdc++.h>
using namespace std;
const int maxn=130;
int dp[maxn][maxn];
long long a[maxn];
int n;
void init()
{
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
}
int main()
{
    init();
    while(~scanf("%d",&n))
    {
        cout<<a[n]<<endl;
    }
    return 0;
}
