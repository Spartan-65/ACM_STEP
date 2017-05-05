#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a;
    int b;
    while(~scanf("%lf%d",&a,&b))
    {
        double h=a,sum=a;
        for(int i = 0;i<b;i++)
        {
            sum+=h;
            h/=2;
        }
        printf("%.2lf %.2lf\n",h,sum-2*h);
    }
    return 0;
}
