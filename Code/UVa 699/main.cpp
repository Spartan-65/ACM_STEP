#include <bits/stdc++.h>
using namespace std;
const int maxn=10000;
int sum[maxn];
void build(int p)
{
	int v;
	cin>>v;
	if(v==-1) return;
	sum[p]+=v;
	build(p-1);
	build(p+1);
}
bool input()
{
	memset(sum, 0, sizeof(sum));
	int v,p;
	cin>>v;
	if(v==-1) return false;
	p=maxn/2;
	sum[p]=v;
	build(p-1);
	build(p+1);
	return true;
}
int main()
{
	int Count=0;
	while(input())
	{
		int p = 0;
		while(!sum[p]) {p++;}
		cout<<"Case "<<++Count<<":\n"<<sum[p++];
		while(sum[p]) cout<<" "<<sum[p++];
		puts("\n");
	}
	return 0;
}
