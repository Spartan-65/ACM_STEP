#include <stdio.h>
int F(int x,int y)
{
    if(x==1||y==1||x==0) return 1;
    if(x<y) return F(x,x);
    return F(x,y-1)+F(x-y,y);
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%d\n",F(n,m));
    }
}
