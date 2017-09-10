#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>, greater<int> > q;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            int t;scanf("%d",&t);
            q.push(t);
        }
        int ans=0;
        while(q.size()>1)
        {
            int sum=q.top();q.pop();
            sum+=q.top();q.pop();
            q.push(sum);
            ans+=sum;
        }
        cout<<ans<<endl;
    }
}
