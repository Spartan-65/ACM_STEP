#include <bits/stdc++.h>
using namespace std;
int main()
{
    int D, n;
    int t;
    while(cin>>t)
    {
        if(t==-1) return 0;
        while(t--)
        {
            scanf("%d%d",&D, &n);
            int ans = 1;
            for(int i = 0;i<D-1;i++)
            {
                if(n&1){ ans *= 2, n = (n+1)/2; }
                else ans = ans*2+1, n /= 2;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
