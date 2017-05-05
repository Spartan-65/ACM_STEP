#include <bits/stdc++.h>
using namespace std;
struct milk
{
    int s,v;
};
bool cmp(milk a, milk b)
{return a.s<b.s;}
int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        milk a[m];
        for(int i = 0;i<m;i++)
            cin>>a[i].s>>a[i].v;
        sort(a,a+m,cmp);
        int sum = 0, p=0;
        while(n>0)
        {
            if(n>a[p].v) {
                n-=a[p].v;
                sum+=(a[p].v*a[p].s);
            }
            else
            {
                sum+=n*a[p].s;
                n=0;
            }
            p++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
