#include <bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
    int m,n;
    while(~scanf("%d%d",&m,&n))
    {
        if(m==0&&n==0) return 0;
        for(int i=0;i<m;i++) scanf("%d",&a[i]);
        int ans=0;
        while(n--)
        {
            bool flag=1;int t;
            for(int i=0;i<m;i++)
            {
                scanf("%d",&t);
                if(t>a[i])flag=0;
            }
            if(flag) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
