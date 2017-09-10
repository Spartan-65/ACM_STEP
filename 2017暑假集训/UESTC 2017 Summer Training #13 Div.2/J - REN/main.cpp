#include <bits/stdc++.h>
using namespace std;
bool flag[27];
int main()
{
    string s;
    memset(flag,0,sizeof(flag));
    int n;
    cin>>s;
    cin>>n;
    int len=s.size();
    int C=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]!='?')
        {
            char ch=s[i];
            if(!flag[ch-'a'])
            {
                C++;
                flag[ch-'a']=1;
            }
        }
    }
    for(int i=0;i<len;i++)
    {
        if(s[i]=='?')
        {
            if(i&1)
            {
                if(C<n)
                {
                    for(int j=0;j<26;j++)
                    {
                        if(!flag[j])
                        {
                            s[i]=j+'a';
                            flag[j]=1;
                            C++;break;
                        }
                    }
                }
                else s[i]='a';
            }
            else
            {
                if(C<n)
                {
                    for(int j=25;j>=0;j--)
                    {
                        if(!flag[j])
                        {
                            s[i]=j+'a';
                            flag[j]=1;
                            C++;break;
                        }
                    }
                }
                else s[i]='z';
            }
        }
    }
    if(C<n) cout<<"-1"<<endl;
    else cout<<s<<endl;
}
