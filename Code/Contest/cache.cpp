/*#include <bits/stdc++.h>

using namespace std;

class Person
{
    int x;
public :
    string name;
    string sex;
    int age;
    Person(int x) {this->x = x;}
    Person(){cout<<"who is you father"<<endl; x = 0;}
    void print()
    {
        cout<<"Person Class"<<endl;
    }
    void printx(){cout<<x<<endl;}
};

class Student : public Person
{
    int y;
public :
    Student(int x):Person(x)  {}
    Student():Person(){cout<<"this is student"<<endl;}
    void print()
    {
        cout<<"this is a student";
    }
};

class Teacher : public Student, public Person
{
public :

    Teacher():Person() {cout<<"this is teacher"<<endl;}

};
int main()
{
    Teacher a;
    Student b(2);
    Student c;
    c.printx();
    b.printx();
    return 0;
}*/
/*
#include <bits/stdc++.h>
using namespace std;

class Complex
{
    double r;
    double img;
public :
    Complex(double r = 0, double img = 0)
    {
        this -> r = r;
        this ->img = img;
    }
    Complex operator + (Complex &b)
    {
        return Complex(r+b.r, img+b.img);
    }
    Complex operator - (Complex &b)
    {
        return Complex(r-b.r, img -b.img);
    }
    Complex operator * (Complex &b)
    {
        return Complex(r*b.r-img*b.img, r*b.img+img*b.r);
    }
    void display()
    {
        cout<<r<<"   "<<img<<'i'<<endl;
    }
};
int main()
{
    Complex a(10, 3), b(15, -7), c;
    c = a+b;
    c.display();
    c = a - b;
    c.display();
    c = a*b;
    c.display();
}
*/
