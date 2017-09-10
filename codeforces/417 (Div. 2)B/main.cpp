#include <bits/stdc++.h>
using namespace std;
char a[20][105];
int n,m;
int Count=0;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = n-1;i>=0;i--)
            scanf("%s",&a[i]);
        Count=0;
        for(int i = 0;i<n;i++)
        {
            printf("%s\n",a[i]);
            for(int j = 0;j<m+2;j++)
                if(a[i][j]=='1')Count++;
        }


    }

    return 0;
}
