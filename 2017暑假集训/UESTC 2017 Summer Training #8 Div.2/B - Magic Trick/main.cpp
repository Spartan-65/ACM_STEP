#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
double a[maxn];
char s[20];
bool vis[maxn];
bool check(double x)
{
    if(x<0) return true;
    if(floor(x)!=x) return true;
    return false;
}
int main()
{
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    int n;
    int ans=0;
    for(int i=0;i<=100;i++) a[i]=i;
    scanf("%d",&n);
    while(n--)
    {
        double t;
        scanf("%s%lf",s,&t);
        for(int i=1;i<=100;i++)
        {
            if(s[0]=='A') a[i]+=t;
            else if(s[0]=='S') a[i]-=t;
            else if(s[0]=='D') a[i]/=t;
            else
            {
                a[i]*=t;
            }
            if(check(a[i])&&!vis[i]) {ans++;vis[i]=1;}
        }
    }
    cout<<ans<<endl;
}