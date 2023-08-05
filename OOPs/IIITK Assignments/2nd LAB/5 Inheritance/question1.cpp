// To demonstrate the use of inheritance in C++
// Lets suppose,In a School we have three section in Class 10th , Let the section be A,B,C
// And we want to find the grade for each student of class 10th 
// As marking will be same for all student, so we can use same method for all student
// Instead of finding for each class we can Define a method and use in all section of the class
// Lets say we want to find the grade for each student of class 10th

#include<bits/stdc++.h>
using namespace std;

class Class10th
{
    public:
    int rollno;
    string name;
    float marks;
    void getdata()
    {
        cout<<"Enter the rollno: ";
        cin >> rollno;
        cout<<"Enter the name of the student : ";
        cin >> name;
        cout << "Enter the marks of student : ";
        cin >> marks;
    }
    int getGrade(float marks)
    {
        if(marks>=80)
        {
            return 10;
        }
        else if(marks>=70)
        {
            return 9;
        }
        else if(marks>=60)
        {
            return 8;
        }
        else if(marks>=50)
        {
            return 7;
        }
        else if(marks>=40)
        {
            return 6;
        }
        else if(marks>=30)
        {
            return 5;
        }
        else
        {
            return 4;
        }
    }
};

class SectionA : public Class10th
{
	public:
		void display()
		{
            cout << "Rollno:" << rollno << "\nName:" << name << "\nMarks" << marks << endl;
            cout<<"The grade of student is : "<<getGrade(marks)<<endl;
		}
};

class SectionB : public Class10th
{
    public:
        void display()
        {
            cout << "Rollno:" << rollno << "\nName:" << name << "\nMarks" << marks << endl;
            cout<<"The grade of student is : "<<getGrade(marks)<<endl;
        }
};

class SectionC : public Class10th
{
    public:
        void display()
        {
            cout << "Rollno:" << rollno << "\nName:" << name << "\nMarks" << marks << endl;
            cout<<"The grade of student is : "<<getGrade(marks)<<endl;
        }
};

