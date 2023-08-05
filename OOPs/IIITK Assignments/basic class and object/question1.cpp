#include<bits/stdc++.h>
using namespace std;
class FirstClass{
    public:
        int id;
        string name;
};

int main(){
    FirstClass object1;
    cout<<"Enter the ID : "<<endl;
    cin>>object1.id;
    cout<<"Enter the name : "<<endl;
    cin>>object1.name;
    cout<<endl;
    cout<<"The ID is : "<<object1.id<<" and NAME is : "<<object1.name<<endl;
    return 0;
}