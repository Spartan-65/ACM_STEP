#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
}arr[5001];
bool cmp(node a,node b)
{
    return a.y<b.y;
}
int main()
{
    int n,s;
    while(~scanf("%d%d",&n,&s))
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int h= a+b;
        for(int i = 0;i<n;i++)
            scanf("%d%d",&arr[i].x,&arr[i].y);
        sort(arr,arr+n,cmp);
        int sum=0,p=0,Count=0;
        while(sum<s)
        {
            if(sum+arr[p].y>s) break;
            if(arr[p].x<=h)
            {
                sum+=arr[p].y;
                Count++;
            }
            p++;
        }
        printf("%d\n",Count);
    }
    return 0;
}
