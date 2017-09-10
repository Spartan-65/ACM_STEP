#include <bits/stdc++.h>
using namespace std;
string s1,s2;

void work(int l1,int r1,int l2,int r2)
{
    if(l1>r1) return;
    cout<<s2[r2];
    char root=s2[r2];
    int p=l1;
    while(s1[p]!=root) p++;
    int cnt=p-l1;
    work(l1,p-1,l2,l2+cnt-1);
    work(p+1,r1,l2+cnt,r2-1);
}


int main()
{
    while(cin>>s1>>s2)
    {
        work(0,s1.length()-1,0,s2.length()-1);
        printf("\n");
    }
    return 0;
}
