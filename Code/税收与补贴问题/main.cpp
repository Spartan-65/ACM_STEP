#include <bits/stdc++.h>
using namespace std;

int main()
{
    int y;
    while(cin>>y)
    {
        map<int,int> M;
        int c;
        int a, b,m=0,e,f;
        int t2=0;
        cin>>a>>b;
        M[a]=b;
        c=a;

        while(cin>>e>>f)
        {
            if(e==-1&&f==-1) break;
            int t=(b-f)/(e-a);
            for(int i = a+1;i<e;i++)
            {
                M[i]=b-(i-a)*t;
            }
            M[e]=f;
            if(e>m) m=e;
            a=e,b=f;
        }
        cin>>t2;
        for(int i=m+1;;i++)
        {
            int t=M[m]-(i-m)*t2;
            if(t<0) break;
            M[i]=t;
            m=i;
        }
        if(!M.count(y)) {cout<<"NO SOLUTION"<<endl; continue;}
        double Max=999999999;
        int mix=(y-c)*(M[y]);
        for(int i = c;i<y;i++)
        {
            double t= (mix-((i-c)*M[i]))*1.0/(M[i]-M[y]);
            if(t<Max) Max=t;
        }
        double Min=-999999999;
        for( int i = y+1;i<=m;i++)
        {
            double t=((i-c)*M[i]-mix)*1.0/(M[y]-M[i]);
            if(t>Min) Min=t;
        }
        if(Min>Max) {cout<<"NO SOLUTION"<<endl; continue;}
        if(abs(Min)<abs(Max)) cout<<ceil(Min)<<endl;
        else cout<<floor(Max)<<endl;
    }
    return 0;
}
