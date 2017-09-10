#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {

        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        if(n<=1) {cout<<"0"<<endl;continue;}
        sort(a,a+m,cmp);
        int p=0;
        int ans=1;
        while(n>0&&p<m)
        {
            n-=a[p];
            if(n>0)ans++,p++,n++;
        }
        if(n>0)cout<<"Impossible"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
