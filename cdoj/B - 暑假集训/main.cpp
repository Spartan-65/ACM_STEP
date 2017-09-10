#include <bits/stdc++.h>
using namespace std;
const int maxn=25;
int dp[maxn][maxn][maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int t=(n*(n-1)*(n-2)/6);
        for(int i=0;i<t;i++)
        {
            int x,y,z,v;
            scanf("%d%d%d%d",&x,&y,&z,&v);
            dp[x][y][z]=v;
        }
        //cout<<"mark"<<endl;

    }
    return 0;
}
