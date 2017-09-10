#include <bits/stdc++.h>
using namespace std;
int n;
double a,b,c,d;
int main()
{
    while(~scanf("%d",&n))
    {
        while(n--){
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            //cout<<a<<' '<<b<<' '<<' '<<c<<' '<<d<<endl;
            if(b==d){
                double t=13-a;
                double avg=0.5/t;
                double ans=avg*(c-a);
                printf("%.4lf\n",ans);
            }
            else{
                    double ans=0.5;
                    ans+=(d-b-1);
                    double avg=1.0/12;
                    ans+=(c-1)*avg;
                    printf("%.4lf\n",ans);
            }
        }
    }
    return 0;
}
