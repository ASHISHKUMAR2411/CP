// here we will keep track on how the static data member works ..
// ? static data member of a class is shared among all data objects and it is shared exactly in the state it is currently . it will be more clear when we will code it .


// ? Static Data Member Functions are function which will only call static member and other static function and any other function outside class , and it cannot use this pointer of any class , they can be accessed by the name of the classes.   

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define MAX 1000000 
using namespace std;

// lets keep track of how many object of the class are created .. it can be used to keep track how many new user have been using our application ...
class StaticMemberBehaviour
{
private:
    /* data */
public:
    string name;
    static int count;
    StaticMemberBehaviour()
    {
        count++;
        cout<<"Number of objects are : "<<count<<endl;
    }
};
class UseStatic
{
    private :
        static StaticMemberBehaviour ob;
    public:
        UseStatic() { cout<<"showing how static member is shared among objects of the class  "<<endl;}
        static StaticMemberBehaviour getMember() { return ob;}
};
//  static member  must be explicitly defined outside the class using scope resolution operator. 
int StaticMemberBehaviour::count=0;

// we have to define it outside so that we can access the static object from other class otherwise it will give errors ...
StaticMemberBehaviour UseStatic :: ob;
int main(int argc, char const *argv[])
{
    fast;
    // UseStatic obj , b , c ;
    StaticMemberBehaviour object1 = UseStatic::getMember();
    return 0;
}

