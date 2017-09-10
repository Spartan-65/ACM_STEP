#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],M[maxn],m[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(M,-1,sizeof(M));
        int t=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            t=max(a[i],t);
            M[i]=t;
        }
        t=1e9;
        for(int i=n-1;i>=0;i--)
        {
            t=min(t,a[i]);
            m[i]=t;
        }
        t=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=m[i]&&a[i]>=M[i]) t++;
        }
        cout<<t<<endl;
    }

    return 0;
}
