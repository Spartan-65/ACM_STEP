#include <bits/stdc++.h>
#include <string>
using namespace std;
int n;
string tab[5][4];
void print()
{
    printf("+----------+----------+----------+\n");
    for(int i=1;i<=4;i++)
    {
        bool flag=false;
        for(int j=1;j<=3;j++)
        {
            printf("|");
            int len;
            if(tab[i][j].size()<=10)
            {
                len=10-tab[i][j].size();
                cout<<tab[i][j];
                tab[i][j].clear();
                for(int i=0;i<len;i++)printf(" ");
            }
            else
            {
                string temp,te;
                stringstream ss(tab[i][j]);
                ss>>temp;
                int t=temp.size();
                while(ss>>te)
                {
                    if(te.size()+t+1<=10)
                    {
                        temp+=" ";
                        temp+=te;
                        t=temp.size();
                    }
                    else break;
                }
                len=10-temp.size();
                cout<<temp;
                for(int i=0;i<len;i++) printf(" ");
                tab[i][j].erase(0,10-len);
                if(tab[i][j][0]==' ') tab[i][j].erase(0,1);
                if(tab[i][j].size()>0) flag=true;
            }
            if(j==3) printf("|\n");
        }
        if(flag) i--;
        else printf("+----------+----------+----------+\n");
    }

}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        string s,temp;
        int x;
        scanf("%*c");
        getline(cin,temp);
        cin>>s>>x;
        if(s=="Tuesday") tab[x][1]=temp;
        else if(s=="Thursday") tab[x][2]=temp;
        else tab[x][3]=temp;
    }
    print();
    return 0;
}
