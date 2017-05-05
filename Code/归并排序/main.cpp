#include <bits/stdc++.h>
using namespce std;

void merge_sort(int a[],int frist,int mid,int last)
{
    int temp[last-frist+1];
    int m=mid ,n=last;
    int i = frist,j = mid+1;
    int k = 0;
    while(i<=m&&j<=n)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    while(i<=m)
    temp[k++]=a[i++];
    while(j<=n) temp[k++]=a[j++];

}
int main()
{


    return 0;
}
