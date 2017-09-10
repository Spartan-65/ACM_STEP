#include <bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n;
int x[maxn],y[maxn],xx[maxn],yy[maxn];
int main()
{
    freopen("lshape.in","r",stdin);
    freopen("lshape.out","w",stdout);
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&x[i],&y[i],&xx[i],&yy[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((x[i]==x[j]&&y[i]==y[j])||(x[i]==xx[j]&&y[i]==yy[j])||(xx[i]==x[j]&&yy[i]==y[j])||(xx[i]==xx[j]&&yy[i]==yy[j]))
                    if((x[i]-xx[i])*(x[j]-xx[j])+(y[i]-yy[i])*(y[j]-yy[j])==0) ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
