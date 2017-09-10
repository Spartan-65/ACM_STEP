#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[105];
    int x;
    while(~scanf("%s%d",s,&x))
    {
        int S[100],top=0; S[top++]=s[0]-'0';
        int ans1=s[0]-'0';
        for(int i=1;i<strlen(s);i+=2)
        {
            if(s[i]=='+') ans1+=(s[i+1]-'0');
            else ans1*=(s[i+1]-'0');
        }
        int ans2=0;
        for(int i=1;i<strlen(s);i+=2)
        {
            if(s[i]=='+'){
                S[top++]=s[i+1]-'0';
            }
            else
            {
                int t=s[i+1]-'0';
                S[top-1]*=t;
            }
        }
        for(int i=0;i<top;i++) ans2+=S[i];
        if(ans1==ans2&&ans1==x)
        {
            printf("U\n");
        }
        else if(ans1==x)
        {
            printf("L\n");
        }
        else if(ans2==x)
        {
            printf("M\n");
        }
        else printf("I\n");
    }

    return 0;
}
