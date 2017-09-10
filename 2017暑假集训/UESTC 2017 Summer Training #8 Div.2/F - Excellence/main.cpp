#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int Min=1e9;
    for(int i=0;i<n/2;i++)
    {
        int t=a[i]+a[n-i-1];
        Min=min(t,Min);
    }
    cout<<Min<<endl;
    return 0;
}
