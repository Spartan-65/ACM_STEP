#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;
map<string, int> ID;

int main(){
    int m, n;
    while(~scanf("%d%d%*c",&n,&m)){
        int table[n][m];
        ID.clear();
        char ch;
        int num = 0;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++){
                char ch;
                string str;
                while((ch = getchar())!='\n'&&ch!=',')
                    str += ch;
                if(ID.count(str)) table[i][j] = ID[str];
                else table[i][j] = ID[str] = num++;
            }
        bool flag = false;
        for(int i = 0;i<m;i++){
        for(int j = i+1;j<m;j++){
            pair<int, int> P;
            map<pair<int, int>,int> P2;
            int C = 0;
            for(int k = 0;k<n;k++){
                P.first = table[k][i], P.second = table[k][j];
                if(P2.count(P)){
                    flag = true;
                    printf("NO\n%d %d\n%d %d\n",P2[P],k+1,i+1,j+1);
                    break;
                }
                else P2[P] = k + 1;
            }
            if(flag) break;
        }
        if(flag) break;
        }
        if(!flag) cout<<"YES"<<endl;
    }
    return 0;
}
