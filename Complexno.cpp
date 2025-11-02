#include<iostream>
using namespace std;
class Complex {
    float real;
    float img;
    public:
    //Default constructor
    Complex()
    {
        real=0;
        img=0;
    }
    //paramaterized constructor
    Complex(float r,float i)
    {
        real=r;
        img=i;
    }
    //operator overloading addition
    Complex operator+(Complex c){
        return Complex(real+c.real,img+c.img);
    }
    //operator overloading subtraction
    Complex operator-(Complex c){
        return Complex(real-c.real,img-c.img);
    }
    //operator overloading multiplication
    Complex operator*(Complex c){
        return Complex(real*c.real-img*c.img,real*c.img+img*c.real);
    }
    Complex operator/(Complex c)
    {
        float denom=c.real*c.real+c.img*c.img;
        return Complex((real*c.real+img*c.img)/denom,(img*c.real-real*c.img)/denom);
    }
    void accept()
    {
        cin>>real>>img;
    }
    void display()
    {
        if(img>=0)
        cout<<real<<"+"<<img<<"i";
        else{
            cout<<real<<img<<"i";
        }
    }

};
int main()
{
    int choice;
    Complex c1,c2,result;
    do{
        cout<<"\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter First complex no.";
            c1.accept();
            cout<<"Enter Second complex no.";
            c2.accept();
            result=c1+c2;
            cout<<"Addition:";
            result.display();
            cout<<endl;
            break;
            case 2:
            cout<<"Enter First complex no.";
            c1.accept();
            cout<<"Enter Second complex no.";
            c2.accept();
            result=c1-c2;
            cout<<"Subtraction:";
            result.display();
            cout<<endl;
            break;
            case 3:
            cout<<"Enter First complex no.";
            c1.accept();
            cout<<"Enter Second complex no.";
            c2.accept();
            result=c1*c2;
            cout<<"Multiplication:";
            result.display();
            cout<<endl;
            break;
            case 4:
            cout<<"Enter First complex no.";
            c1.accept();
            cout<<"Enter Second complex no.";
            c2.accept();
            result=c1/c2;
            cout<<"Division:";
            result.display();
            cout<<endl;
            break;
            case 5:
            cout<<"Exiting te program";
            break;
            default:
            cout<<"Invalid choice\n";
            break;
        }
    }while(choice!=5);
    return 0;
}