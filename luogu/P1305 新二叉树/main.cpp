#include <bits/stdc++.h>
using namespace std;
int flag[26];
struct node
{
    int l,r;
}t[26];

void print(int x)
{
    if(x==-1) return;
    printf("%c",('a'+x));
    print(t[x].l);
    print(t[x].r);
}
int main()
{
    int n;
    while(cin>>n)
    {
        char temp[4];
        memset(flag,0,sizeof(flag));
        for(int i = 0;i<n;i++)
        {
            scanf("%s",temp);
            flag[temp[0]-'a']++;
            if(temp[1]!='*')
                {
                    t[temp[0]-'a'].l=temp[1]-'a';
                    flag[temp[1]-'a']++;
                }
            else t[temp[0]-'a'].l=-1;
            if(temp[2]!='*')
            {
                t[temp[0]-'a'].r=temp[2]-'a';
                flag[temp[2]-'a']++;
            }

            else
                t[temp[0]-'a'].r=-1;
        }
        for(int i = 0;i<26;i++)
            if(flag[i]==1)
            {
                print(i);
                printf("\n");
                break;
            }
    }
    return 0;
}
