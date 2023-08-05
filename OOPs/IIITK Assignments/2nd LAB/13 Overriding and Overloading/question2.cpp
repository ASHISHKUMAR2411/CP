// Write a C++ program which start with the publication, book and tape classes. Add a base class sale that holds an array of three floats so that it can record the dollar sales of a particular publication for the last three months. Include a getdata( ) function to get three sales amounts from the user and a putdata( ) function to display the sales figures. After the book and tape classes so they are derived from both publication and sales. An object of class book or tape should input and output sales data along with its other data. Write a main ( ) function to create a book object and a tape object and exercise their input/output capabilities.

#include<bits/stdc++.h>
using namespace std;
class publication
{
    protected:
    string title;
    string author;
    string publisher;
    string date;
    public:
    void getdata()
    {
        cout<<"Enter the title of the book: ";
        cin>>title;
        cout<<"Enter the author of the book: ";
        cin>>author;
        cout<<"Enter the publisher of the book: ";
        cin>>publisher;
        cout<<"Enter the date of publication: ";
        cin>>date;
    }
    void putdata()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Publisher: "<<publisher<<endl;
        cout<<"Date of publication: "<<date<<endl;
    }
};
class book:public publication
{
    protected:
    int pages;
    public:
    void getdata()
    {
        publication::getdata();
        cout<<"Enter the number of pages: ";
        cin>>pages;
    }
    void putdata()
    {
        publication::putdata();
        cout<<"Number of pages: "<<pages<<endl;
    }
};
class tape:public publication
{
    protected:
    int length;
    public:
    void getdata()
    {
        publication::getdata();
        cout<<"Enter the length of the tape: ";
        cin>>length;
    }
    void putdata()
    {
        publication::putdata();
        cout<<"Length of the tape: "<<length<<endl;
    }
};
class sale
{
    protected:
    float sales[3];
    public:
    void getdata()
    {
        cout<<"Enter the sales for the last three months: ";
        for(int i=0;i<3;i++)
        {
            cin>>sales[i];
        }
    }
    void putdata()
    {
        cout<<"Sales for the last three months: ";
        for(int i=0;i<3;i++)
        {
            cout<<sales[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    book b;
    tape t;
    sale s;
    b.getdata();
    b.putdata();
    t.getdata();
    t.putdata();
    s.getdata();
    s.putdata();
    return 0;
}
// Output:
// Enter the title of the book: C++ Programming
// Enter the author of the book: B.R.K.
// Enter the publisher of the book: Pearson
// Enter the date of publication: 12/12/2018
// Enter the number of pages: 567
// Title: C++ Programming
// Author: B.R.K.
// Publisher: Pearson
// Date of publication: 12/12/2018
// Number of pages: 567