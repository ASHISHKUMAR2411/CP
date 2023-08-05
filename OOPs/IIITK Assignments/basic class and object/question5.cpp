#include <iostream>
using namespace std;

class ElectricityBill
{
private:
    int customer_id;
    char customer_name[100];
    int no_of_units;
    double billAmount;

public:
    void get()
    {
        cout << "Enter Details of Customer Below :: \n"<< endl;
        cout << "Enter Customer No. :: ";
        cin >> customer_id;
        cout << "\nEnter Customer Name :: ";
        cin >> customer_name;
        cout << "\nEnter No. of Units used :: ";
        cin >> no_of_units;
    }

    void put()
    {
        cout << "\nEntered Details of Customer are :: " << endl;
        cout << "\nCustomer No. is : " << customer_id;
        cout << "\n\nCustomer Name is : " << customer_name;
        cout << "\n\nNumber of Units Consumed : " << no_of_units;
        cout << "\n\nBill of Customer : " << billAmount;
    }

    void calc_bill(double chargePerUnit)
    {
        billAmount = no_of_units * chargePerUnit;
    }
};

int main()
{
    ElectricityBill b1;
    b1.get();
    double chargePerUnit ;
    cout<<" enter the charge perUnit : ";
    cin>>chargePerUnit;
    b1.calc_bill(chargePerUnit);
    b1.put();

    cout << "\n";

    return 0;
}
