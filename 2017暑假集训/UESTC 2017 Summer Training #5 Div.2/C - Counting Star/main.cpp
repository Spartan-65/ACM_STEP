#include <bits/stdc++.h>
using namespace std;
const int maxn=305;
int a[maxn][maxn];int r,c;
int f(int x,int y,int i,int j){
    if(x>i||y>j) return 0;
    return a[i][j]-a[x-1][j]-a[i][y-1]+a[x-1][y-1];
}
int main()
{
    int T;scanf("%d",&T);
    int sum=0;
    while(T--)
    {
        scanf("%d%d",&r,&c);
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                int t;
                scanf("%d",&t);
                a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+t;
            }
        }
        int ans=0;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                for(int k=1;k+i<=r&&k+j<=c;k++){
                    int ti=i+k,tj=j+k;
                    if(f(i,j,ti,tj)-f(i+1,j+1,ti-1,tj-1)==4*k){
                        int x=f(i+1,j+1,ti-1,tj-1);
                        int y=(k-1)*(k-1)-x;
                        if(abs(x-y)<=1) ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
