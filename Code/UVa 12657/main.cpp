#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

int right[100005], left[100005];
void Link(int L, int R){
    right[L] = R; left[R] = L;
}
int main()
{
    int m, kase = 0, n;
    while(scanf("%d%d",&n, &m)==2){
        for(int i = 1;i<=n;i++){
            left[i] = i-1;
            right[i] = (i+1)%(n+1);
        }
        right[0] = 1; left [0] = n;
        int op, x, y, inv = 0;
        while(m--)
        {
            scanf("%d", &op);
            if(op == 4) inv = !inv;
            else {
                scanf("%d%d",&x, &y);
                if(op == 3&&right[y]==x) std::swap(x, y);
                if(op !=3&&inv) op = 3-op;
                if(op == 1 && x == left[y]) continue;
                if(op == 2 && x == right[y]) continue;
                int lx = left[x], rx = right[x], ly = left[y], ry = right[y];
                if(op == 1) {
                    Link(lx, rx); Link(ly, x); Link(x, y);
                }
                else if(op == 2){
                    Link(lx, rx); Link(y, x); Link(x, ry);
                }
                else if(op == 3){
                    if(right[x] == y) { Link(lx, y); Link(y, x); Link(x, ry); }
                    else { Link(lx, y); Link(y, rx); Link(ly, x); Link (x, ry); }
                }
            }
        }
        int b = 0;
        long long ans = 0;
        for(int i = 1;i<=n;i++){
            b = right[b];
            if(i&1) ans += b;
        }
        if(inv && n%2 == 0 ) ans = (long long)n*(n+1)/2 - ans;
        printf("Case %d: %lld\n", ++kase, ans);
    }
    return 0;
}
