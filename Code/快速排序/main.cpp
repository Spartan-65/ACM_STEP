#include <bits/stdc++.h>
using namespace std;

int temp[100010];
void Qsort(int s[],int l, int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    Qsort(s,l,mid);
    Qsort(s,mid+1,r);
    int i=l,j=mid+1,c=0;
    while(i<=mid&&j<=r)
    {
        if(s[i]<s[j]) temp[c++]=s[i++];
        else temp[c++]=s[j++];
    }
    if(i<=mid) temp[c++]=s[i++];
    if(j<=r) temp[c++]=s[j++];
    for(int i = 0;i<c;i++)
        s[i+l]=temp[i];
}
int main()
{
    int n;
    //freopen("testdata.in","r",stdin);
    while(~scanf("%d",&n))
    {
        int a[n];
        for( int i = 0;i<n;i++)
            scanf("%d",&a[i]);
        Qsort(a,0,n-1);
        for(int i = 0;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
