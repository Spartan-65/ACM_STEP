#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int n;
int gcd(int m,int n)
{
    return m%n?gcd(n,m%n):n;
}
int main()
{
    int Count=0;

    while(~scanf("%d",&n))
    {
        int ji=0,ou=0;

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]&1)ji=i;
            else ou=i;
        }
        printf("Case %d: ",++Count);
        bool flag=1;
        for(int i=2;i<=n;i++)
        {
            a[1]=gcd(a[1],a[i]);
            if(a[1]==1) {
                flag=0;
                break;
            }
        }
        if(flag) printf("-1\n");
        else
        {
            printf("%d\n",2*(n-1));
            for(int i=2;i<=n;i++)
                printf("1 %d\n",i);
            for(int i=2;i<=n;i++)
                printf("1 %d\n",i);
        }
        printf("\n");
    }
    return 0;
}
