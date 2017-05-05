#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int a[n+1],sum=0;
        for(int i = 1;i<=n;i++) cin>>a[i],sum+=a[i];
        int p=sum/n;
        int p1=1,p2=n;
        sum=0;
        while(p1<=p2)
        {
            if(a[p1]!=p){
                int t=a[p1]-p;
                a[p1]=p;
                a[p1+1]+=t;
                sum++;
            }
            if(a[p2]!=p){
                int t=a[p2]-p;
                a[p2]=p;
                a[p2-1]+=t;
                sum++;
            }
            p1++;p2--;
        }
        cout<<sum<<endl;
    }
    return 0;
}
