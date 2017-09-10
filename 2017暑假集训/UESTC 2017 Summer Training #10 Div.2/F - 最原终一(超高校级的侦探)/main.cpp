#include <bits/stdc++.h>
using namespace std;
char s[10005];
int a[10005];
int main()
{
    memset(a,0,sizeof(a));
    scanf("%s",s);
    int len=strlen(s);
    int t=0;
    for(int i=0;i<len;i++)
        a[i]=s[len-i-1]-'0';
    for(int i=2;i>=0;i--) t=t*10+a[i];
    int x;
    for(int i=t;;i++)
    {
        x=(i+1)*i/2*3-i;
        if(x%4==0) {x=i;break;}
    }
    a[0]+=(x-t);
    for(int i=0;i<len-1;i++)
    {
        if(a[i]>=10) a[i+1]+=a[i]/10,a[i]=a[i]%10;
        else break;
    }
    for(int i=len-1;i>=0;i--) printf("%d",a[i]);
    cout<<endl;
    return 0;
}
