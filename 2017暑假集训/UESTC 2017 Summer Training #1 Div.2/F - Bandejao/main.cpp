#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        n+=1;
        if(n%k==0) {printf("yes\n");continue;}
        printf("no\n");
    }
    return 0;
}
