#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n,k,l,d;
    int s1[10001]={0},s2[10001]={0};
    fill(s1,s1+10001,0);
    fill(s2,s2+10001,0);
    cin>>m>>n>>k>>l>>d;
    for(int i = 0;i<d;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==c)
        {
            if(b<d)s2[b]++;
            else s2[d]++;
        }
        else{
        if(a<c) s1[a]++;
        else s1[c]++;
        }
    }
    int m1=0,m2=0;
    for(int i = 0;i<10000;i++) if(m1<s1[i]) m1=s1[i];
    for(int i = 0;i<10000;i++) if(m2<s2[i]) m2=s2[i];
    int c=0;
    while(c<k){
        for(int i=0;i<10000;i++) if(m1==s1[i]) c++;
        m1--;
    }
    m1++;
    c=0;
    while(c<l)
    {
        for(int i = 0;i<10000;i++) if(m2==s2[i]) c++;
        m2--;
    }
    m2++;
    for(int i = 0;i<10000;i++) if(s1[i]>=m1) cout<<i<<' '; cout<<endl;
    for(int i = 0;i<10000;i++) if(s2[i]>=m2) cout<<i<<' '; cout<<endl;
    return 0;
}
