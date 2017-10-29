#include <bits/stdc++.h>
using namespace std;
int main()
{
    double d[3],a,b,c;
    while(~scanf("%lf%lf%lf",&d[0],&d[1],&d[2]))
    {
        sort(d,d+3);
        a=d[0],b=d[1],c=d[2];
        if(a+b>c)
        {
            if(a==b&&b==c)printf("equilateral triangle\n");
            else if(a==b||b==c||a==c) printf("isosceles triangle\n");
            else if(a*a+b*b==c*c)printf("right triangle\n");
            else printf("general triangle\n");
        }
        else printf("not triangle\n");
    }
    return 0;
}
