#include <bits/stdc++.h>
using namespace std;
struct num
{
    int v;
    num *next;
};
void init()
{
    //
}
int main()
{
    int n;
    cin>>n;
    priority_queue< int,vector<int>,greater<int> > a;
    int t;
    for(int i = 0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        a.push(t);
    }

    int sum = 0;
    for(int i = 0;i<n-1;i++)
    {
        int x=a.top();
        a.pop();
        int y = a.top();
        a.pop();
        int t = x+y;
        a.push(t);
        sum+=t;
    }
    cout<<sum<<endl;
    return 0;
}
