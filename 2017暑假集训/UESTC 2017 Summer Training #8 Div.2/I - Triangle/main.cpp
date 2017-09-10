#include <bits/stdc++.h>
using namespace std;
int a[3],b[3];
int main()
{
    while(~scanf("%d%d%d",&a[0],&a[1],&a[2]))
    {
        for(int i=0;i<3;i++) scanf("%d",&b[i]);
        sort(a,a+3);
        sort(b,b+3);
        bool flag=true;
        for(int i=0;i<3;i++) if(a[i]!=b[i]) flag=0;
        if(a[0]*a[0]+a[1]*a[1]!=a[2]*a[2]) flag=0;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
