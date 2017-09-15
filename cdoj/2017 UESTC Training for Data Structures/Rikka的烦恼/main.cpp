#include <bits/stdc++.h>
using namespace std;
const int maxn=7e4+8;
const int K=6;
int val[maxn];
int ans;
struct node{
    int arr[maxn<<2];
    int sz;
    void up(int k)
    {
        arr[k]=max(arr[k<<1],arr[k<<1|1]);
    }
    void modify(int l,int r,int d,int k,int x)
    {
        if(l==d&&r==d)
        {
            arr[k]+=x;
            return;
        }
        int mid=(l+r)>>1;
        if(d<=mid) modify(l,mid,d,k<<1,x);
        else modify(mid+1,r,d,k<<1|1,x);
        up(k);
    }
    void query(int a,int b,int l,int r,int k)
    {
        if(a<=l&&b<=r)
        {
            if(ans==-1e9)
                ans=arr[k];
            else ans=max(ans,arr[k]);
            return ;
        }
        int mid=(l+r)>>1;
        if(a<=mid) query(a,b,l,mid,k<<1);
        if(b>mid) query(a,b,mid+1,r,k<<1|1);
        up(k);
    }
    void mo(int a,int x){modify(1,sz,a,1,x);}
    void qu(int a,int b){query(a,b,1,sz,1);}
}T[K][K];

int main()
{
    //freopen("test.in","r",stdin);
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&val[i]);
    for(int i=1;i<K;i++)
    {
        for(int j=1;j<=i;j++)
        {
            T[i][j].sz=(n-j)/i+1;
            for(int k=0;i*k+j<=n;k++)
            {
                T[i][j].mo(k+1,val[i*k+j]);
            }
        }
    }
    scanf("%d",&m);
    while(m--)
    {
        int op,a,b;scanf("%d%d%d",&op,&a,&b);
        if(op==0)
        {
            val[a]+=b;
            for(int i=1;i<K;i++)
            {
                for(int j=1;j<=i;j++)
                {
                    if((a-j)%i==0){
                        int k=(a-j)/i+1;
                        T[i][j].mo(k,val[a]);
                    }
                }
            }
        }
        else{
            if(b>=K){
                ans=-1e9;
                for(int i=a;i<=n;i+=b)
                {
                    ans=max(ans,val[i]);
                }
                printf("%d\n",ans);
                continue;
            }
            int i=b;
            int j=a%b;
            int k=a/b+1;
            if(!j){j=b;k--;}
            ans=-1e9;
            //cout<<i<<' '<<j<<' '<<k<<endl;
            T[i][j].qu(k,T[i][j].sz);
            printf("%d\n",ans);
        }
    }
    return 0;
}
