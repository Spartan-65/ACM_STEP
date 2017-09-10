#include <bits/stdc++.h>
using namespace std;
long long m,n,t;
bool work()
{
    long long x=1;
    if(t==1)
    {
        for(int i=2;i<=n;i++){
            x*=i;
            if(x>m) return 1;
        }
    }
    else if(t==2)
    {
        for(int i=0;i<n;i++){
            x*=2;
            if(x>m)return 1;
        }
    }
    else if(t==3)
    {
        for(int i=0;i<4;i++){
            x*=n;
            if(x>m)return 1;
        }
    }
    else if(t==4)
    {
        for(int i=0;i<3;i++){
            x*=n;
            if(x>m) return 1;
        }
    }
    else if(t==5)
    {
        x=n*n;
        if(x>m) return 1;
    }
    else if(t==6)
    {
        if(n*log2(n)>m)return 1;
    }
    else
    {
        if(n>m) return 1;
    }
    return 0;
}
int main()
{
    cin>>m>>n>>t;

    if(work()) cout<<"TLE"<<endl;
    else cout<<"AC"<<endl;
    return 0;
}
