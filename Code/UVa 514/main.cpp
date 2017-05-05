#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {

        while(scanf("%d",&a[1]),a[1])
        {
            stack<int> s;
            int  A =1, B = 1;
            bool flag = false;
            for(int i = 2;i<=n;i++)
                scanf("%d",&a[i]);
            while(B<=n){
                if(A==a[B]){ A++, B++;}
                else if(!s.empty()&&s.top()==a[B]){ s.pop();B++;}
                else if(A<=n) {s.push(A++);}
                else { flag = true; break;}
            }
            if(flag) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
        cout<<endl;
    }
}
