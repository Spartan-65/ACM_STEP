#include <bits/stdc++.h>
using namespace std;
const int maxn=30;
char mp[maxn][maxn];
int n,m;
int  R[maxn],C[maxn];
void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<mp[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        int sum=0;
        memset(R,0,sizeof(R));
        memset(C,0,sizeof(C));
        for(int i=0;i<n;i++)
        {
            scanf("%s",mp[i]);
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]=='*')
                {
                    sum++;
                    R[i]++;
                    C[j]++;
                }
            }
        }
        int ans=0;
        while(sum>0)
        {
            print();
            int mr=0,mc=0,t1=0,t2=0;
            for(int i=0;i<maxn;i++)
            {
                if(mr<R[i])
                {
                    mr=R[i];
                    t1=i;
                }
            }
            for(int i=0;i<maxn;i++)
            {
                if(mc<C[i])
                {
                    mc=C[i];
                    t2=i;
                }
            }
            sum-=(mr+mc);
            if(mp[t1][t2]=='*') sum++;
            for(int i=0;i<m;i++) if(mp[t1][i]=='*'){C[i]-=1;R[t1]--;}
            for(int i=0;i<n;i++) if(mp[i][t2]=='*'){R[i]-=1;C[t2]--;}
            for(int i=0;i<m;i++) mp[t1][i]='.';
            for(int i=0;i<n;i++) mp[i][t2]='.';
            R[t1]=0;C[t2]=0;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
