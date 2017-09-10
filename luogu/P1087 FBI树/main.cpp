#include <bits/stdc++.h>
using namespace std;
int n;
char s[1500];
void build(int l,int r)
{
    int mid=(l+r)>>1;
    if(l!=r)
    {
        build(l,mid);
        build(mid+1,r);
    }
    int a=0,b=0;
    for(int i = l;i<=r;i++)
        if(s[i]=='0') a++;
        else b++;
    if(a&&b)printf("F");
    else if(a) printf("B");
    else printf("I");
}


int main()
{
    while(cin>>n)
    {
        scanf("%s",&s[1]);
        build(1,pow(2,n));
        printf("\n");
    }
}
