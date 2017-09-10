#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=min(n,m);i<=max(n,m);i++)printf("%d\n",i+1);
    }
    return 0;
}
