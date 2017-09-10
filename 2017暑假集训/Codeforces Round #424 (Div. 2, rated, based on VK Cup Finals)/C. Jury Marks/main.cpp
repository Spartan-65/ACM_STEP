#include <bits/stdc++.h>
using namespace std;
const int maxn=2005;
int sum[maxn],b[maxn];
map<int,int> ans;
vector<int> v;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    sum[0]=1;
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        sum[i]=sum[i-1]+t;
    }
    for(int i=0;i<k;i++)scanf("%d",&b[i]);
    sort(sum+1,sum+n+1);
    int len=unique(sum+1,sum+n+1)-(sum+1);
    for(int i=1;i<=len;i++){
        for(int j=0;j<k;j++){
            v.push_back(b[j]-sum[i]);
        }
    }
    int x=0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        if(!ans.count(v[i])) ans[v[i]]=0;
        ans[v[i]]++;
    }
    for(map<int,int>::iterator i=ans.begin();i!=ans.end();i++)
        if(i->second >= k)x++;
    cout<<x<<endl;
    return 0;
}
