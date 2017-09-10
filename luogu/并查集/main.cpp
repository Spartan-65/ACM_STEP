#include <bits/stdc++.h>
using namespace std;
int n,m;
int p[10000];
void init()
{
    for(int i = 0;i<=n;i++) p[i]=i;
}
int findp(int x)
{
    if(x==p[x]) return x;
    return p[x]=findp(p[x]);
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        int z,x,y;
        for(int i = 0;i<m;i++)
        {
            scanf("%d%d%d",&z,&x,&y);

            if(z==1)
            {
                int xx=findp(x);
                int yy=findp(y);
                p[xx]=yy;
            }
            else
            {

                int xx=findp(x);
                int yy=findp(y);
                if(xx==yy) printf("Y\n");
                else printf("N\n");
            }
        }
    }
    return 0;
}
