#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
    return a+b<b+a;
}
int main()
{
    int n;
    cin>>n;
    string a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    sort(a,a+n,cmp);
    for(int i = n-1;i>=0;i--)
        cout<<a[i];
    cout<<endl;
    return 0;
}
