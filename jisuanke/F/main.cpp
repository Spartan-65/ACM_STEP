#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+2;
int n,t;
int a[maxn];
int main()
{
    while(~scanf("%d%d",&n,&t))
    {
        for(int i = 0;i<n;i++)
            scanf("%d",&a[i]);
        queue<int> q;
        int sumt=0;
        int Max=0;
        for(int i = 0;i<n;i++)
        {
            sumt+=a[i];
            q.push(a[i]);
            while(sumt>t) {sumt-=q.front();q.pop();}
            int x=q.size();
            Max=max(x,Max);
        }
        printf("%d\n",Max);
    }
    return 0;
}
