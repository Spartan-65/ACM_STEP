#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        if((a[0]&1)&&(a[n-1]&1)&&(n&1)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
