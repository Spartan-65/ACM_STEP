#include <bits/stdc++.h>
using namespace std;
int main()
{
    char ch;
    char s[250];
    int top=0;
    while((ch=getchar())!='@')
    {
        if(ch=='(') s[top++]=ch;
        else if(ch==')') top--;
    }
    if(!top)printf("YES\n");
    else printf("NO\n");
    return 0;
}
