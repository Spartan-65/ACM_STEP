#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+8;
int Set[maxn<<1];
void init()
{
    for(int i=0;i<maxn<<1;i++)
    {
        Set[i]=i;
    }
}
void meg(int op,int x,int y)
{

}
void Find(int x)
{
    if(Set[x]==x) return x;
    return Find(Set[x]);
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        init();
    }
    return 0;
}
