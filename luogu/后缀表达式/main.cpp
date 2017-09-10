#include <bits/stdc++.h>
using namespace std;
int s[1000];
int main()
{
    int temp=0;
    int ans=0,top=0;
    char ch;
    while((ch=getchar())!='@')
    {
        if(ch=='.') {s[top++]=temp;temp=0;continue;}
        else if(ch>='0'&&ch<='9') temp=temp*10+(ch-'0');
        else{
            int a=s[--top];
            int b=s[--top];
            if(ch=='+') s[top++]=a+b;
            else if(ch=='-') s[top++]=b-a;
            else if(ch=='*') s[top++]=a*b;
            else if(ch=='/') s[top++]=b/a;
        }
    }
    cout<<s[0]<<endl;
    return 0;
}
