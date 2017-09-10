#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int s[30000];
    int t,top=0;
    memset(s,0,sizeof(s));
    s[0]=-999999;
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&t);
        if(t>s[top]) s[++top]=t;
        else
        {
            int l=0,h=top;
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(s[mid]<t) l=mid+1;
                else h=mid-1;
            }
            s[l]=t;
        }
    }
    cout<<top<<endl;
    return 0;
}
