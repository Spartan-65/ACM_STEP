#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+8;
int Set[maxn<<1];
void init()
{
    for(int i=0;i<maxn<<1;i++)
        Set[i]=i;
}
int Find(int x)
{
    if(Set[x]==x) return x;
    return Find(Set[x]);
}
void meg(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx!=fy)
    {
        Set[fx]=fy;
    }
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=0;i<m;i++)
        {
            int x,a,b;scanf("%d%d%d",&x,&a,&b);
            if(x)
                meg(a,b),meg(a+maxn,b+maxn);
            else meg(a,b+maxn),meg(a+maxn,b);
        }
        bool flag=1;
        for(int i=1;i<=n;i++)
        {
            if(Find(i)==Find(i+maxn))
            {
                flag=0;break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
