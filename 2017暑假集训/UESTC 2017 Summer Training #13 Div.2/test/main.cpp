#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,m;
int a[105];
int b[105];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&s);
        if(s==0)
        {
            if(n==1)
                printf("0 0\n");
            else
                printf("-1 -1\n");
            continue;
        }
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int t=n-1;
        while(s&&t>=0)
        {
            if(s>=9)
            {
                a[t]=9;
                b[t]=a[t];
                s-=9;
            }
            else
            {
                a[t]=s;
                b[t]=a[t];
                s=0;
            }
            t--;
        }
        if(s>0)
        {
            printf("-1 -1\n");
            continue;
        }
        if(a[0]==0)
        {
            a[0]=1;
            a[t+1]--;
        }
        for(int i=0;i<n;i++)
        {
            printf("%d",a[i]);
        }
        printf(" ");
        sort(b,b+n);
        for(int i=n-1;i>=0;i--)
        {
            printf("%d",b[i]);
        }
        printf("\n");
    }
    return 0;
}
