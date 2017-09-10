/*hdu1907*/

#include <bits/stdc++.h>
using namespace std;
const int maxn=50;
int main()
{
    int t;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            int n;
            scanf("%d",&n);
            int Count=0,ans=0;
            for(int i=0;i<n;i++)
            {
                int t;
                scanf("%d",&t);
                ans^=t;
                if(t>=2) Count++;
            }
            if(Count==0)
            {
                if(ans) cout<<"Brother"<<endl;
                else cout<<"John"<<endl;
            }
            else if(Count==1){
                cout<<"John"<<endl;
            }
            else{
                if(ans) cout<<"John"<<endl;
                else cout<<"Brother"<<endl;
            }
        }
    }
    return 0;
}
