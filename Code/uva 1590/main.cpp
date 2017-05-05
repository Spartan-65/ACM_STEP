#include <bits/stdc++.h>
using namespace std;
int f(unsigned n)
{
    int c = 0;
    while(n)
    {
        n >>= 1;
        c++;
    }
   return c;
}
int main()
{
    int t;
    while(cin>>t)
    {
        unsigned Max = 0, Min = ~0;
        while(t--)
        {
            unsigned ip = 0;
            for(int i = 4;i--;)
            {
                unsigned t;
                scanf("%u%*c",&t);
                ip |= t<<8*i;
            }
            Max = max(Max, ip),Min = min(Min,ip);
        }
        unsigned mask = ~0;
        int a = f(Max^Min);
        if(a==32) { printf("0.0.0.0\n0.0.0.0\n"); continue;}
        mask >>= a,mask <<= a;
        Max >>= a, Max <<= a;
        for(int i = 4;i--;)
        {
            printf("%u%c",(Max>>8*i)&255,i?'.':'\n');
        }
        for(int i = 4;i--;)
        {
            printf("%u%c",(mask>>8*i)&255,i?'.':'\n');
        }
    }
    return 0;
}
