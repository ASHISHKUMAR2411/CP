// To show multilevel inheritance 

#include<bits/stdc++.h>
using namespace std;
class A
{
    public:
        void show()
        {
            cout<<"\nA";
        }
};
class B:public A
{
    public:
        void show()
        {
            cout<<"\nB";
        }
};
class C:public B
{
    public:
        void show()
        {
            cout<<"\nC";
        }
};
int main()
{
    C c;
    c.show();
    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// class vehicle
// {
// 	protected:
// 		int speed,cost;
// 	public:
// 		vehicle()
// 		{
// 			speed=0;
// 			cost=0;
// 		}
// 		void set_speed(int s)
// 		{
// 			speed=s;
// 		}
// 		void set_cost(int c)
// 		{
// 			cost=c;
// 		}
// 		int get_speed()
// 		{
// 			return speed;
// 		}
// 		int get_cost()
// 		{
// 			return cost;
// 		}
// };
// class car:public vehicle
// {
//     public:
//         car()
//         {
//             speed=0;
//             cost=0;
//         }
//         void set_speed(int s)
//         {
//             speed=s;
//         }
//         void set_cost(int c)
//         {
//             cost=c;
//         }
//         int get_speed()
//         {
//             return speed;
//         }
//         int get_cost()
//         {
//             return cost;
//         }
// };
// class bike:public vehicle
// {
//     public:
//         bike()
//         {
//             speed=0;
//             cost=0;
//         }
//         void set_speed(int s)
//         {
//             speed=s;
//         }
//         void set_cost(int c)
//         {
//             cost=c;
//         }
//         int get_speed()
//         {
//             return speed;
//         }
//         int get_cost()
//         {
//             return cost;
//         }
// };
// class scooter:public vehicle
// {
//     public:
//         scooter()
//         {
//             speed=0;
//             cost=0;
//         }
//         void set_speed(int s)
//         {
//             speed=s;
//         }
//         void set_cost(int c)
//         {
//             cost=c;
//         }
//         int get_speed()
//         {
//             return speed;
//         }
//         int get_cost()
//         {
//             return cost;
//         }
// };
// int main()
// {
//     car c;
//     bike b;
//     scooter s;
//     c.set_speed(100);
//     c.set_cost(20000);
//     b.set_speed(80);
//     b.set_cost(15000);
//     s.set_speed(50);
//     s.set_cost(10000);
//     cout<<"\nCar Speed: "<<c.get_speed()<<"\nCar Cost: "<<c.get_cost()<<"\nBike Speed: "<<b.get_speed()<<"\nBike Cost: "<<b.get_cost()<<"\nScooter Speed: "<<s.get_speed()<<"\nScooter Cost: "<<s.get_cost();
//     return 0;
// }
// Output:
// Car Speed: 100
// Car Cost: 20000
// Bike Speed: 80
// Bike Cost: 15000
// Scooter Speed: 50
// Scooter Cost: 10000