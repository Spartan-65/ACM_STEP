#include <bits/stdc++.h>
using namespace std;
int a[20],b[15];
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(b,0,sizeof(b));
        int cnt=0;
        bool flag=true;
        for(int i=0;i<14;i++)
        {
            scanf("%d",&a[i]);
            b[a[i]]++;
        }
        for(int i=1;i<=9;i++)
        {
            if(b[i]>=0)
            {
                int temp[15];
                for(int j=1;j<=11;j++) temp[j]=b[j];
                temp[i]-=2;
                bool check=1;
                for(int j=1;j<=11;j++)
                {
                    if(temp[j]<0)
                    {
                        check=0;
                        break;
                    }
                    temp[j]%=3;temp[j+1]-=temp[j];temp[j+2]-=temp[j];
                }
                if(check)
                {
                    flag=0;
                    break;
                }
            }

        }
        if(flag) cout<<"Immune"<<endl;
        else cout<<"Vulnerable"<<endl;

    }
}
