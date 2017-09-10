#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
char s[maxn];
unsigned long long dp[maxn];
int main()
{
    int T;scanf("%d",&T);
    int ca=0;
    while(T--)
    {
        scanf("%s",s+1);
        int len=strlen(s+1);
        memset(dp,0,sizeof(dp));
        dp[0]=1;s[0]='0';
        for(int i=1;i<=len;i++)
        {
            if(s[i]<='9'&&s[i]>='1')dp[i]+=dp[i-1];
            int t=(s[i-1]-'0')*10+s[i]-'0';
            if(t>=10&&t<=26) dp[i]+=dp[i-2];
        }
        printf("Case #%d: %llu\n",++ca,dp[len]);
    }
    return 0;
}
