#include <bits/stdc++.h>
using namespace std;
long long ans[100];
int n,q;
long long temp[15][15][15];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(ans,0,sizeof(ans));
        memset(temp,0,sizeof(temp));
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            temp[x][y][z]++;
        }
        for(int i=0;i<=10;i++)
        {
            for(int j=0;j<=10;j++)
            {
                for(int k=0;k<=10;k++)
                {
                    long long t=(long long)temp[i][j][k];
                    if(t==0) continue;
                    ans[0]+=(long long)(t*(t-1)>>1);
                    for(int t1=i;t1<=10;t1++)
                        for(int t2=j;t2<=10;t2++)
                            for(int t3=k;t3<=10;t3++)
                            {
                                if(!temp[t1][t2][t3]) continue;
                                int  tt=abs(t1-i)+abs(t2-j)+abs(t3-k);
                                if(tt==0) continue;
                                //cout<<i<<' '<<j<<' '<<k<<' '<<t1<<' '<<t2<<' '<<t3<<endl;
                                ans[tt]+=(long long)(temp[t1][t2][t3]*t);
                            }
                }
            }
        }
        for(int i=1;i<=100;i++)
        {
            ans[i]+=ans[i-1];
            //cout<<ans[i]<<endl;
        }
        for(int i=0;i<q;i++) {
                scanf("%d",&n);
                if(n>90) printf("%lld",ans[90]);
                else
                printf("%lld\n",ans[n]);
        }
    }

    return 0;
}
