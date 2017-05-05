#include <bits/stdc++.h>

using namespace std;

int gcd(int m, int n)
{
    return m%n?gcd(n,m%n):n;
}

int main()
{
    int P,Q;
    while(~scanf("%d%d",&P,&Q))
    {
        int t=gcd(P,Q);
        int m=P/t*Q;
        int a=P*Q;
        int Count=0;
        if(Q%P){cout<<'0'<<endl;continue;}
        for(int i = t;i<=m;i+=t)
        {
            if(a%i!=0) continue;
            int j = a/i;

            if(gcd(i,j)==t) Count++,cout<<i<<endl;;
        }
        printf("%d\n",Count);
    }
    return 0;
}
