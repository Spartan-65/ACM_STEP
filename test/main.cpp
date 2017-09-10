#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
struct node
{
    int pre;
    int relation;
} p[maxn];

int find(int x)
{
    int temp;
    if(x == p[x].pre)
        return x;
    temp = p[x].pre;
    p[x].pre = find(temp);
    p[x].relation = (p[x].relation + p[temp].relation)%3;
    return p[x].pre;
}

int main()
{
    freopen("test.in","r",stdin);
    freopen("ac.out","w",stdout);
    int n,m;
    while(cin>>n>>m)
    {
        queue <int> qu;
        for(int i=1; i<=n; i++)
        {
            p[i].pre = i;
            p[i].relation = 0;
        }
        for(int i=1; i<=m; i++)
        {
            int a,b,c;
            cin>>c>>a>>b;
            if(a == b && c == 2)
            {
                qu.push(i);
                continue;
            }
            if(a > n || b > n)
            {
                qu.push(i);
                continue;
            }
            int fa = find(a);
            int fb = find(b);
            if(fa != fb)
            {
                p[fb].pre = fa;
                p[fb].relation = (3 + (c - 1) + p[a].relation - p[b].relation)%3;//很重要的合并公式
                //rootx->rooty = (relation[x]+d-1+3-relation[y])%3 = relation[rooty](公式)
            }
            else
            {
                if(c == 1 && p[a].relation != p[b].relation)//同类但是和父类的关系不同是不可能的
                    qu.push(i);
                if(c == 2 && ((3 - p[a].relation + p[b].relation)%3 != c -1))//检验是否是符合捕食关系
                    qu.push(i);
            }
        }
        if(qu.empty())
            continue;
        printf("%d",qu.front());
        qu.pop();
        while(!qu.empty())
        {
            printf(" %d",qu.front());
            qu.pop();
        }
        cout<<endl;
    }
    return 0;
}
