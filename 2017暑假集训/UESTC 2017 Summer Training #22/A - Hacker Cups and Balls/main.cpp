#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int n,m,a[maxn];
bool cmp(int a,int b){return a>b;}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x<y) sort(a+x-1,a+y);
            else sort(a+y-1,a+x,cmp);
        }
        printf("%d\n",a[n/2]);
    }
    return 0;
}
