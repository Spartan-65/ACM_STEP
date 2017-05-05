#include <bits/stdc++.h>
using namespace std;
char wei[4][10]={"","shi","bai","qian"};
char num[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char s[15];
bool flag;
int len,len1;
void Print(int cur, int n)
{
    if(!n) return ;
    if(cur==len1) flag=false;
    if(s[cur]=='2'&&n==4&&cur+1==len1) { printf("liang %s ",wei[n-1]);}
    else if(s[cur]=='0'&&flag&&n!=1) {printf("ling ");flag=false;}
    else if(cur==0&&s[cur]=='1'&&n==2) printf("shi ");
    else {
        if(s[cur]!='0')
            {printf("%s %s",num[s[cur]-'0'],wei[n-1]);if(n!=1)printf(" ");}

    }
    if(s[cur]!='0') flag=true;
    Print(cur+1,n-1);
}

int main()
{
    while(~scanf("%s",&s))
    {
        int cur=0;len=strlen(s),len1=len-1;
        if(s[len-1]=='0') while(1) if(s[len1-1]!='0') break; else len1--;
        flag = true;
        if(len>8){Print(cur,len%8);printf("yi "); cur=len-8;flag = true; }
        if(len>4)
        { if(cur) {Print(cur, len-cur-4);if(s[cur]!='0'||s[cur+1]!='0'||s[cur+2]!='0'||s[cur+3]!='0')printf("wan "); } else Print(cur, len%4),printf("wan ");cur=len-4; }
        Print(cur, len-cur);
        printf("\n");
    }
    return 0;
}
