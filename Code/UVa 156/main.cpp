#include <bits/stdc++.h>
using namespace std;
map<string,int> cnt;
vector<string> word;
string f(string s)
{
    string ss = s;
    for(int i = 0;i<s.length();i++)
        ss[i] = tolower(ss[i]);
    sort(ss.begin(), ss.end());
    return ss;
}
int main()
{
    string s;
    while(cin>>s)
    {
        if(s[0]=='#') break;
        string ss = f(s);
        word.push_back(s);
        if(!cnt.count(ss)) cnt[ss] = 0;
        cnt[ss]++;
    }
    vector<string> ans;
    for(int i = 0;i<word.size();i++)
        if(cnt[f(word[i])] == 1) ans.push_back(word[i]);
    sort(ans.begin(),ans.end());
    for( int i = 0;i<ans.size();i++ )
        cout<<ans[i]<<endl;
    return 0;
}
