#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
char str[maxn];
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='1')
        {
            if(a[i%n])
            {
                printf("%d %d\n",a[i%n],i+1);
                return 0;
            }
            else a[(i+1)%n]=i+1;
        }
    }
    printf("0 0\n");
    return 0;
}
