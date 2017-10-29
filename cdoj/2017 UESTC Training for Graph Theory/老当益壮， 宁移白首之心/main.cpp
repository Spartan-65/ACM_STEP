 #include <bits/stdc++.h>
 using namespace std;
 const int maxn=(1<<14)+8;
 const int maxm=(1<<15)+8;
 int n;
 typedef pair<int,int> ii;
 vector<ii> E[maxn];
 vector<int> path;
 bool vis[maxm];
 void dfs(int u)
 {
     while(!E[u].empty())
     {
         int v=E[u].back().first, e=E[u].back().second;

         E[u].pop_back();
         if(!vis[e])
         {
             vis[e]=1;
             dfs(v);
             path.push_back(e);
             cout<<u<<"->"<<v<<endl;
         }
     }
 }
 int main()
 {

     scanf("%d",&n);
     for(int i=0;i<(1<<n);i++)
     {
         int u=i>>1,v=i%(1<<(n-1));
         E[u].push_back(ii(v,i));
         cout<<i<<' '<<u<<' '<<v<<endl;
     }
     memset(vis,0,sizeof(vis));
     dfs(0);
     for(int i=0;i<(1<<n);i++){
            printf("%d",path[i]&1);
     }
     cout<<endl;
     return 0;
 }
