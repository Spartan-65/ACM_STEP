#include <bits/stdc++.h>
using namespace std;
int ans=0;
void mergarry(int a[],int frist,int mid,int last)
{
	int m=mid,n=last,i=frist,j=mid+1;
	int k=0,c[last-frist+1];
	while(i<=mid&&j<=n)
	{
		if(a[i]<a[j]) c[k++]=a[i++];
		else c[k++]=a[j++],ans+=m-i+1;
	}
	while(i<=m) c[k++]=a[i++];
	while(j<=n) c[k++]=a[j++];
	for(i=0;i<k;i++)
	a[frist+i]=c[i];
	//cout<<"mark"<<endl;
}
void mergsort(int a[],int frist,int last)
{
	//cout<<frist<<' '<<last<<endl;
	if(frist<last)
	{

	//cout<<"mark"<<endl;
		int mid=(frist+last)/2;
		mergsort(a,frist,mid);
		mergsort(a,mid+1,last);
		mergarry(a,frist,mid,last);

	}
}
int main()
{
	int a[400001];
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	mergsort(a,0,n-1);
	//for(int i=0;i<n;i++)cout<<a[i]<<' ';
	//cout<<endl;
	cout<<ans<<endl;
	return 0;
}
