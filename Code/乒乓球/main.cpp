#include <bits/stdc++.h>
using namespace std;
char str[200000];
int main()
{
    char ch;
    int p=0;
    while((ch=getchar())!='E')
    {
        if(ch=='\n') continue;
        str[p++]=ch;
    }
    str[p]='\0';
    p=0;
    int a=0,b=0;
    while(str[p]!='\0')
    {
        if(str[p]=='W') a++;
        else if(str[p]=='L') b++;
        if(max(a,b)>=11&&abs(a-b)>=2)
        {
            cout<<a<<':'<<b<<endl;
            a=0;
            b=0;
        }
        p++;
    }
    cout<<a<<':'<<b<<endl;
    cout<<endl;
    p=0;a=0,b=0;
    while(str[p]!='\0')
    {
        if(str[p]=='W') a++;
        else if(str[p]=='L') b++;
        if(max(a,b)>=21&&abs(a-b)>=2)
        {
            cout<<a<<':'<<b<<endl;
            a=0;
            b=0;
        }
        p++;
    }
    cout<<a<<':'<<b;
    return 0;
}
