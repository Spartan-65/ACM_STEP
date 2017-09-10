#include <bits/stdc++.h>
using namespace std;
struct node
{
    string a,b;
}s[105];
bool cmp(node a,node b)
{
    if(a.b!=b.b)
        return a.b<b.b;
    return a.a<b.a;
}
int main()
{

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i].a>>s[i].b;
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++)
        cout<<s[i].a<<' '<<s[i].b<<endl;
    return 0;
}
