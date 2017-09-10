#include <bits/stdc++.h>
using namespace std;
const int maxk=105;
const int maxm=105;
int SG[10005];
int S[maxk];
void getSG(int num)
{
    SG[0]=0;
    for(int i=1;i<=10001;i++)
    {
        bool flag[10005];
        memset(flag,0,sizeof(flag));
        for(int j=0;j<num&&S[j]<=i;j++)
            flag[SG[i-S[j]]]=1;
        int j=0;
        while(flag[j])j++;
        SG[i]=j;
    }
}
void print()
{
    for(int i=0;i<10;i++)
        cout<<SG[i]<<' ';
    cout<<endl;
}
int main()
{
    int k;
    while(~scanf("%d",&k))
    {
        if(k==0) return 0;
        for(int i=0;i<k;i++)
            scanf("%d",&S[i]);
        sort(S,S+k);
        getSG(k);
        //print();
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int ans=0;
            int m;scanf("%d",&m);
            for(int i=0;i<m;i++)
            {
                int temp;scanf("%d",&temp);
                ans^=SG[temp];
            }
            if(ans) cout<<"win!"<<endl;
            else cout<<"lose!"<<endl;
        }
    }
    return 0;
}
