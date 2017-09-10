#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int t=1;
        int ans=0;
        while(n)
        {
            if(n&1)ans++;
            n>>=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
