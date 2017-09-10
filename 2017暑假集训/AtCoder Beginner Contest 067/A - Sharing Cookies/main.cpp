#include <bits/stdc++.h>
using namespace std;
int main()
{
int a,b;
while(cin>>a>>b)
{
    if((a+b)%3==0)cout<<"Possible"<<endl;
    else if(a%3==0)cout<<"Possible"<<endl;
    else if(b%3==0) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}
}
