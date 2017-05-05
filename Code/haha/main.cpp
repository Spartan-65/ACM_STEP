#include <stdio.h>
int deal(int a, int b)
{ return a%b?deal(b, a%b):a; }
int main()
{
    int a, b;
    while(~scanf("%d%d",&a, &b))
    {
        int x = deal(a, b);
        printf("%d\n%d\n",x,a*b/x);

    }

}
