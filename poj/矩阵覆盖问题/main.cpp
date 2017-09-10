#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int n,m;
int dp[10][1005];
void init()
{
    dp[2][1]=1;
    dp[2][2]=2;
    for(int i = 3;i<1005;i++) dp[2][i]=(dp[2][i-1]+dp[2][i-2])%M,cout<<i<<' '<<dp[2][i]<<endl;

}
int main()
{
    init();
    while(~scanf("%d%d",&n,&m))
    {

    }
    return 0;
}
