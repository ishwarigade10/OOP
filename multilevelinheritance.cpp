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
class Employee:public Person{
    protected:
    int emp_id;
    float salary;
    public:
    void empaccept(){
        accept();
        cout<<"enter emp id:";
        cin>>emp_id;
        cout<<"Enter the salary";
        cin>>salary;
    }
    void empdisplay(){
        display();
        cout<<"EWmp id:"<<emp_id;
        cout<<"\nSalary:"<<salary;
    }
};
class Manager:public Employee{
    string department;
    float bonus;
    public:
    void man_accept(){
        empaccept();
        cout<<"Enter department name:";
        cin>>department;
        cout<<"Enter the bonus";
        cin>>bonus;
    }
    void mandisplay()
    {
        cout<<"\n-----manager details-----";
        empdisplay();
        cout<<"\nDepartment:"<<department;
        cout<<"\nBonus:"<<bonus;
    }
};
int main()
{
    Manager m;
    
    m.man_accept();
    m.mandisplay();
    return 0;
}
