#include <bits/stdc++.h>
using namespace std;
int Map[15],n,Count=0;
int b[100]={0},c[100]={0},d[100]={0};
void Put(int x)
{
    if(x==n){
        Count++;
        if(Count<=3) {for(int i = 0;i<n;i++) cout<<Map[i]+1<<' ';cout<<endl;}
        return ;
    }
    for(int i = 0;i<n;i++)
    {
        if(!b[i]&&!c[i+x]&&!d[i-x+15])
        {
            Map[x]=i;
            b[i]=1;
            c[i+x]=1;
            d[i-x+15]=1;
            Put(x+1);
            b[i]=0;
            c[i+x]=0;
            d[i-x+15]=0;
        }
    }
}

int main()
{
    cin>>n;
    Put(0);
    cout<<Count<<endl;
    return 0;
}
