#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v[100005]={0};
    int n;
    while(~scanf("%d",&n))
    {
        memset(v,0,sizeof(v));
        for(int i = 0;i<n;i++) {int t;scanf("%d",&t);v[t]++;}
        int cur=0;int sum = 0;int c=0,t=0;
        while(cur<100005)
        {
            if(v[cur]){
                t+=cur;
                v[cur]--;
                c++;
            }
            if(c==2){v[t]+=1;sum+=t;t=c=0;}
            if(!v[cur])cur++;
        }
        //cout<<sum<<endl;
        printf("%d\n",sum);
    }
    return 0;
}
