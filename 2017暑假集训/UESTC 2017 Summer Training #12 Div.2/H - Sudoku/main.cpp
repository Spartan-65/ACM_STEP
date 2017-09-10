#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;
int a[81],cnt;
bool qu[3][3][10];
bool hang[9][10];
bool lie[9][10];
void print()
{
    for(int i=0;i<81;i++)
    {
        cout<<a[i];
        if((i+1)%9==0)cout<<endl;
    }
    cout<<endl;
}
bool dfs(int n,int s)
{
    for(int i=s;i<81;i++)
    {
        if(a[i]) continue;
        for(int j=1;j<=9;j++)
        {
            if(hang[i/9][j]||lie[i%9][j]||qu[i/27][(i%9)/3][j]) continue;
            hang[i/9][j]=lie[i%9][j]=qu[i/27][(i%9)/3][j]=1;
            a[i]=j;
            if(!dfs(n+1,i+1))hang[i/9][j]=lie[i%9][j]=qu[i/27][(i%9)/3][j]=a[i]=0;
            else return 1;
        }
        if(a[i]==0) return 0;
    }
    return 1;
}
int main()
{
    string s;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        s.clear();
        for(int i=0;i<9;i++)
        {
            string temp;
            cin>>temp;
            s+=temp;
        }
        memset(hang,0,sizeof(hang));
        memset(lie,0,sizeof(lie));
        memset(qu,0,sizeof(qu));
        if(s=="end")return 0;
        cnt=0;
        for(int i=0;i<81;i++)
        {
            char ch=s[i];
            if(s[i]=='.') ch='0';
            a[i]=ch-'0';
            hang[i/9][a[i]]=1;
            lie[i%9][a[i]]=1;
            qu[i/9/3][(i%9)/3][a[i]] = 1;
            if(ch=='0') cnt++;
        }
        dfs(1,0);
        print();
    }
}
