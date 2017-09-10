#include <bits/stdc++.h>

using namespace std;

struct node
{
    int n;
    node *next;
};
int main()
{
    int a[100];
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int p=0,ans=0,c=0;
        for(int i = 0;i<n;i++)a[i]=i+1;
        while(ans<n)
        {
            p++;
            if(a[p-1]) c++;
            if(c==m&&a[p-1]!=0)
            {
                printf("%d ",a[p-1]);
                a[p-1]=0;
                ans++;
                c=0;
            }
            p%=n;
        }
        printf("\n");
    }
    return 0;
}
