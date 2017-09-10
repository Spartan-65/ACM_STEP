#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int n,s;
int main()
{
    while(~scanf("%d%d",&n,&s))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int i=0,j=n-1;
        int C=0;
        int ans=n;
        while(i<j)
        {
            if(a[i]+a[j]>s) b[C++]=a[i++],b[C++]=a[j--];
            else b[C++]=a[i++],b[C++]=a[i++],ans--;
        }
        if(i==j) b[C++]=a[i];
        printf("%d\n%d",ans,b[0]);
        for(int i=1;i<n;i++)printf(" %d",b[i]);
        printf("\n");
    }
    return 0;
}
