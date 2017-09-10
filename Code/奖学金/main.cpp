#include <bits/stdc++.h>
using namespace std;
struct p
{
    int num,a,b,c,sum;
};


bool cmp(p a, p b)
{
    if(a.sum!=b.sum) return a.sum>b.sum;
    else if(a.a!=b.a) return a.a>b.a;
    else return a.num<b.num;

}
int main()
{
    int n;
    cin>>n;
    p a[n];
    for(int i = 0;i<n;i++)
    {
        a[i].num=i+1;
        cin>>a[i].a>>a[i].b>>a[i].c;
        a[i].sum=a[i].a+a[i].b+a[i].c;
    }
    sort(a,a+n,cmp);
    for(int i = 0;i<5;i++)
        cout<<a[i].num<<' '<<a[i].sum<<endl;

}
