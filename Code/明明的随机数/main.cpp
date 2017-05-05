#include <bits/stdc++.h>
using namespace std;
struct p
{
    string num;
    int mark;

};
bool cmp(p a, p b)
{
    if(a.mark!=b.mark)
        return a.mark>b.mark;

    else
    return a.num<b.num;
}
int main()
{
    int n,m;
    cin>>n>>m;
    p a[n];
    for(int i = 0;i<n;i++)
    {
        string num;
        int mark;
        cin>>num>>mark;
        a[i].num=num;
        a[i].mark=mark;
    }
    sort(a,a+n,cmp);
    int limit=a[(int)(m*1.5)-1].mark;
    int Count=m*1.5;
    while(a[Count].mark>=limit) Count++;
    cout<<limit<<' '<<Count<<endl;
    for(int i = 0;i<Count;i++)
        cout<<a[i].num<<' '<<a[i].mark<<endl;

}
