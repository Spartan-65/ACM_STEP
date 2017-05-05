#include <bits/stdc++.h>
using namespace std;
int tongfen(int m,int n)
{
    return m%n?tongfen(n,m%n):n;
}
int add()
{
    int a,b,c,d;
    a=1,b=3,c=2,d=3;
    int t=tongfen(b,d);
    t=b*d/t;
    cout<<t<<endl;
    int t1= t/b;
    int t2=t/d;
    cout<<t1<<' '<<t2<<endl;
    int sum=((a*t1)+(c*t2))/t;
    cout<<sum<<endl;
    return sum;

}
int main()
{
    cout<<add()<<endl;


}
