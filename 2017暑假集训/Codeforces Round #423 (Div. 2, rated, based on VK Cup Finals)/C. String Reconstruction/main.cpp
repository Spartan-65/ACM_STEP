#include <bits/stdc++.h>
using namespace std;
const int maxn=2000005;
char str[maxn],s[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<maxn;i++)
            str[i]='a';
        int len=0;
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%s",s);
            scanf("%d",&t);
            int len1=strlen(s);
            for(int j=0;j<t;j++)
            {
                int tt;
                scanf("%d",&tt);
                len=max(len,tt+len1-1);
                for(int k=0;k<len1;k++)
                    str[tt+k]=s[k];
            }
        }
        for(int i=1;i<=len;i++) printf("%c",str[i]);
        printf("\n");
    }
}
