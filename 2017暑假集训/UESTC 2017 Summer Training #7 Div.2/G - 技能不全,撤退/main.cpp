#include <bits/stdc++.h>
using namespace std;
int n;
int a[25];
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<20;i++) scanf("%d",&a[i]);
        for(int i=19;i>0;i--)
        {
            int t=a[i];
            if(t&1) a[i]=1;
            else a[i]=0;
            a[i-1]+=(t/2);

        }
        for(int i=0;i<19;i++) printf("%d ",a[i]);
        printf("%d\n",a[19]);
    }
}
