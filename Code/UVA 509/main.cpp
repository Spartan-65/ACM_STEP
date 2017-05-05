#include <bits/stdc++.h>
using namespace std;
char data[7][7500];
int d, s, b;
char ch;
bool f()
{
    for(int i = 0;i<s*b;i++)
    {
        int sum = 0, x = -1;
        for(int j = 0;j<d;j++)
        {
            if(data[j][i] == '1' ) sum++;
            if(data[j][i] == 'x') {if(x != -1) return false;x = j;}
        }
        sum = sum&1;
        if(ch=='E')
        {
            if(x!=-1) data[x][i] = sum?'1':'0';
            else if(sum) return false;
        }
        else{
            if(x!=-1) data[x][i] = sum?'0':'1';
            else if(!sum) return false;
        }
    }
    return true;
}

void print(bool flag)
{
    if(!flag) {cout<<"invalid."<<endl; return;}
    cout<<"valid, contents are: ";
    unsigned sum = 0, Count = 0;
    for(int i = 0;i<b;i++)
    {
        for(int j = 0;j<d;j++)
        {
            if(j==i%d) continue;
            for(int k = i*s;k<i*s+s;k++)
            {
                Count++;
                sum<<=1;
                if(data[j][k]=='1') sum +=1;
                if(Count==4) {printf("%X",sum);sum = Count =0;}
            }
        }
    }
    if(Count) { sum<<=(4-Count); printf("%X",sum);  }
    putchar('\n');
}

int main()
{
    int Count = 1;
    while(cin>>d)
    {
        if(!d) return 0;
        memset(data,'\0',sizeof(data));
        cin>>s>>b>>ch;
        for(int i = 0;i<d;i++) cin>>data[i];
        printf ("Disk set %d is ",Count++);
        print(f());
    }
    return 0;
}

