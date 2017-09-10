#include <bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+5;
long long a[maxn];
int main()
{
    int n;
    long long sum1=0,sum2=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]),sum2+=a[i];
    sum1=a[0],sum2-=a[0];
    long long Min=abs(sum1-sum2);
    for(int i=1;i<n-1;i++)
    {
        Min=min(Min,abs(sum1-sum2));
        sum1+=a[i];sum2-=a[i];
    }
    cout<<Min<<endl;
    return 0;
}
