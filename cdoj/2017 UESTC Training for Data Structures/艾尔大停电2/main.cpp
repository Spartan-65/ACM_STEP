#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+8;
int T[maxn][maxn];
inline int lowbit(int x){return (x&-x);}
inline void add(int x,int y,int v)
{
    for(int i=x;i<maxn;i+=lowbit(i)){
        for(int j=y;j<maxn;j+=lowbit(j)){
            T[i][j]+=v;
        }
    }
}
inline int get(int x,int y)
{
    int res=0,i,j;
    for(i=x;i;i-=lowbit(i))
    {
        for(j=y;j;j-=lowbit(j))
            res+=T[i][j];
    }
    return res;
}
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int n,t,x1,y1,x2,y2,ans;
    scanf("%d",&t);
    //std::ios::sync_with_stdio(false);
    while(t--)
    {
        memset(T,0,sizeof(T));
        scanf("%d",&n);
        char ch;
        while(n--){
             getchar(); getchar();
            ch = getchar();
            if(ch=='C')
            {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                add(x2+1, y2+1, 1);
                add(x2+1, y1, 1);
                add(x1, y2+1, 1);
                add(x1, y1, 1);
            }
            else{
                scanf("%d%d", &x1, &y1);
                ans = get(x1, y1);
                printf("%d\n", ans % 2);
            }
        }
    }
    return 0;
}
