#include <bits/stdc++.h>
using namespace std;
int a[5][5];
bool flag[4];
int main()
{
    while(~scanf("%d%d%d%d",&a[0][0],&a[0][1],&a[0][2],&a[0][3]))
    {
        memset(flag,0,4);
        for(int i = 1;i<4;i++)
            for(int j = 0;j<4;j++)
            scanf("%d",&a[i][j]);
        for(int i = 0;i<4;i++)
        {
            for(int j = 0;j<3;j++)
            {
                if(a[i][j])
                {
                    flag[i]=1;
                    if(j==0) flag[(i+3)%4]=1;
                    if(j==1) flag[(i+6)%4]=1;
                    if(j==2) flag[(i+5)%4]=1;
                }
            }
        }
        bool ans=true;
        for(int i = 0;i<4;i++)
            if(a[i][3]&&flag[i]) ans=false;
        if(ans) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
