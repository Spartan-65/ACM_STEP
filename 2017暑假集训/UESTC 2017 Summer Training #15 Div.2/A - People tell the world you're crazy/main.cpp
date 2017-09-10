#include <bits/stdc++.h>
using namespace std;
char d[10000005];
int main()
{
    int p;
    scanf("%d",&p);
    for(int i=0;i<p;i++)
    {
        int id,b;
        scanf("%d%d%s",&id,&b,d);
        int ans=0;
        for(int i=0;i<strlen(d);i++)
        {
            ans=(ans+(s[i]-'0'%(b-1))%(b-1));

        }
        printf("%d %d\n",id,ans);
    }
    return 0;
}
