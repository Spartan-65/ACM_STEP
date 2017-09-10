#include <bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
    int T;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            int n;scanf("%d",&n);
            for(int i=0;i<n;i++) scanf("%d",&a[i]);
            if(n==2){printf("%d\n",max(a[0],a[1])-min(a[0],a[1]));continue;}
            while(1)
            {
                sort(a,a+n);
                if(a[n-1]-a[0]==0) break;
                int t=a[n-1]-a[0];
                a[0]=a[n-1]=t;
            }
            printf("%d\n",a[0]);
        }
    }
}
