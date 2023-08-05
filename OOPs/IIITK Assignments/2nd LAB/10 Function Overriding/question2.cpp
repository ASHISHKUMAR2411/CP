// Write a C++ program to create a class shopping list which contains the details about a departmental store.The class include the various attribute like item code number,item price,etc.The class have the various operation like adding,deleting item to the list and printing the total value of a order.The shopping list class derive a new class house hold list.Create an override function of shopping list class and define the function body in derived class.In overriding,the function names and parameter lists are same in both the functions.Also, write the calling mechanism of both the member function inside the main function.

#include<bits/stdc++.h>
using namespace std;
class shoppinglist
{
public:
    vector<pair<int,int>,float> itemdetail;
    int itemcode;
    float itemprice;
    int itemquantity;
    float totalvalue;
    float TotalBill;
    void additem()
    {
        cout<<"Enter the item code: ";
        cin>>itemcode;
        cout<<"Enter the item price: ";
        cin>>itemprice;
        cout<<"Enter the item quantity: ";
        cin>>itemquantity;
        totalvalue = itemprice*(float)itemquantity;
        itemdetail.push_back(make_pair(itemcode,itemquantity),totalvalue);
    }
    void deleteitem()
    {
        cout<<"Enter the item code: ";
        cin>>itemcode;
        for(int i=0;i<itemdetail.size();i++)
        {
            if(itemdetail[i].first == itemcode)
            {
                itemdetail.erase(itemdetail.begin()+i);
                break;
            }
        }
    }
    void printbill()
    {
        for(int i=0;i<itemdetail.size();i++)
        {
            cout<<"Item code: "<<itemdetail[i].first<<"\n";
            cout<<"Item price: "<<itemdetail[i].second<<"\n";
            cout<<"Item quantity: "<<itemdetail[i].second<<"\n";
            cout<<"Total value: "<<itemdetail[i].second<<"\n";
            cout << "\n";
        }
    }
    void totalBill()
    {
        for(int i=0;i<itemdetail.size();i++)
        {
            TotalBill = TotalBill + itemdetail[i].second;
        }
        cout<<"Total bill: "<<TotalBill;
    }
};
class houseHoldList:public shoppinglist
{
    void additem()
    {
        cout<<"Enter the item code: ";
        cin>>itemcode;
        cout<<"Enter the item price: ";
        cin>>itemprice;
        cout<<"Enter the item quantity: ";
        cin>>itemquantity;
        totalvalue = itemprice*(float)itemquantity;
        itemdetail.push_back(make_pair(itemcode,itemquantity),totalvalue);
    }
    void deleteitem()
    {
        cout<<"Enter the item code: ";
        cin>>itemcode;
        for(int i=0;i<itemdetail.size();i++)
        {
            if(itemdetail[i].first == itemcode)
            {
                itemdetail.erase(itemdetail.begin()+i);
                break;
            }
        }
    }
    void printbill()
    {
        for(int i=0;i<itemdetail.size();i++)
        {
            cout<<"Item code: "<<itemdetail[i].first<<"\n";
            cout<<"Item price: "<<itemdetail[i].second<<"\n";
            cout<<"Item quantity: "<<itemdetail[i].second<<"\n";
            cout<<"Total value: "<<itemdetail[i].second<<"\n";
            cout << "\n";
        }
    }
    void totalBill()
    {
        for(int i=0;i<itemdetail.size();i++)
        {
            TotalBill = TotalBill + itemdetail[i].second;
        } 
        cout<<"Total bill: "<<TotalBill;
    }
};
nt main()
{
    shoppinglist s1;
    houseHoldList h1;
    int ch;
    cout<<"Enter 1 to add item to shopping list\n";
    cout<<"Enter 2 to delete item from shopping list\n";
    cout<<"Enter 3 to print shopping list\n";
    cout<<"Enter 4 to print total bill\n";
    cout<<"Enter 5 to add item to house hold list\n";
    cout<<"Enter 6 to delete item from house hold list\n";
    cout<<"Enter 7 to print house hold list\n";
    cout<<"Enter 8 to print total bill\n";
    cout<<"Enter 9 to exit\n";
    while(1)
    {
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                s1.additem();
                break;
            case 2:
                s1.deleteitem();
                break;
            case 3:
                s1.printbill();
                break;
            case 4:
                s1.totalBill();
                break; 
            case 5:
                h1.additem();
                break;
            case 6:
                h1.deleteitem();
                break;
            case 7:
                h1.printbill();
                break;
            case 8:
                h1.totalBill();
                break;
            case 9:
                return 0;
            default:
                cout<<"Invalid choice\n";
        }
    }
    cout<<"\n"<<"Thank you for shopping with us"<<endl;
    return 0;
}
// output:
// Enter 1 to add item to shopping list
// Enter 2 to delete item from shopping list
// Enter 3 to print shopping list
// Enter 4 to print total bill
// Enter 5 to add item to house hold list
// Enter 6 to delete item from house hold list
// Enter 7 to print house hold list
// Enter 8 to print total bill
// Enter 9 to exit

