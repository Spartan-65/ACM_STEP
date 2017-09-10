#include <bits/stdc++.h>
using namespace std;
const int maxn=50005;

struct node{
    int pre;
    int re;
}p[maxn];
int Find(int x)
{
    if(x==p[x].pre) return x;
    int temp=p[x].pre;
    p[x].pre=Find(temp);
    p[x].re=(p[x].re+p[temp].re)%3;
    return p[x].pre;
}
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("my.out","w",stdout);
    int n,m;
    while(cin>>n>>m)
    {
        queue<int>ans;
        for(int i=1;i<=n;i++)
        {
            p[i].pre=i;
            p[i].re=0;
        }
        for(int i=1;i<=m;i++)
        {
            int x,a,b;scanf("%d%d%d",&x,&a,&b);
            if(a>n||b>n) ans.push(i);
            else if(x==2&&a==b) ans.push(i);
            else
            {
                int fa=Find(a),fb=Find(b);
                if(fa!=fb)
                {
                    p[fb].pre=fa;
                    p[fb].re=(p[a].re+(x-1)+3-p[b].re)%3;
                }
                else
                {
                    if(x==1&&p[b].re!=p[a].re) ans.push(i);
                    if(x==2&&((3 - p[a].re + p[b].re)%3 != x -1)) ans.push(i);
                }
            }
        }
        if(ans.empty())continue;
        printf("%d",ans.front());ans.pop();
        while(!ans.empty())
        {
            printf(" %d",ans.front());ans.pop();
        }
    }

    return 0;
}
