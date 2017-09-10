#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(k&1)
        {
            if(n&1) cout<<'1'<<endl;
            else cout<<'0'<<endl;
        }
        else
        {
            n=n%(k+1);
            if(n==k) cout<<n<<endl;
            else {
                if(n&1) cout<<'1'<<endl;
                else cout<<'0'<<endl;
            }
        }
    }
    return 0;
}
