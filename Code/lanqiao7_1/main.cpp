#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[105]={1},t=2;
    for(int i = 1;i<100;i++)
        a[i]=a[i-1]+t,t++;
    cout<<a[2]<<' '<<a[99]<<endl;


}
