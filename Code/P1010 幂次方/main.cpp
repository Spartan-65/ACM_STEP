#include <bits/stdc++.h>

using namespace std;
void solve(unsigned int n)
{
    if(n==0)
        printf("0");
    else if(n==1)
        printf("2(0)");
    else if(n==2) printf("2");
    else
    {
        int p=0;
        unsigned int  a[15],Count=0;
        while(n)
        {
            if(n&1) a[p++]=Count;
            n>>=1;
            Count++;
        }
        for(int i = p-1;i>0;i--)
        {
            //printf("%u\n",a[i]);
            if(a[i]==1) {printf("2+");}
            else
            {printf("2(");
            solve(a[i]);
            printf(")+");}
        }
        if(a[0]==1) printf("2");
        else
           { printf("2(");
            solve(a[0]);
            printf(")");}

    }
    return;
}
int main()
{
    unsigned int n;

    scanf("%u",&n);
    solve(n);
    return 0;
}
