#include <bits/stdc++.h>
using namespace std;
const double Pi=3.14159265358979323846;
double R,r,n;
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {

        scanf("%lf%lf",&R,&n);printf("Case %d: ",i);
        double t=2*Pi/n/2;
        t=sin(t);
        //t=t+1;
        printf("%.6lf\n",R*t/(t+1));

    }
    return 0;
}
