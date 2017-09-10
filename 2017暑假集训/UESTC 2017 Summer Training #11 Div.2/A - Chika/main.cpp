#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("bulls.in","r",stdin);
    freopen("bulls.out","w",stdout);
    char s1[10],s2[10];
    bool flag[10];
    while(~scanf("%s%s",s1,s2))
    {
        int a=0,b=0;
        memset(flag,0,sizeof(flag));
        for(int i=0;i<4;i++)
            flag[s1[i]-'0']=1;
        for(int i=0;i<4;i++)
            if(s1[i]==s2[i]) a++;
        for(int i=0;i<4;i++)
            if(flag[s2[i]-'0']) b++;
        cout<<a<<' '<<b-a<<endl;
    }

    return 0;
}
