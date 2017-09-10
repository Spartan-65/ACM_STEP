#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    bool up=false,m=false,down=false,flag=true;
    int now=0,last=0;
    for(int i=0;i<n;i++){
        cin>>now;
        if(last){
            if(now-last>0){
                up=true;
                if(down||m){
                    flag=false;
                }
            }
            if(now-last==0){
                m=true;
                if(down){
                    flag=false;
                }
            }
            if(now-last<0){down=true;}
        }
        last=now;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
