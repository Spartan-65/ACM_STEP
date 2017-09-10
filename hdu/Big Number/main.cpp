#include <bits/stdc++.h>
using namespace std;
int main()
{
    double sum;
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum=0;
        for(int i=1;i<=n;i++)
            sum+=log10(i);
        printf("%d\n",(int)sum+1);
    }
    return 0;
}
