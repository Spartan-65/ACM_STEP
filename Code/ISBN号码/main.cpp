#include <bits/stdc++.h>
using namespace std;
int main()
{

    int ans = 0;
    string str;
    cin>>str;
    int Count=1;
    for(int i = 0;i<str.length()-1;i++)
    {
        if(str[i]=='-') continue;
        int t = str[i]-'0';
        t=t*(Count);
        ans += t;
        ans%=11;
        Count++;
    }
    int a=str[str.length()-1]-'0';
    if(a==ans||(ans==10&&str[str.length()-1]=='X')) cout<<"Right"<<endl;
    else{
        for(int i = 0;i<str.length()-1;i++)
            cout<<str[i];
        if(ans==10) cout<<'X'<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
