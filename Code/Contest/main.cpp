#include <fstream>
#include <iostream>
using namespace std;

class Student
{
    string name;
    string sno;
public :
    Student (string name , string sno): name(name),sno(sno) {}
    void setName(string name){ this -> name = name; }
    string  getName() { return name; }
};

int main()
{
    string name , sno;
    ofstream out("test.txt");

    while(cin>>name>>sno)
    {
        if(name[0]=='#') break;
        out<<name<<' '<<sno<<endl;
    }
    out.close();
    ifstream in("test.txt");
    string a, b;
    while(in>>a>>b)
    {
        cout<<a<<' '<<b<<endl;
    }
    out.close();
    return 0;
}
