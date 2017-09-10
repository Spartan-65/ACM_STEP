#include <bits/stdc++.h>
using namespace std;
const int maxn=80005;
char s1[maxn],s2[maxn];
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        scanf("%s%s",s1,s2);
        int Count=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])Count++;
        }
        if(abs(x-y)>Count){
            printf("Lying\n");
        }
        else {
            int same=n-Count;
            x-=same,y-=same;
            if(x+y+same>n) printf("Lying\n");
            else printf("Not lying\n");
        }
    }
    return 0;
}
