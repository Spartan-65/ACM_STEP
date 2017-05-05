#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str1[105],str2[105],str3[105];
    int a[26]={-1},b[26]={-1};
    bool flag = true;
    cin>>str1>>str2>>str3;
    for(int i = 0;i<26;i++){a[i]=b[i]=-1;}
    for(int i = 0;i<strlen(str1);i++)
    {
        if(a[str1[i]-'A']==-1&&b[str2[i]-'A']==-1)
        {
            a[str1[i]-'A']=str2[i]-'A';
            b[str2[i]-'A']=str1[i]-'A';
        }
        else{
            if(a[str1[i]-'A']!=str2[i]-'A'||b[str2[i]-'A']!=str1[i]-'A')
            {
                flag = false;
                break;
            }
        }
    }

    for(int i = 0;i<26;i++)
        {
            if(a[i]==-1||b[i]==-1) {flag=false;break;}
        }
        if(flag){
            for(int i = 0;i<strlen(str3);i++)
                printf("%c",a[str3[i]-'A']+'A');
        }
        else cout<<"Failed";
        cout<<endl;
    return 0;
}
