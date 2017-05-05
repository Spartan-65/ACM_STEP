#include <bits/stdc++.h>

using namespace std;
int a[10005];
int main()
{
    int n, num;
    while(~scanf("%d",&n))
    {
        scanf("%d",&num);
        for(int i = 0;i<n;i++) scanf("%d",&a[i]);
        int Count=0;
        do{

            if(Count==num) break;Count++;
        }while(next_permutation(a,a+n));
        for(int i = 0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
