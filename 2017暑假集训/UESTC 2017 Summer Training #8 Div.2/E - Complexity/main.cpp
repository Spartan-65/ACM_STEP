#include <bits/stdc++.h>
using namespace std;
char s[105];
int a[30];
int main()
{
    while(~scanf("%s",s))
    {
        memset(a,0,sizeof(a));
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            a[s[i]-'a']++;
        }
        sort(a,a+26);
        len-=(a[25]+a[24]);
        cout<<len<<endl;
    }

}
