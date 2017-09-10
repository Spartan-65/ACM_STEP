#include <bits/stdc++.h>
using namespace std;
int main()
{
    int P;scanf("%d",&P);
    string s;
    //freopen("out","w",stdout);
    while(P--)
    {
        int id;scanf("%d%*c",&id);
        getline(cin,s);
        int n;scanf("%d",&n);
        int p=0,len=s.size();
        printf("%d ",id);
        for(int i=0;i<n;i++)
        {
            int t;scanf("%d",&t);
            p+=t;
            p=(p+len)%len;
            cout<<s[p];
        }
        cout<<endl;
    }
    return 0;
}
