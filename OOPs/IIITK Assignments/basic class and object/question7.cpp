#include<iostream>
using namespace std;
// The below class can be used in classrooms fo roll number purpose 
// First We don't give them roll number directly Either We give them roll number of a student who left i.e copy constructor 
// Or we can initialize a new roll number to the student giving the required roll number . 
class Constructor{
    static int roll_no;
    string name;
public:
    Constructor(){
        roll_no++;
        name = "No Name Given";
    }
    Constructor(int roll , string Name){
        roll_no = roll;
        name = Name;
    }
    Constructor(const Constructor &Stu){
        roll_no = Stu.roll_no;
        name = Stu.name;
    }
    void Show(){
        cout<<"Roll No : "<<roll_no<<" Name : "<<name<<endl;
    }
};

int Constructor :: roll_no = 0;

int main(){
    Constructor c1;
    cout<<" Default Constructor : ";
    c1.Show();
    Constructor c2(c1);
    cout<<" Copy constructor : ";
    c2.Show();
    cout<<" Parameterized Constructor : ";
    Constructor c3(1008,"Ashish Kumar");
    c3.Show();
}