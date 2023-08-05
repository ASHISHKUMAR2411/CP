// Write a C++ Program to illustrates how constructor are implemented when the classes are inherited
#include<bits/stdc++.h>
using namespace std;
class Health
{
    public:
        int age;
        float height, weight;
        string name;
        Health()
        {
            cout<<"Enter Your Details When Asked "<<endl;
            cout << "Enter your Name : ";
            getline(cin, name);
            cout<<"Enter "<<name<<"'s age : ";
            cin >> age;
            AgainHeight:
            cout<<"Enter "<<name<<"'s height in meter : ";
            cin >> height;
            if(height > 2.5){
                cout << endl;
                cout << "Please Enter your height in meter like 1.62 for 162cm " << endl;
                goto AgainHeight;
            }
            cout<<"Enter "<<name<<"'s weight in Kg : ";
            cin >> weight;
        }
};


class BMI : public Health
{
    public:
        float bmi;
        BMI()
        {
            cout << endl;
            cout<<"Now lets Talk About Your BMI i.e fitness "<<endl;
            bmi = weight / (height * height);
            cout << "BMI of " << name << " is " << bmi << endl;
            cout << "You are ";
            if(bmi < 18.5)
                cout << "Underweight, We need to take care to put up some weight";
            else if(bmi >= 18.5 && bmi <= 24.9)
                cout << "Normal Keep it up, Just Do whatever you are doing.";
            else if(bmi >= 25 && bmi <= 29.9)
                cout << "Overweight, We need to take care of health and do put down some weights";
            else
                cout << "Obese, We have to take it seriously and Immediately work out to put down weight";
        }
};

class BloodCheck : public BMI
{
    public:
        float hb;
        BloodCheck()
        {
            cout << endl;
            cout << "Now let's check blood pressure" << endl;
            hb = bmi * 6.02;
            cout << "Hb of " << name << " is " << hb << " mg/dl" << endl;
            cout << "You are ";
            if(hb > 150)
                cout << "High Blood Pressure, We need to take care of health and do put down some weights";
            else if(hb < 100)
                cout << "Low Blood Pressure, We need to take care to put up some weight";
            else
                cout << "Normal, Keep it up, Just Do whatever you are doing.";
        }
};

int main()
{
    BloodCheck b;
    return 0;
}
// Output:
// Enter Your Details When Asked
// Enter your Name : Abhishek
// Enter Abhishek's age : 22
// Enter Abhishek's height in meter : 1.72
// Enter Abhishek's weight in Kg : 70
//
// Now lets Talk About Your BMI i.e fitness
// BMI of Abhishek is 22.5
// You are Normal Keep it up, Just Do whatever you are doing.
//
// Now let's check blood pressure
// Hb of Abhishek is 7.5 mg/dl
// You are Normal, Keep it up, Just Do whatever you are doing.
//
// Process returned 0 (0x0)   execution time : 0.064 s
