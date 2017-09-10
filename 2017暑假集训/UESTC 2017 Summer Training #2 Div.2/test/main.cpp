#include <bits/stdc++.h>
using namespace std;
const int maxn=15;
int a[maxn];
int main()
{
    int T;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            int n,sum=0;
            for(int i=0;i<n;i++)
            {
                int t; scanf("%d",&t);
                sum+=t;
            }

            sort(a,a+n);
        }
    }
    return 0;
}
