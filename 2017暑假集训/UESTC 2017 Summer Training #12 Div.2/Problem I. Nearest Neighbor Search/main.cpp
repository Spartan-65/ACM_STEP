#include <bits/stdc++.h>
using namespace std;
int x[3],y[3],z[3];
int main()
{
    for(int i=0;i<3;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
    int a,b,c;
    if(x[0]>=x[1]&&x[0]<=x[2]) a=0;
    else a=min(abs(x[0]-x[1]),abs(x[0]-x[2]));
    if(y[0]>=y[1]&&y[0]<=y[2]) b=0;
    else b=min(abs(y[0]-y[1]),abs(y[0]-y[2]));
    if(z[0]>=z[1]&&z[0]<=z[2]) c=0;
    else c=min(abs(z[0]-z[1]),abs(z[0]-z[2]));
    printf("%d\n",a*a+b*b+c*c);

    return 0;
}