int main()
{
    vector<SectionA> A;
    vector<SectionB> B;
    vector<SectionC> C;
    int nA,nB,nC;
    cout<<"Enter the number of students in section A : ";
    cin>>nA;
    cout<<"Enter the number of students in section B : ";
    cin>>nB;
    cout<<"Enter the number of students in section C : ";
    cin>>nC;
    cout<<" Enter the data for SectionA : "<<endl;
    for(int i=0;i<nA;i++)
    {
        SectionA s;
        s.getdata();
        A.push_back(s);
    }
    cout<<" Enter the data for SectionB : "<<endl;
    for(int i=0;i<nB;i++)
    {
        SectionB s;
        s.getdata();
        B.push_back(s);
    }
    cout<<" Enter the data for SectionC : "<<endl;
    for(int i=0;i<nC;i++)
    {
        SectionC s;
        s.getdata();
        C.push_back(s);
    }
    cout<<" Display the data for SectionA : "<<endl;
    for(int i=0;i<nA;i++)
    {
        A[i].display();
        cout<<endl;
    }
    cout<<" Display the data for SectionB : "<<endl;
    for(int i=0;i<nB;i++)
    {
        B[i].display();
        cout<<endl;
    }
    cout<<" Display the data for SectionC : "<<endl;
    for(int i=0;i<nC;i++)
    {
        C[i].display();
        cout<<endl;
    }


    // In this way we can also find the highest marks scored by a student, and also find how many students get particular grade , Find topper of the batch and section respectively 
    cout<<endl;
    cout<<endl;
    cout<<"Highest marks scored by a student : "<<endl;

    float score = 0,max = 0;
    int j = 0,sec = 0,k;
    for(int i=0;i<nA;i++){
        if(A[i].marks>score){
            score = A[i].marks;
            j = i;
        }
    }
    k = j;
    cout<<"The highest marks scored by "<<A[j].name<<" in Section A is : "<<score<<endl;
    max = score;
    for(int i=0;i<nB;i++){
        if(B[i].marks>score){
            score = B[i].marks;
            j = i;
        }
    }
    cout<<"The highest marks scored by "<<B[j].name<<" in Section B is : "<<score<<endl;
    if(score>max){
        max = score;
        sec = 1;
        k = j;
    }
    for(int i=0;i<nC;i++){
        if(C[i].marks>score){
            score = C[i].marks;
            j = i;
        }
    }
    cout<<"The highest marks scored by  "<<C[j].name<<" in Section C is : "<<score<<endl;
    if(score>max){
        max = score;
        sec = 2;
        k = j;
    }
    cout<<"The topper of the batch is : ";
    if(sec==1){
        cout<<B[k].name<<endl;
    }
    else if(sec==2){
        cout<<C[k].name<<endl;
    }
    else{
        cout<<A[k].name<<endl;
    }
    return 0;
}
// Output :
// Enter the number of students in section A : 5
// Enter the number of students in section B : 5
// Enter the number of students in section C : 5
// Enter the data for SectionA :
// Enter the rollno: 1  
// Enter the name of the student : A
// Enter the marks of student : 90
// Enter the rollno: 2
// Enter the name of the student : B
// Enter the marks of student : 80
// Enter the rollno: 3
// Enter the name of the student : C
// Enter the marks of student : 70
// Enter the rollno: 4
// Enter the name of the student : D
// Enter the marks of student : 60
// Enter the rollno: 5
// Enter the name of the student : E
// Enter the marks of student : 50
// Enter the data for SectionB :
// Enter the rollno: 6
// Enter the name of the student : F
// Enter the marks of student : 40
// Enter the rollno: 7
// Enter the name of the student : G
// Enter the marks of student : 30
// Enter the rollno: 8
// Enter the name of the student : H
// Enter the marks of student : 20
// Enter the rollno: 9
// Enter the name of the student : I
// Enter the marks of student : 10
// Enter the data for SectionC :
// Enter the rollno: 10
// Enter the name of the student : J
// Enter the marks of student : 90
// Enter the rollno: 11
// Enter the name of the student : K
// Enter the marks of student : 80
// Enter the rollno: 12
// Enter the name of the student : L
// Enter the marks of student : 70
// Enter the rollno: 13
// Enter the name of the student : M
// Enter the marks of student : 60
// Enter the rollno: 14
// Enter the name of the student : N
// Enter the marks of student : 50
// Enter the rollno: 15
// Enter the name of the student : O
// Enter the marks of student : 40
// Enter the rollno: 16
// Enter the name of the student : P
// Enter the marks of student : 30
// Enter the rollno: 17
// Enter the name of the student : Q
// Enter the marks of student : 20
// Enter the rollno: 18
// Enter the name of the student : R
// Enter the marks of student : 10
// Display the data for SectionA :
// The rollno of student A is : 1
// The name of the student A is : A
// The marks of student A is : 90
// The rollno of student B is : 2
// The name of the student B is : B
// The marks of student B is : 80
// The rollno of student C is : 3
// The name of the student C is : C
// The marks of student C is : 70
// The rollno of student D is : 4
// The name of the student D is : D
// The marks of student D is : 60
// The rollno of student E is : 5
// The name of the student E is : E
// The marks of student E is : 50
// Display the data for SectionB :
// The rollno of student F is : 6
// The name of the student F is : F
// The marks of student F is : 40
// The rollno of student G is : 7
// The name of the student G is : G
// The marks of student G is : 30
// The rollno of student H is : 8
// The name of the student H is : H
// The marks of student H is : 20
// The rollno of student I is : 9
// The name of the student I is : I
// The marks of student I is : 10
// Display the data for SectionC :
// The rollno of student J is : 10
// The name of the student J is : J
// The marks of student J is : 90
// The rollno of student K is : 11
// The name of the student K is : K
// The marks of student K is : 80
// The rollno of student L is : 12
// The name of the student L is : L
// The marks of student L is : 70
// The rollno of student M is : 13
// The name of the student M is : M
// The marks of student M is : 60
// The rollno of student N is : 14
// The name of the student N is : N
// The marks of student N is : 50
// The rollno of student O is : 15
// The name of the student O is : O
// The marks of student O is : 40
// The rollno of student P is : 16
// The name of the student P is : P
// The marks of student P is : 30
// The rollno of student Q is : 17
// The name of the student Q is : Q
// The marks of student Q is : 20
// The rollno of student R is : 18
// The name of the student R is : R
// The marks of student R is : 10
// The highest marks scored by A in Section A is : 90
// The highest marks scored by B in Section B is : 80
// The highest marks scored by C in Section C is : 70
// The topper of the batch is : A
//
// Process returned 0 (0x0)   execution time : 0.064 s




