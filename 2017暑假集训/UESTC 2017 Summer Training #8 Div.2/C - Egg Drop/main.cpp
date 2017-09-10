#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n,f;
    while(~scanf("%d%d",&n,&f))
    {
        memset(a,0,sizeof(a));
        int ans1=1,ans2=f;
        a[1]=1,a[f]=2;
        for(int i=0;i<n;i++)
        {
            int t;
            char s[20];
            scanf("%d%s",&t,s);
            if(s[0]=='S') a[t]=1;
            else a[t]=2;
        }
        int i=1;
        while(1)
        {
            if(a[i]==2){ans2=i-1;break;}
            i++;
        }
        i=f;
        while(1)
        {
            if(a[i]==1) {ans1=i+1;break;}
            i--;
        }
        cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}
