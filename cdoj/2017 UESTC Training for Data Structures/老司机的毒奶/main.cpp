#include <bits/stdc++.h>
using namespace std;
const int maxn=50000;
map<int,bool> mp;
priority_queue<int> q;
int n;
int main()
{
    while(~scanf("%d",&n))
    {
        while(!q.empty()) q.pop();
        mp.clear();
        for(int i=0;i<n;i++)
        {
            int t;scanf("%d",&t);
            mp[t]=true;
            q.push(t);
        }
        //while(!q.empty()){cout<<q.top()<<endl;q.pop();}
        while(!q.empty())
        {
            //cout<<q.top()<<endl;
            int t=q.top();
            mp[t]=0;
            while(t)
            {
                t>>=1;
                if(t&&!mp[t])
               {
                   q.pop();
                   mp[t]=1;
                   q.push(t);
                   break;
               }
            }
            if(t==0)break;
        }
        printf("%d\n",q.top());
    }
}