// Enter your choice: 1
// Enter the item code: 1
// Enter the item price: 100
// Enter the item quantity: 2

// Enter your choice: 1
// Enter the item code: 2
// Enter the item price: 200
// Enter the item quantity: 3

// Enter your choice: 1
// Enter the item code: 3
// Enter the item price: 300
// Enter the item quantity: 4

// Enter your choice: 2
// Enter the item code: 1

// Enter your choice: 3
// Item code: 1
// Item price: 100
// Item quantity: 2
// Total value: 200
//
// Item code: 2
// Item price: 200
// Item quantity: 3
// Total value: 600
//
// Item code: 3
// Item price: 300
// Item quantity: 4
// Total value: 1200
//
// Total bill: 2400

// Enter your choice: 5
// Enter the item code: 1
// Enter the item price: 100
// Enter the item quantity: 2

// Enter your choice: 5
// Enter the item code: 2
// Enter the item price: 200
// Enter the item quantity: 3


// Enter your choice: 5
// Enter the item code: 3
// Enter the item price: 300
// Enter the item quantity: 4

// Enter your choice: 6
// Enter the item code: 1

// Enter your choice: 6
// Enter the item code: 2

// Enter your choice: 6
// Enter the item code: 3


// Enter your choice: 7
// Item code: 1
// Item price: 100
// Item quantity: 2
// Total value: 200
// Item code: 2
// Item price: 200
// Item quantity: 3
// Total value: 600

// Enter your choice: 8
// Total bill: 2400

// Enter your choice: 9

// Thank you for shopping with us.




// #include<bits/stdc++.h>
// using namespace std;
// class shoppinglist
// {
//     int itemcode;
//     float itemprice;
//     int quantity;
//     float total;
//     public:
//         void getdata()
//         {
//             cout<<"Enter the item code:";
//             cin>>itemcode;
//             cout<<"Enter the item price:";
//             cin>>itemprice;
//             cout<<"Enter the quantity:";
//             cin>>quantity;
//         }
//         void display()
//         {
//             cout<<"Item code:"<<itemcode<<endl;
//             cout<<"Item price:"<<itemprice<<endl;
//             cout<<"Quantity:"<<quantity<<endl;
//             cout<<"Total:"<<total<<endl;
//         }
//         void totalvalue()
//         {
//             total=itemprice*quantity;
//         }
// };
// class householdlist:public shoppinglist
// {
//     public:
//         void getdata()
//         {
//             shoppinglist::getdata();
//             cout<<"Enter the item code:";
//             cin>>itemcode;
//             cout<<"Enter the item price:";
//             cin>>itemprice;
//             cout<<"Enter the quantity:";
//             cin>>quantity;
//         }
//         void display()
//         {
//             shoppinglist::display();
//             cout<<"Item code:"<<itemcode<<endl;
//             cout<<"Item price:"<<itemprice<<endl;
//             cout<<"Quantity:"<<quantity<<endl;
//             cout<<"Total:"<<total<<endl;
//         }
//         void totalvalue()
//         {
//             shoppinglist::totalvalue();
//             total=itemprice*quantity;
//         }
// };
// int main()
// {
//     shoppinglist s1;
//     householdlist h1;
//     s1.getdata();
//     s1.totalvalue();
//     s1.display();
//     h1.getdata();
//     h1.totalvalue();
//     h1.display();
//     return 0;
// }
// Output:
// Enter the item code:1
// Enter the item price:100
// Enter the quantity:2
// Item code:1
// Item price:100
// 