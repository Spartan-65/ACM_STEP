#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;

int main(){
    int n;
    string str[105];
    while(cin>>n){
        int m = 0;
        for(int i = 0;i<n;i++){
            cin>>str[i];
            if(m < str[i].length()) m = str[i].length();
        }
        cout<<"------------------------------------------------------------"<<endl;
        sort(str,str+n);
        int column = (60 - m)/(m+2)+1, row = (n-1)/column + 1;
        for(int i = 0;i<row;i++){
            for(int j = i;j<n;j+=row){
                    printf("%-*s", (j+row)<n?m+2:m, str[j].c_str());
            }
            putchar('\n');
        }
    }
    return 0;
}
