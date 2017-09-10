#include <bits/stdc++.h>
using namespace std;
int n,s;
int a[105];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&s);
        memset(a,0,sizeof(a));
        if(n*9<s)
        {
            printf("-1 -1\n");
            continue;
        }
        if(s==0)
        {
            if(n==1) { printf("0 0\n"); }
            else printf("-1 -1\n");
            continue;
        }
        for(int i=0;i<n;i++)
            a[i]=9;
        int t=n*9-s;
        if(t>=8) {a[0]=1;t-=8;}
        else {a[0]-=t;t=0;}
        int p=1;
        while(t>=9&&p<n)
        {
            a[p]=0;
            t-=9;
            p++;
        }
        if(t>0) a[p]-=t;
        for(int i=0;i<n;i++)
            printf("%d",a[i]);
        printf(" ");

        for(int i=0;i<n;i++)
            a[i]=9;
        p=n-1;
        t=n*9-s;
        while(t>=9)
        {
            a[p]=0;
            t-=9;
            p--;
        }
        if(t) a[p]-=t;
        for(int i=0;i<n;i++)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
