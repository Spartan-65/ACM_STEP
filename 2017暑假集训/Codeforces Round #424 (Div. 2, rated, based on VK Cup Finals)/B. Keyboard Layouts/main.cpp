#include <bits/stdc++.h>
using namespace std;
char a[30],b[30],out[30];
int main()
{
    cin>>a;cin>>b;
    for(int i=0;i<26;i++)
    {
        out[a[i]-'a']=b[i];
    }
    char s[1005];
    cin>>s;
    for(int i=0;i<strlen(s);i++)
    {
        char ch=s[i];
        if(ch<='z'&&ch>='a') ch=out[ch-'a'];
        if(ch<='Z'&&ch>='A') ch=out[ch-'A']-32;
        printf("%c",ch);
    }
    cout<<endl;
}
