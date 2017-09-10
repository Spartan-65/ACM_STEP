#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    int T;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d%d",&m,&n);
            if(m*n%6) cout<<"No"<<endl;
            else if(m<2||n<2) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}
