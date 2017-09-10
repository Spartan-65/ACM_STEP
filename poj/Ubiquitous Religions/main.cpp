#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int maxn=50005;
int n,m;
set<int> ans;
int Set[maxn];
void init(){for(int i=1;i<=n;i++)Set[i]=i;}
int Find(int x)
{
    if(x==Set[x]) return x;
    return Find(Find(Set[x]));
}
int main()
{
    int ca=0;
    while(~scanf("%d%d",&n,&m)&&n)
    {
        ans.clear();
        printf("Case %d: ",++ca);
        init();
        for(int i=0;i<m;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            a=Find(a);b=Find(b);
            if(a!=b) Set[a]=b;
        }
        for(int i=1;i<=n;i++) ans.insert(Find(i));
        cout<<ans.size()<<endl;
    }
    return 0;
}
