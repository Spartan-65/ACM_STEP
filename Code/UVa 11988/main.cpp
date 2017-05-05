#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <cstring>

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using std::cout;
using std::cin;
const int maxn = 100000+5;
int last, cur, next[100005];
char s[maxn];
int main()
{
    while(scanf("%s",s+1)==1)
    {
        int n = strlen(s+1);
        last = cur = 0;
        next[0] = 0;
        for(int i = 1;i<=n;i++)
        {
            char ch = s[i];
            if(ch == '[') cur = 0;
            else if(ch == ']') cur = last;
            else{
                next[i] = next[cur];
                next[cur] = i;
                if(cur == last ) last = i;
                cur = i;
            }
        }
        for(int i = next[0];i != 0;i = next[i])
            printf("%c",s[i]);
        putchar('\n');
    }
    return 0;
}
