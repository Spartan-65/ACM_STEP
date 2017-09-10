#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int main()
{
    char s[1001];int a[1001];
    while(~scanf("%s",s)){
        int l=strlen(s);
        for(int i=0;i<l;i++)
        a[i]=s[i]-'0';
        sort(a,a+l);
        for(int i=0;i<l;i++)
        printf("%d",a[i]);
        printf("\n");
    }
return 0;
}
