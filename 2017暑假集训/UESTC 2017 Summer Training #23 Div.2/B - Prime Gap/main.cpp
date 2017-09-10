#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int num[maxn];
int n,k;
bool flag[15000000];
void init()
{
    int p=0;
    memset(flag,0,sizeof(flag));
    for(int i=2;i<1500000;i++)
    {
        if(!flag[i])
        {
            num[p++]=i;if(p>=100000)break;
            for(int j=i*2;j<15000000;j+=i)
                flag[j]=1;
        }
        if(p>=100000)break;
    }
}
int main()
{

    init();
    freopen("B.in","r",stdin);
    while(~scanf("%d",&n)&&n)
    {
        bool flag=1;
        int p1=0,p2;
        for(int i=0;i<maxn;i++)
        {
            if(num[i]==n){flag=0;break;}
            else if(num[i]<n){
                p1=num[i];
            }
            else {
                p2=num[i];
                break;
            }
        }
        if(flag) printf("%d\n",p2-p1);
        else printf("0\n");
    }
    return 0;
}
