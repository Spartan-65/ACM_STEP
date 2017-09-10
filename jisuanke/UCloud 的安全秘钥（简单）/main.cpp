#include <queue>
#include <deque>
#include <iostream>
using namespace std;
deque<int> q;
int main()
{
    for(int i=0;i<10;i++)
        q.push_back(i);
    q.insert(q.begin(),10);
    q.erase(q.begin()+3);
    //int t;
    //t=q.erase(4,4);
    //cout<<t<<endl;
    deque<int>::iterator i;
    for(i=q.begin();i!=q.end();i++)
    {
        cout<<*i<<endl;
    }
}
