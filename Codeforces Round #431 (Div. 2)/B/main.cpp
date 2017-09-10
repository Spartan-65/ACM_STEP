#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int y[maxn];
int n;
bool line(int a,int b,int c)
{
    return (y[b]-y[a])*1ll*(c-b)==(y[c]-y[b])*1ll*(b-a);
}
bool check(int a,int b)
{
    vector<int> q;
    for(int i=0;i<n;i++)
    {
        if(i==a||i==b) continue;
        if(!(line(a,b,i)))q.push_back(i);
    }
    if(q.empty()) return false;
    if(q.size()==1) return true;
    if((y[b]-y[a])*1ll*(q[1]-q[0])!=(y[q[1]]-y[q[0]])*1ll*(b-a)) return false;
    for(int i=2;i<q.size();i++)
    {
        if(!(line(q[0],q[1],q[i])))return false;
    }
    return true;
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++) scanf("%d",&y[i]);
        bool flag=check(1,2);
        for(int i=1;i<n;i++)
        {
            if(flag) break;
            flag=check(0,i);
        }
        printf(flag?"Yes":"No");
        puts("");
    }
}
