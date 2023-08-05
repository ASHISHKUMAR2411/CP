// Create a class publication that stores the title (a string) and price(type float) of publication.From this class derive two classes : book, which adds a page count(type int); and tape, which adds a playing time in minutes(type float).Each of these three classes should have a getdata() function to get its data from the user at the keyboard and a putdata() function to display its data. Write a main() program to test the book and tape classes by creating instance of them, asking the user to fill in data with getdata() and then displaying data with putdata().
#include<bits/stdc++.h>
using namespace std;

class publication
{
    string title;
    float price;
    public:
    void getdata()
    {
        cout<<"Enter the title of the publication: ";
        getline(cin,title);
        cout<<"Enter the price of the publication: ";
        cin>>price;
    }
    void putdata()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

class book:public publication
{
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
    float playtime;
    public:
    void getdata()
    {
        publication::getdata();
        cout<<"Enter the playing time in minutes: ";
        cin>>playtime;
    }
    void putdata()
    {
        publication::putdata();
        cout<<"Playing time: "<<playtime<<endl;
    }
};

int main()
{
    book b;
    tape t;
    cout<<"Enter the Book Publication : "<<endl;
    b.getdata();
    cout<<endl;
    cout<<"Enter the Tape Publication : "<<endl;
    t.getdata();
    cout<<endl;
    cout<<"Details of the Book : "<<endl;
    b.putdata();
    cout<<"Details of the tape : "<<endl;
    t.putdata();
    return 0;
}

// Output:
// Enter the title of the publication: The Alchemist
// Enter the price of the publication: 200
// Enter the number of pages: 400
// Enter the playing time in minutes: 200
// Title: The Alchemist
// Price: 200
// Number of pages: 400
// Playing time: 200
// 