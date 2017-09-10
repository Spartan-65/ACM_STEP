#include <stdio.h>
long long n,sum,t;
int main()
{
while(~scanf("%lld",&n))
{sum=0;
for(int i=1;i<n;i++){scanf("%lld",&t);sum+=t;}
printf("%lld\n",(n*(n+1))/2-sum);
}
}
