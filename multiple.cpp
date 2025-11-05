#include<iostream>
using namespace std;
class Person{
    protected:
    int age;
    string name;
    public:
    void accept()
    {
        cout<<"Enter Name:";
        cin>>name;
        cout<<"Enter age:";
        cin>>age;
    }
    void display()
    {
        cout<<"\nName:"<<name<<endl;
        cout<<"Age"<<age<<endl;
    }
};
class Employee{
    protected:
    int emp_id;
    float salary;

    public:
    void empaccept(){
        cout<<"enter employee id";
        cin>>emp_id;
        cout<<"enter salary";
        cin>>salary;

    }
    void empdisplay()
    {
        cout<<"Id:"<<emp_id;
        cout<<"\nSalary:"<<salary;

    }
};
class Manager:public Person,public Employee{
    string department;
    public:
    void manaccept(){
        accept();
        empaccept();
        cout<<"enter the department";
        cin>>department;

    }
    void mandisplay()
    {  cout<<"\n-----manager details-----";
        display();
        empdisplay();
        cout<<"\nDepartment:"<<department;
    }

};
int main()
{
    Manager m;
    m.manaccept();
    m.mandisplay();
    return 0;
}