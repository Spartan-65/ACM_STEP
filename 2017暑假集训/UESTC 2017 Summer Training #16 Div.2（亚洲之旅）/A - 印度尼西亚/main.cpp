#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int ans=0;
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int t;
            scanf("%d",&t);
            while(t&1) t>>=1;
            t>>=1;
            ans^=t;
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
