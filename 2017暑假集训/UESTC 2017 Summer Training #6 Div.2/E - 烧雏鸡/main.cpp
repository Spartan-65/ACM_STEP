#include <bits/stdc++.h>
using namespace std;
const int maxn=10000;
int table[10][10];
int ssn[maxn];
int temp[5];
void work(int x)
{
    for(int j=4;j>=0;j--){
        temp[j]=x%10;
        x/=10;
    }
}
bool check(int n){
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<10;j++)
        {
            work(n);
            if(temp[i]==j) continue;
            temp[i]=j;
            int e=0;
            for(int k=0;k<5;k++){
                e=table[e][temp[k]];
            }
            if(e==0) return true;
        }
    }
    for(int i=1;i<5;i++)
    {
        work(n);
        if(temp[i-1]==temp[i])continue;
        swap(temp[i-1],temp[i]);
        int e=0;
        for(int j=0;j<5;j++){
            e=table[e][temp[j]];
        }
        if(e==0) return true;
    }
    return false;
}
int main()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            scanf("%d",&table[i][j]);
    for(int i=0;i<10000;i++)
    {
        int a[4],t=i;
        for(int j=3;j>=0;j--){
            a[j]=t%10;
            t/=10;
        }
        for(int j=0;j<4;j++)
            t=table[t][a[j]];
        ssn[i]=i*10+t;
    }
    int ans=0;

    for(int i=0;i<maxn;i++)
    {
        if(check(ssn[i]))ans++;
    }
    cout<<ans<<endl;


    return 0;
}
