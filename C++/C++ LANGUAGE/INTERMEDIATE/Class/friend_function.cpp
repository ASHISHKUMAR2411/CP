// friend_class_and_member in c++
#include<bits/stdc++.h>
using namespace std;
// a friend class is a class which can access private and protected member
class friend_class
{
    // using friend class to find the area of the rectangle
    private:
        int length;
        int breadth;
    public :
        friend_class(int length,int breadth):length(length),breadth(breadth){}
        friend void calArea(friend_class s);
};
void calArea(friend_class s)
{
    cout<<"\nArea is : "<<(s.length*s.breadth);
}
int main()
{
    friend_class ob(10,20);
    calArea(ob);
    return 0;
}