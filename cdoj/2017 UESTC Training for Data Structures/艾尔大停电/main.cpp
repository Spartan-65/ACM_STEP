#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=200+5;
struct node{
    double x1,y1,x2,y2;
}nodes[maxn];
double x[maxn],y[maxn];
bool mp[maxn][maxn];
int num1,num2;
int n;
int Find(double *arr,double val,int len)
{
    int l=0,r=len-1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(arr[mid]==val) return mid;
        else if(arr[mid]<val)l=mid+1;
        else r=mid-1;
    }
    //return -1;
}
int main()
{
    int cas=0;
    while(~scanf("%d",&n),n)
    {
        num1=0,num2=0;
        memset(mp,0,sizeof(mp));
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&nodes[i].x1,&nodes[i].y1,&nodes[i].x2,&nodes[i].y2);
            x[num1++]=nodes[i].x1;
            x[num1++]=nodes[i].x2;
            y[num2++]=nodes[i].y1;
            y[num2++]=nodes[i].y2;
        }
        sort(x,x+num1);
        sort(y,y+num2);
        num1=unique(x,x+num1)-x;
        num2=unique(y,y+num2)-y;
        for(int i=0;i<n;i++)
        {
            int si=Find(x,nodes[i].x1,num1);
            int mi=Find(x,nodes[i].x2,num1);
            int j=Find(y,nodes[i].y1,num2);
            int mj=Find(y,nodes[i].y2,num2);
            //cout<<si<<' '<<mi<<' '<<j<<' '<<mj<<endl;
            for(;si<mi;si++)
                for(int tj=j;tj<mj;tj++)
                    mp[si][tj]=1;
        }
        double ans=0;
        for(int i=0;i<num1;i++)
            for(int j=0;j<num2;j++)
                if(mp[i][j])
                    ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);//,cout<<i<<' '<<j<<endl;
        printf("%.2lf\n",ans);
    }
}
