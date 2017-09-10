#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
string s;
int len[maxn];
vector<string> ans[maxn];
int main()
{
    int p=0;
    ifstream in("alignment.in");
    ofstream out("alignment.out");
    memset(len,0,sizeof(len));
    while(getline(in,s))
    {
        stringstream ss(s);
        string buf;
        int cnt=0;
        while(ss>>buf){
            int t=buf.size();
            len[cnt]=max(len[cnt],t);
            ans[p].push_back(buf);
            cnt++;
        }
        if(!ans[p].empty()) p++;
    }
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<ans[i].size()-1;j++)
        {
            out<<ans[i][j];
            int t=len[j]-ans[i][j].size();
            for(int k=0;k<t;k++) out<<" ";
            out<<" ";
        }
        out<<ans[i][ans[i].size()-1]<<endl;
    }
    in.close();out.close();
    return 0;
}
