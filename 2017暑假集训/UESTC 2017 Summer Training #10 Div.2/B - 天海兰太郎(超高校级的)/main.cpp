#include <bits/stdc++.h>
using namespace std;
int a[20][20],b[20][20];
void print()
{
    for(int i=0;i<4;i++)
    {
        printf("%d",b[i][0]);
        for(int j=1;j<4;j++) printf(" %d",b[i][j]);
        cout<<endl;
    }

}
void work(int x)
{
    if(x==0)
    {
        for(int i=0;i<4;i++)
        {
            int C=0,t=0;
            for(int j=0;j<4;j++)
            {
                if(a[i][j]) b[i][C++]=a[i][j];
            }
        }
    }
    else if(x==1)
    {
        for(int j=0;j<4;j++)
        {
            int C=0;
            for(int i=0;i<4;i++)
            {
                if(a[i][j]) b[C++][j] =a[i][j];
            }
        }
    }
    else if(x==2)
    {
        for(int i=3;i>=0;i--)
        {
            int C=3;
            for(int j=3;j>=0;j--)
            {
                if(a[i][j]) b[i][C--]=a[i][j];
            }
        }
    }
    else
    {
        for(int j=3;j>=0;j--)
        {
            int C=3;
            for(int i=3;i>=0;i--)
                if(a[i][j]) b[C--][j]=a[i][j];
        }
    }
}
int main()
{    memset(b,0,sizeof(b));
    int x;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++) scanf("%d",&a[i][j]);
    scanf("%d",&x);
    work(x);
    memset(a,0,sizeof(a));
    if(x==0)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(b[i][j]==b[i][j+1])a[i][j]=2*b[i][j],b[i][j+1]=0;
                else a[i][j]=b[i][j];
            }
            a[i][3]=b[i][3];
        }
    }
    else if(x==1)
    {
        for(int j=0;j<4;j++)
        {
            for(int i=0;i<3;i++)
                if(b[i][j]==b[i+1][j]) a[i][j]=2*b[i][j],b[i+1][j]=0;
                else a[i][j]=b[i][j];
            a[3][j]=b[3][j];
        }
    }
    else if(x==2)
    {
        for(int i=3;i>=0;i--)
        {
            for(int j=3;j>0;j--)
                if(b[i][j]==b[i][j-1]) a[i][j]=2*b[i][j],b[i][j-1]=0;
                else a[i][j]=b[i][j];
            a[i][0]=b[i][0];
        }
    }
    else{
        for(int j=3;j>=0;j--)
        {
            for(int i=3;i>0;i--)
            {
                if(b[i][j]==b[i-1][j]) a[i][j]=2*b[i][j],b[i-1][j]=0;
                else a[i][j]=b[i][j];
                a[0][j]=b[0][j];
            }
        }

    }
    memset(b,0,sizeof(b));
    work(x);
    print();
    return 0;
}
