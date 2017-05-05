#include <bits/stdc++.h>
using namespace std;
struct P
{
    int x,w;
};
bool cmp1(P a, P b)
{
    if(a.w!=b.w) return a.w>b.w;
    else return a.x<b.x;

}

int main()
{
    int n;
    int k;
    cin>>n>>k;
    int E[10];
    P a[n];
    for(int i = 0;i<10;i++) cin>>E[i];
    for(int i = 0;i<n;i++)
    {
        int t;
        cin>>t;
        a[i].x=i;
        a[i].w=t;
    }
    sort(a,a+n,cmp1);
    for(int i = 0;i<n;i++)
    {
        a[i].w+=E[i%10];
    }
    sort(a,a+n,cmp1);
    for(int i = 0;i<k;i++)
    {
        cout<<a[i].x+1<<' ';
    }
    cout<<endl;
}
