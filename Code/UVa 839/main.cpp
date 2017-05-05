/*
#include <bits/stdc++.h>
using namespace std;
bool solve(int& W)
{
    int w1,d1,w2,d2;
    bool b1=true, b2=true;
    cin>>w1>>d1>>w2>>d2;
    if(!w1) b1=solve(w1);
    if(!w2) b2=solve(w2);
    W=w1+w2;
    return b1&&b2&&(w1*d1==w2*d2);
}
int main()
{
    int t,w=0;
    cin>>t;
    while(t--)
    {
        if(solve(w)) cout<<"YES"<<endl;else cout<<"NO"<<endl;
        if(t)puts("");
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
bool build(int& W)
{
    int w1,w2,d1,d2;
    bool b1 = true,b2 = true;
    cin>>w1>>d1>>w2>>d2;
    if(!w1) b1 = build(w1);
    if(!w2) b2 = build(w2);
    W=w1+w2;
    return b1&&b2&&(w1*d1==w2*d2);
}
int main()
{
    int t,W;
    cin>>t;
    while(t--)
    {
        if(build(W))cout<<"YES"<<endl; else cout<<"NO"<<endl;
        if(t) puts("");
    }
}
