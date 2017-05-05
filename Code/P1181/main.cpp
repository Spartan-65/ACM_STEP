#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int t=0,ans=0;
        for(int i = 0;i<n;i++)
        {
            int a;cin>>a;
            t+=a;
            if(t>m){
                t=a;
                ans++;
            }
        }
        if(t) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
