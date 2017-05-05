#include <bits/stdc++.h>
using namespace std;
char s1[1000],s2[1000];
char* Strlwr(char* s)
{
    for(int i = 0;i<strlen(s);i++)
        if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
    return s;
}
int main()
{

    while(~scanf("%s%s",s1,s2))
    {
        if(strlen(s1)!=strlen(s2)) cout<<"1"<<endl;
        else if(!strcmp(s1,s2)) cout<<"2"<<endl;
        else if(!strcmp(Strlwr(s1),Strlwr(s2))) cout<<"3"<<endl;
        else cout<<"4"<<endl;
    }
    return 0;
}
