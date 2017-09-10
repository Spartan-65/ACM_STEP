#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
int num[maxn][260]={0};
int main()
{
    memset(num,0,sizeof(num));
    num[0][0]=num[1][0]=num[2][0]=num[3][0]=num[4][0]=1;
    for(int i=5;i<maxn;i++)
    {
        for(int j=0;j<260;j++)
        {
            num[i][j]=num[i-1][j]+num[i-2][j]+num[i-3][j]+num[i-4][j];
        }
        for(int j=0;j<260;j++)
        {
            if(num[i][j]>100000000)
            {
                num[i][j+1]+=num[i][j]/100000000;
                num[i][j]%=100000000;
            }
        }
    }
    int n;
    while(~scanf("%d",&n))
    {
        int j=259;
        while(num[n][j]==0) j--;
        printf("%d",num[n][j]);j--;
        while(j>=0) printf("%08d",num[n][j]),j--;
        printf("\n");
    }
    return 0;
}
