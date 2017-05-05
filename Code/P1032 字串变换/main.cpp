#include <bits/stdc++.h>

using namespace std;

map<string,int> M;
string  a[10],b[10],st,ed;
int n;
struct f
{
    string s;
    int step;
};
void bfs()
{
    queue<f> q;
    M[st]=1;
    q.push(f{st,0});
    while(!q.empty()&&q.front().step<10)
    {
        f t=q.front();q.pop();
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<t.s.size();j++)
            if(t.s.substr(j,a[i].size())==a[i])
            {
                f tt=t;
                tt.s.replace(j,a[i].size(),b[i]);
                if(!M[tt.s])
                {
                    tt.step++;
                    M[tt.s]=1;
                    q.push(tt);
                }
                if(tt.s==ed)
                {
                    cout<<tt.step<<endl;
                    return ;
                }
            }
        }
    }
    cout<<"NO ANSWER!"<<endl;
}
int main()
{
    n=0;
    cin>>st>>ed;
    while(cin>>a[n]>>b[n]) n++;
    bfs();
    return 0;
}

