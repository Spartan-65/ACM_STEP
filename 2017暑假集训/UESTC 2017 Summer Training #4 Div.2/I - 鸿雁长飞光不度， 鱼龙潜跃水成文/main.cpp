#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int B[maxn],R[maxn];
char str[100];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int b=0,r=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            int len=strlen(str);
            int t=0;
            for(int j = 0;j<len-1;j++)
                t=t*10+(str[j]-'0');
            if(str[len-1]=='R') R[r++]=t;
            else B[b++]=t;
        }
        sort(R,R+r);
        sort(B,B+b);
        int len=min(r,b);
        int ans=0;
        for(int i=0;i<len;i++)
        {
            ans+=B[b-i-1];
            ans+=R[r-i-1];
        }
        ans-=(2*len);
        printf("%d\n",ans);
    }

    return 0;
}
