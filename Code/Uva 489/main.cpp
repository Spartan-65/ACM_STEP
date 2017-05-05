#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n == -1) return 0;
        cout<<"Round "<<n<<endl;
        string s, s1;
        cin>>s>>s1;
        int chance = 7, x = s.length();
        bool win = false, lose = false;
        for(int i = 0;i<s1.length();i++)
        {
            bool f = true;
            for(int j = 0;j<s.length();j++)
            if(s[j]==s1[i]){ x--; s[j] = ' '; f = false; }
            if(f) chance--;
            if(!chance) lose = true;
            if(!x) win = true;
            if(win||lose) break;
        }

        if(win) cout<<"You win."<<endl;
        else if(lose) cout<<"You lose."<<endl;
        else cout<<"You chickened out."<<endl;
    }
    return 0;
}
