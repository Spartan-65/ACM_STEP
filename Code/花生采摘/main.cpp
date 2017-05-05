#include <bits/stdc++.h>

using namespace std;

struct B
{
    int x,y,v;
};
bool cmp(B a,B b)
{ return a.v>b.v;}
int main()
{
    int m, n, s;
    int t;
    B a[250000];
    int p=0;
    cin>>m>>n>>s;
    for(int i = 1;i<=m;i++)
        for(int j = 1;j<=n;j++)
        {
            cin>>t;
            if(!t) continue;
            a[p].y=i;
            a[p].x=j;
            a[p].v=t;
            p++;
        }
    sort(a,a+p,cmp);

    int y=0,x=a[0].x,sum=0,time=0;
    for(int i = 0;i<p;i++)
    {
        t=abs(x-a[i].x)+abs(y-a[i].y)+1;
        if((time+t+a[i].y)>s) break;
        x=a[i].x,y=a[i].y;
        sum+=a[i].v;
        time+=t;
    }
    cout<<sum<<endl;
    return 0;
}
