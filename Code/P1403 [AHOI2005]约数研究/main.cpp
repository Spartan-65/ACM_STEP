#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long sum = 0;
    for(int i = 1;i<=n;i++) sum+=n/i;
    printf("%d\n",sum);
    return 0;
}
