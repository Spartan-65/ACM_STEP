#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m;
int up;
struct node
{
    int next[2];
    void init()
    {
        memset(next,-1,sizeof(next));
    }
}L[maxn*32];
void add(int num)
{
    int now=0;
    for(int i=30;i>=0;i--){

        int t=0;
        if(num&(1<<i))t=1;
        int next=L[now].next[t];
        if(next==-1)
        {
            next=++up;
            L[next].init();
            L[now].next[t]=next;
        }
        now=next;
    }
}
int qurrey(int x)
{
    int res=0,now=0,next;
    for(int i=30;i>=0;i--)
    {
        int t=0;
        if(x&(1<<i)) t=1;
        if(L[now].next[!t]!=-1)
        {
            res|=(1<<i);
            now=L[now].next[!t];
        }
        else {
            now=L[now].next[t];
        }
    }
    return res;
}
void print(int x)
{
    int i=30;
    while(!(x&(1<<i)))i--;
    while(i>=0)
    {
        if(x&(1<<i))printf("1");
        else printf("0");
        i--;
    }
    printf("\n");
}
int main()
{
    while(~scanf("%d",&n))
    {
        up=0;L[0].init();
        for(int i=0;i<n;i++)
        {

            int t;scanf("%d",&t);add(t);
            //cout<<L[0].next[1]<<endl;
        }
        scanf("%d",&m);
        int t;
        while(m--)
        {
            scanf("%d",&t);
            //print(qurrey(t));
            printf("%d\n",qurrey(t));
        }
    }
    return 0;
}
