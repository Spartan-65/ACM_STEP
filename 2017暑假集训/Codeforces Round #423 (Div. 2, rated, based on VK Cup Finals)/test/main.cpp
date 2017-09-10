#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int ans=0,c=0;
        for(int i=0;i<n;i++)
        {
            int t;
            bool flag=false;
            scanf("%d",&t);
            if(t==1)
            {
                if(a>0) a--;
                else if(b>0) c++,b--;
                else if(c) c--;
                else flag=true;
            }
            else
            {
                t=2;
                if(b>0) b--;
                else flag=true;
            }
            if(flag) ans+=t;
        }
        printf("%d\n",ans);
    }

    return 0;
}
