#include <bits/stdc++.h>
using namespace std;
int main()
{
    int P;scanf("%d",&P);
    while(P--)
    {
        int id,n;

        scanf("%d%d",&id,&n);int ans=n;
        while(n!=1)
        {
            if(n&1)
            {
                n=n*3+1;
            }
            else
            {
                n/=2;
            }
            ans=max(ans,n);
        }
        printf("%d %d\n",id,ans);
    }
    return 0;
}
