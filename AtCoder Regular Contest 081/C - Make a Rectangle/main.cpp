#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
priority_queue<long long> q;
map<long long,int> ans;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {

            long long t;scanf("%lld",&t);
            q.push(t);
        }
        long long a=0,b=0,t;
        t=q.top();q.pop();
        while(q.size()>0)
        {
            long long x=q.top();q.pop();
            if(x==t)
            {
                if(!a)a=t;
                else b=t;
                t=0;
            }
            else t=x;
            if(a&&b)break;
        }
        printf("%lld\n",a*b);
    }
}
