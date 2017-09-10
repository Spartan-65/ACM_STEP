#include <bits/stdc++.h>
using namespace std;
const int maxn=7550;
int a[maxn],flag[maxn];
priority_queue<int,vector<int>,greater<int> > ans[maxn];
int main()
{
    string s;
    memset(flag,0,sizeof(flag));
    while(getline(cin,s))
    {
        int t,p=0,m=0;
        stringstream ss(s);
        while(ss>>t){
            a[p++]=t;
            flag[t]++;
            m=max(m,t);
        }
        priority_queue<int,vector<int>,greater<int> > q;
        for(int i=1;i<=m;i++)
            if(!flag[i]) q.push(i);
        for(int i=0;i<p;i++)
        {
            int u=q.top();q.pop();
            int v=a[i];
            ans[u].push(v);ans[v].push(u);
            flag[v]--;
            if(!flag[v]) q.push(v);
        }
        for(int i=1;i<=m;i++){
            printf("%d:",i);
            while(!ans[i].empty()){
                printf(" %d",ans[i].top());
                ans[i].pop();
            }
            cout<<endl;
        }
    }
}
