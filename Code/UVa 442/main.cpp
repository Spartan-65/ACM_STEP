#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

struct M
{
    int a, b;
    M(int a = 0, int b = 0):a(a),b(b){}
}m[26];
stack<M> s;
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string name;
        cin>>name;
        int k = name[0] -'A';
        cin>>m[k].a>>m[k].b;
        }
    string str;
    while(cin>>str){
        int len = str.length();
        bool flag = false;
        int ans = 0;
        for(int i = 0;i< len;i++){
            if(isalpha(str[i])) s.push(m[str[i]-'A']);
            else if(str[i] == ')'){
                M m2 = s.top(); s.pop();
                M m1 = s.top(); s.pop();
                if(m1.b != m2.a) {flag = true; break;}
                ans += m1.a*m1.b*m2.b;
                s.push(M(m1.a,m2.b));
            }
        }
        if(flag) printf("error\n"); else printf("%d\n",ans);
    }
    return 0;

}
