#include <bits/stdc++.h>
using namespace std;
vector<int> pile[30];
int n;
void Find(int m,int& p, int& h)
{
    for(p = 0;p <n;p++)
        for(h = 0;h<pile[p].size();h++ )
            if(pile[p][h] == m ) return ;

}
void Back(int p,int h)
{
    for(int i = h+1;i<pile[p].size();i++)
        pile[pile[p][i]].push_back(pile[p][i]);
    pile[p].resize(h+1);
}
void Print()
{
    for(int i = 0;i<n;i++)
    {
        cout<<i<<':';
        for(int h = 0;h<pile[i].size();h++)
            cout<<' '<<pile[i][h];
        cout<<endl;
    }
}
int main()
{
    while(cin>>n)
    {
        string s1, s2;

        for(int i = 0;i<n;i++) pile[i].push_back(i);
        while(cin>>s1)
        {
            int a, b, pa, pb, ha, hb;
            if(s1=="quit") break;
            cin>>a>>s2>>b;
            Find(a, pa, ha);
            Find(b, pb, hb);
            if(pa == pb) continue;
            if(s2 == "onto") Back(pb, hb);
            if(s1 == "move") Back(pa, ha);
            for(int i = ha;i<pile[pa].size();i++)
                pile[pb].push_back(pile[pa][i]);
            pile[pa].resize(ha);
        }
        Print();
    }
    return 0;
}
