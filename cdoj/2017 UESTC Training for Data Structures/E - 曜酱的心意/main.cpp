#include <bits/stdc++.h>
const int maxn=1e5+10;
long long ans;
long long a[maxn];
int flag[maxn];
void Merge(int l,int mid,int r)
{
    int i=l,j=mid+1,k=0;
    int temp[r-l+1];
    while(i<=mid&&j<=r)
    {
        if(a[i]>a[j])
        {
            temp[k++]=a[j];
            ans+=(mid-i+1);
            j++;
        }
        else {
            temp[k++]=a[i];
            i++;
        }
    }
    while(i<=mid) temp[k++]=a[i++];
    while(j<=r) temp[k++]=a[j++];
    for(int i=0;i<(r-l)+1;i++)
        a[i+l]=temp[i];
}
void Sort(int l,int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    Sort(l,mid);
    Sort(mid+1,r);
    Merge(l,mid,r);
}

int main()
{

    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            int t;scanf("%d",&t);
            flag[t]=i;
        }
        for(int i=0;i<n;i++)
        {
            int t;scanf("%d",&t);
            a[i]=flag[t];
        }
        ans=0;
        Sort(0,n-1);
        printf("%lld\n",ans);
    }
}
