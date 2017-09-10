#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
string s[maxn];
int lon[maxn],w[maxn];
int main()
{
    int T;
    while(~scanf("%d",&T))
    {
        scanf("%*c");
        while(T--)
        {
            int p=0;
            while(getline(cin,s[p]))
            {
                if(s[p]=="@") break;
                p++;
            }
            memset(lon,0,sizeof(lon));
            for(int i=0;i<p;i++)
            {
                stringstream ss(s[i]);
                string temp;
                int cnt=0;
                while(ss>>temp)
                {
                    int len=temp.size();
                    lon[cnt]=max(lon[cnt],len);
                    cnt++;
                }
                w[i]=cnt;
            }
            for(int i=0;i<p;i++)
            {
                stringstream ss(s[i]);
                string temp;
                int cnt=-1;
                while(ss>>temp)
                {
                    int len=temp.size();
                    cout<<temp;
                    cnt++;
                    if(cnt==w[i]-1)break;
                    for(int j=len;j<=lon[cnt];j++) cout<<' ';
                }
                cout<<endl;
            }
        }
    }
}
