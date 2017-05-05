#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[105]={'0'}, b[100]={'0'};
    memset(a,'0',sizeof(a));memset(b,'0',sizeof(b));
    while(~scanf("%s %s",&a[1],&b[1]))
    {
        int lena=strlen(a),lenb=strlen(b),ta=0,tb=0;
        //printf("%s\n%s\n",a,b);
        //cout<<lena<<' '<<lenb<<endl;
        int len=max(lena,lenb);int C=len;lena--,lenb--,len--;
        int c[105]={0};
        while(len)
        {
            if(lena)ta=a[lena--]-'0';
            if(lenb)tb=b[lenb--]-'0';
            int t=ta+tb+c[len];
            c[len]=t%10;
            c[--len]+=t/10;
            ta=tb=0;
        }
        if(c[0]) printf("%d",c[0]);
        for(int i = 1;i<C;i++) printf("%d",c[i]);
        printf("\n");
        //printf("%d\n",c[1]);
        memset(a,'0',sizeof(a));memset(b,'0',sizeof(b));

    }
    return 0;
}
