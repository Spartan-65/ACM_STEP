#include <iostream>

using namespace std;

int main()
{
    for(int i = 0;i<100;i++)
    {
        int sum = i;
        for(int j = i+1;j<100;j++)
            {
                sum+=j;
                if(sum==236) cout<<i<<endl;

            }
    }

}
