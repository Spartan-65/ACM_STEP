#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int ans[maxn],n,c[maxn];
struct node{
    int x,y;
}P[maxn];
bool cmp(node a,node b)
{
    if(a.y!=b.y)
    return a.y<b.y;
    return a.x<b.x;
}
int lowbit(int x)
{
    return x&-x;
}
void add(int pos)
{
    while(pos<=maxn)
    {
        //cout<<pos<<endl;system("pause");
        ans[pos]++;
        pos+=lowbit(pos);

    }
}
int get(int pos)
{
    int res=0,i=pos;
    while(i>0)
    {
        res+=ans[i];
        i-=lowbit(i);
    }
    return res;
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&P[i].x,&P[i].y);
        }
        memset(c,0,sizeof(c));
        memset(ans,0,sizeof(ans));
        sort(P,P+n,cmp);
        for(int i=0;i<n;i++)
        {
            c[get(P[i].x)]++;
            add(P[i].x);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            printf("%d\n",c[i]);
        }
    }
    return 0;
}
