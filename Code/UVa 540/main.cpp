#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;


int main()
{
    int t, x, n, C = 1;
    while(cin>>t,t)
    {
        printf("Scenario #%d\n",C++);
        map<int, int> team;
        for(int i = 1;i<=t;i++)
        {
            cin>>n;
            while(n--) {cin>>x; team[x]  = i;}
        }
        char str[10];
        queue<int> q, q2[1005];
        while(cin>>str)
        {
            if(str[0] == 'S') break;
            else if(str[0] == 'E'){
                cin>>x;
                int t = team[x];
                if(q2[t].empty()) q.push(t);
                q2[t].push(x);
            }
            else if(str[0] == 'D'){
                int t = q.front();
                cout<<q2[t].front()<<endl;
                q2[t].pop();
                if(q2[t].empty()) q.pop();
            }
        }
        putchar('\n');
    }
    return 0;
}
