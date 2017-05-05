#include <bits/stdc++.h>
using namespace std;
const int maxn = 260;
char s[20];
bool failed = true;
struct node
{
    bool have_value;
    int v;
    node *left, *right;
    node():have_value(false),left(NULL),right(NULL){}
};
node* newnode() { return new node(); }
node* root;
void addnode(int v, char* s)
{
    int n = strlen(s);
    node* u = root;
    for(int i = 0;i<n;i++)
    {
        if(s[i]=='L'){
            if(u->left==NULL) u -> left = newnode();
            u = u->left;
        }else if(s[i]=='R'){
            if(u -> right==NULL) u -> right = newnode();
            u = u->right;
        }
    }
    if( u->have_value) failed = true;
    u->v = v;
    u->have_value = true;
    u->v = v;
}
void remove_tree(node* u)
{
    if(u == NULL) return ;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}
bool input()
{
    int v;
    failed = false;
    remove_tree(root);
    root = newnode();
    while(1)
    {
        if(scanf("%s",s) != 1) return false;
        if(!strcmp(s,"()")) break;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',')+1);
    }
    return true;
}
vector<int> ans;
bool bfs(vector<int>& ans)
{
    queue<node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty())
    {
        node* u = q.front(); q.pop();
        if(!u->have_value) return false;
        ans.push_back(u->v);
        if(u->left) q.push(u->left);
        if(u->right) q.push(u->right);
    }
    return true;
}
int main()
{
    while(input())
    {
        if(bfs(ans)&&failed == false)
        {
            vector<int>::iterator i = ans.begin();
            for(;(i+1)!= ans.end();++i)
                printf("%d ",*i);
            printf("%d\n",*i);
        }
        else printf("not complete\n");
    }
    return 0;
}
