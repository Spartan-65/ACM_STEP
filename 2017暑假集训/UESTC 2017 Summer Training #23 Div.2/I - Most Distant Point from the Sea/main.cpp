#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
double x[maxn],y[maxn];
int n;
struct line
{
    double a,b,c;
}lin[maxn];
int main()
{
    freopen("C.in","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            if(i>0)
            {
                double dy=y[i]-y[i-1],dx=x[i]-x[i-1];
                if(dy==0)
                {

                }
            }
        }

    }

    return 0;
}
