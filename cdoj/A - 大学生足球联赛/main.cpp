#include <bits/stdc++.h>
using namespace std;
const int maxn=70;
int a[maxn];
int n;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i<=n;i++) a[i]=i;
        for(int i = 1;i<n;i++)
        {
            int l=1,r=n;
            while(l<=r)
            {
                printf("%d %d ",a[l],a[r]);
                l++,r--;
            }
            int t=a[n];
            for(int j = n;j>2;j--)
            {
                a[j]=a[j-1];
            }
            a[2]=t;
            printf("\n");
        }
    }
    return 0;
}
