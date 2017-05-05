#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        string str;
        bool flag = true;
        int c=0,sum = 0;
        cin>>str;
        int p=n-1;
        for(int i = 0;i<p;i++)
        {
            for(int j = p;j>=i;j--)
            {
                if(j==i){
                    if(!(n&1)||(c)){flag=false; break;}
                    c++;
                    sum+=(n/2-i);
                    break;
                }
                if(str[i]==str[j]){
                    for(int k = j;k<p;k++)
                        str[k]=str[k+1];
                str[p]=str[i];
                sum += (p-j);
                p--;
                break;
                }
            }
            if(!flag) break;
        }
        if(flag) cout<<sum<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
