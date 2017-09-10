#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn],dp[maxn];
int main()
{
    int n;
    std::ios::sync_with_stdio(false);
    while(cin>>n&&n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) cin>>a[i];
        int m;cin>>m;
        if(m<5) {cout<<m<<endl;continue;}
        sort(a,a+n);
        for(int i=0;i<n-1;i++)
        {
            for(int j=m-5;j>=a[i];j--)
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
        cout<<(m-dp[m-5]-a[n-1])<<endl;
    }
    return 0;
}
