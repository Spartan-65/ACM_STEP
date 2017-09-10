#include <bits/stdc++.h>
using namespace std;
const int maxn=355;
char a[maxn];
int n;
bool vis[maxn];
int work(int p)
{
    memset(vis,0,maxn);
    int t,num=1;
    char ch=a[p];
    vis[p]=1;
    for(int i = 1;i<n;i++)
    {
        t=(i+p)%n;
        if(vis[t]) break;
        if(a[t]=='w')
        {
            num++;
            vis[t]=1;
        }
        else if(a[t]!=ch&&ch=='w')
        {
            ch=a[t];
            num++;
            vis[t]=1;
        }
        else if(ch==a[t]) num++,vis[t]=1;
        else
        {
            break;
        }
    }
    t=(p-1+n)%n;
    if(vis[t]) return num;
    else vis[t]=1,num++;
    ch=a[t];
    for(int i = 2;i<n;i++)
    {
        t=(p-i+n)%n;
        if(vis[t]) break;
        if(a[t]=='w')
        {
            num++;
            vis[t]=1;
        }
        else if(a[t]!=ch&&ch=='w')
        {
            ch=a[t];
            num++;
            vis[t]=1;
        }
        else if(ch==a[t]) num++,vis[t]=1;
        else
        {
            break;
        }
    }
    return num;
}
int main()
{
    while(~scanf("%d",&n))
    {
        scanf("%s",&a);
        int M=0;
        for(int i = 0;i<n;i++)
        {
            int t=work(i);
            M=max(t,M);
        }
        cout<<M<<endl;
    }
    return 0;
}
