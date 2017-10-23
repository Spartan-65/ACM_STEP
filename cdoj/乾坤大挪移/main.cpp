#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+8;
int a[maxn],b[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]),sum1+=a[i];
        for(int i=0;i<n;i++) scanf("%d",&b[i]),sum2+=b[i];
        bool flag=(sum1==sum2);
        for(int i=1;i<n-1;i++)
        {
            a[i] -=(b[i-1]-a[i-1])*2;
            a[i+1] += b[i-1]-a[i-1];
            a[i-1] += b[i-1]-a[i-1];
        }
        if(a[n-1]!=b[n-1]) flag=0;
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
