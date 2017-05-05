#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int m, n;
    int mat[205][205][2];
    while(~scanf("%d%d",&m,&n))
    {
        memset(mat,0,sizeof(mat));
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                scanf("%d",&mat[i][j][0]),mat[i][j][1]=1;
        printf("%d",mat[0][0][0]);
        mat[0][0][1]=0;
        int i=1,j=0,C=m*n-1;
        while(C)
        {
            while(1)
            {
                if(mat[i][j][1]) {printf(" %d",mat[i][j][0]); mat[i][j][1]=0;i++;C--; }
                else {i--,j++;break;}
            }
            while(1)
            {
                if(mat[i][j][1]) {printf(" %d",mat[i][j][0]); mat[i][j][1]=0;j++;C--; }
                else {j--,i--;break;}
            }
            while(1){if(mat[i][j][1]) {printf(" %d",mat[i][j][0]); mat[i][j][1]=0;i--;C--; }else {i++,j--;break;}}
            while(1){if(mat[i][j][1]) {printf(" %d",mat[i][j][0]); mat[i][j][1]=0;j--;C--; }else {j++,i++;break;}}
        }
        printf("\n");
    }
    return 0;
}
