#include<iostream>
#include<string>
#include<vector>
#include<chrono>
using std::vector;
using namespace std::chrono;
using namespace std;
int main()
{
    // here begin and rbegin can used to change the content but cbegin cannot crbegin means it will not change the content and it will return the next to the last element and crend points to the firste element
    // we can use #include <bits/stdc++.h>
    vector<int> A={1,2,3,4,5,6,7,8};
    vector<char> B={'a','b','c','d','e','f'};
    vector<float> C={1.1,2.2,3.3,4.4,5,6.6,7.7,8.8};
    vector<double> D={1.00001,2.0009,3.8695,4.4563,5.7851,6.89754,7.9086,8.09534};
    vector<string> E={"Ashish","Priya","Sony","Radha","Chintu","Dhaneshwar"};
    vector<bool> F={0,1,0,1,1,1,0};
    vector<long int> G={1001,20000,30987,4897,5786,6897,7765,8098};
    for(auto i=A.begin();i!=A.end();i++)
    {
        cout<<"   "<<*i;
    }
    cout<<"\n";
    for(auto i=B.begin();i!=B.end();i++)
    {
        cout<<"   "<<*i;
    }
    cout<<"\n";
    for(auto i=C.begin();i!=C.end();i++)
    {
        cout<<"   "<<*i;
    }
    cout<<"\n";
    for(auto i=D.begin();i!=D.end();i++)
    {
        cout<<"   "<<*i;
    }
    cout<<"\n";
    for(auto i=E.begin();i!=E.end();i++)
    {
        cout<<"   "<<*i;
    }
    cout<<"\n";
    for(auto i=F.begin();i!=F.end();i++)
    {
        cout<<"   "<<*i;
    }
    cout<<"\n";
    for(auto i=G.begin();i!=G.end();i++)
    {
        cout<<"   "<<*i;
    }
    cout<<"\n";
    for(auto i=A.rbegin();i!=A.rend();i++)
    {
        cout<<" "<<*i;
    }
    cout<<"\n";
    for(auto i=B.rbegin();i!=B.rend();i++)
    {
        cout<<" "<<*i;
    }
    cout<<"\n";
    for(auto i=C.rbegin();i!=C.rend();i++)
    {
        cout<<" "<<*i;
    }
    cout<<"\n";
    for(auto i=D.rbegin();i!=D.rend();i++)
    {
        cout<<" "<<*i;
    }
    cout<<"\n";
    for(auto i=E.rbegin();i!=E.rend();i++)
    {
        cout<<" "<<*i;
    }
    cout<<"\n";
    for(auto i=F.rbegin();i!=F.rend();i++)
    {
        cout<<" "<<*i;
    }
    cout<<"\n";
    for(auto i=G.rbegin();i!=G.rend();i++)
    {
        cout<<" "<<*i;
    }
    cout<<"\n";
    ++*A.begin();
    cout<<"\nthe last element is "<<*A.begin();
    cout<<"\n";
    for(auto i=G.cbegin();i!=G.end();i++)
    {
        cout<<" "<<*i;
    }
    cout<<"\n";
    for(auto i=G.cend()-1;i!=G.begin();i--)
    {
        cout<<" "<<*i;
    }
    cout << " " << *G.cbegin();
    cout<<"\n";
    // for(auto i=B.crbegin();i!=B.crend();i++)
    for(auto i=B.crbegin();i!=B.crend();i++)
    {
        cout<<"   "<<*i;
    }
    cout<<"\n";
// now we will see the user input system and manipulation of the that
    vector<int> g1={1,2,3,4,5,6} ,g2={};
    cout<<"\nthe element of the new array g1 ";
    for(int i=0;i<=5;i++)
    {

        g1.push_back(i);
    }
    cout<<"\n";
    cout<<"\n";
    for(auto it=g1.begin();it!=g1.end();++it)
    {
        cout<<" "<<*it;
    }
    cout<<"\n";
// now seeing the size of the vector
    cout<<A.empty();
    cout<<"\n";
    // A.empty();
    cout<<"\n";
    cout<<g2.empty();
    cout<<"\n";
    // g2.empty();
    cout<<"\n";
    if(g2.empty())
    {
        cout<<"\nTrue";
    }
    else
    {
        cout<<"\nFalse";
    }
    int sum=0;
    // for finding the sum 
    while(!g1.empty())
    {
        sum += g1.back();
        g1.pop_back();
    }
    cout<<"\n";
    cout<<sum;
    cout<<"\n";
    cout<<g1.size();
    cout<<"\n";
    g1.size();
    cout<<"\n";
    cout<<g2.size();
    cout<<"\n";
    g2.size();
    cout<<"\n";
    // size has O(n) complexity
    // vector size
    vector<int> a1;
    vector<float> a2;
    vector<string> a3;
    vector<bool> a4;
    vector<char> a5;
    vector<double> a6;
    cout<<"\n";
    cout<<"\n max size of the vextor is :"<<a1.max_size();
    cout<<"\n";
    cout<<"\n max size of the vextor is :"<<a2.max_size();
    cout<<"\n";
    cout<<"\n max size of the vextor is :"<<a3.max_size();
    cout<<"\n";
    cout<<"\n max size of the vextor is :"<<a4.max_size();
    cout<<"\n";
    cout<<"\n max size of the vextor is :"<<a5.max_size();
    cout<<"\n";
    cout<<"\n max size of the vextor is :"<<a6.max_size();
    cout<<"\n";
    cout<<"\n the size of the vector is :"<<A.size();
    cout<<"\n the capacity of the vector is :"<<A.capacity();
    cout<<"\n";
    cout<<"\n the size of the vector is :"<<B.size();
    cout<<"\n the capacity of the vector is :"<<B.capacity();
    cout<<"\n";
    cout<<"\n the size of the vector is :"<<C.size();
    cout<<"\n the capacity of the vector is :"<<C.capacity();
    cout<<"\n";
    cout<<"\n the size of the vector is :"<<D.size();
    cout<<"\n the capacity of the vector is :"<<D.capacity();
    cout<<"\n";
    vector<int> b1;
    for(int i=0;i<10;i++)
    {
        b1.push_back(i*10);
    }
    cout<<endl;
    for(int i=0;i<b1.size();i++)
    {
        cout<<" "<<b1[i];
    }
    cout<<endl;
    // here we have to understand the different functions here size will give the actual size which it hold 
    // resize used to change the size but it does not delete the elements they are still there and can be used to fetch other elements 
    // shrink to fit shrink the container i.e array into that size in which it is legal i.e after resize it will shrink to the size set by resize
    // 
    cout<<"\nVector is size :"<<b1.size();
    cout<<"\nVector is capacity :"<<b1.capacity();
    cout<<"\n";
    b1.resize(4);
    cout<<"\n the content of the vector of size "<<b1.size()<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<b1[i]<<" ";
    }
    cout<<endl;
    b1.shrink_to_fit();
    cout<<"\n the content of the vector of size "<<b1.size()<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<b1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<b1.size();i++)
    {
        cout<<b1[i]<<" ";
    }
    b1.resize(10,0);
    cout<<"\n the content of the vector"<<endl;
    for(int i=0;i<b1.size();i++)
    {
        cout<<b1[i]<<" ";
    }
    // showing how to use reserve() function
    // illustrate the use to how to calculates the time  
    int N=(int)1e6;
    vector<int> v1,v2;
    v2.reserve(N);
    auto start = high_resolution_clock::now();
    for(int i=0;i<N;++i)
    {
        v1.push_back(i);
    }
    auto stop =high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
    cout<<"\n Method took "<<duration.count()<<" microseconds";
    start = high_resolution_clock::now();
    for(int i=0;i<N;++i)
    {
        v2.push_back(i);
    }
    stop =high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout<<"\n Method ii took "<<duration.count()<<" microseconds \n";
    // operator() is used to change the existing values of the array(dynamic)
    // it show undefined behaviour when we try to fetch the the element of the out of range
    vector<int> c1={1,2,3,4,5},c2={4,3,2,1};
    for(auto i=c1.begin();i!=c1.end();i++)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    for(auto i=c2.begin();i!=c2.end();i++)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    c1=c2;
    for(auto i=c1.begin();i!=c1.end();i++)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    cout<<" "<<c1[2];
    cout<<" "<<c2[4];
    cout<<endl;
    c1.push_back(5);
    c1.push_back(6);
    c1.push_back(7);
    c1.push_back(9);
    c1.push_back(8);
    c1.push_back(5);
    cout<<endl;
    for(auto i=c1.begin();i!=c1.end();i++)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    for(auto i=c1.begin();i!=c1.end();++i)
    {
        if((i-c1.begin())%2==0)
        {
            cout<<" "<<*i;
        }
    }
    cout<<endl;
    for(int i=0;i<c1.size();i++)
    {
        if(i%2==0)
        {
            cout<<" "<<c1[i];
        }
    }
    // use at() function in this
    cout<<endl; 
    cout<<c1.at(2)<<" "<<c2.at(2)<<" "<<A.at(2)<<" "<<B.at(2)<<" "<<C.at(2)<<" "<<D.at(2)<<" "<<E.at(2)<<" "<<F.at(2)<<" "<<G.at(2)<<" ";
    // <<g1.at(2)<<" ";
    // <<g2.at(2)<<" ";
    // <<v1.at(2)<<" "<<v2.at(2)<<" "<<b1.at(2)<<" "<<a1.at(2)<<" "<<a2.at(2)<<" "<<a3.at(2)<<" "<<a4.at(2)<<" "<<a5.at(2)<<" "<<a6.at(2);
    cout<<endl;
    // swap() function is used to the swap to content of one vector with another and size may differ 
    for(auto i=c1.begin();i!=c1.end();i++)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    for(auto i=c2.begin();i!=c2.end();i++)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    c1.swap(c2);
    for(auto i=c1.begin();i!=c1.end();i++)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
     for(auto i=c2.begin();i!=c2.end();i++)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    // front function is used to give the element at the front position 
    cout<<c1.front();
    cout<<" "<<c2.front();
    cout<<"\n";
    c1.swap(A);
    cout<<c1.front();
    cout<<" "<<c2.front();
    cout<<endl;
    // cout<<g2.front()<<" "<<g1.front();
    // cout<<endl;
    // cout<<g2.front()<<" "<<g1.front();
    // cout<<endl;
    // cout<<g2.back()<<" "<<g1.back();
    cout<<endl;
    cout<<c1.back();
    cout<<endl;
    cout<<" "<<c2.back();
    cout<<"\n"<<c1.back()<<" "<<c1.front()<<endl;
    cout<<"\n"<<c1.front()-c1.back();
    if(c1.front()>c1.back())
    {
        cout<<"\n"<<c1.front()-c1.back();
    }
    else
    {
        cout<<endl<<c1.back()-c1.front();
    }
    cout<<endl;
    // data() function is the function which is used to find and return the position of the first element which is stored internally .
    int *p=c1.data();
    for(int i=0 ; i<c1.size();i++)
    {
        cout<<" "<<*p++;
    }
    cout<<endl;
    // assign function is used to store the new variable in place of the new ones , it can also used to modify the data ;
    cout<<int(c1.size());
    cout<<endl;
    g2.assign(7,10);
    for(auto i=g2.begin();i!=g2.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    int a[]={1,2,3,4,5};
    g1.assign(a,a+5);
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    g1.assign(g1.begin(),g1.begin()+3);
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    g1.assign({1,2,3,4,5,6,7,8,9,0,10});
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    // push_back() function is used to push elements in the vector and also resize them according to the push , it throws error only when container changes its position 
    // pop_back is the function is used to pop out the value from the vector and it decrement the size of the vector , it removes element from the back.
    g1.push_back(11);
    g1.push_back(12); 
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    g1.pop_back();
    // pop_back is not used to delete the data it only decrement the size we can find the value of the pop_element and it can easily find out , if we resize the vector or we shrink_to_fit the vector then we will lost that popped_element 
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    cout<<g1.size()<<" "<<g1[12];
    g1.shrink_to_fit();
    // shrink to fit is used to limit the container size by shrinking it to the legal data 
    cout<<endl;
    cout<<g1.size()<<" "<<g1[12]<<endl;
// now we will use the insert () function in which what happened is actually
    g1.insert(g1.begin()+3,40);
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    // here i is the position where it adds
    // and *i is the value we added at that position
    auto i=g1.insert(g1.begin()+5,9);
    i=g1.insert(g1.begin()+7,98);
    g1.insert(i,2);
    cout<<" "<<*i<<endl;
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    // we can also insert a whole array 
    int aa[]={100,200,300},x=50;
    start = high_resolution_clock::now();
    g1.insert(g1.begin()+2,x);
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    stop =high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout<<endl;
    start = high_resolution_clock::now();
    g1.insert(g1.begin()+2,{100,200,x,300,400});
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    stop =high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout<<"\n Method ii took "<<duration.count()<<" microseconds \n";
    cout<<endl;
    // differnet syntax for insert (position,frequency,value);
    g1.insert(g1.begin()+2,5,3);
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    i = g1.insert(g1.begin(),1,0);
    g1.insert(i,2,10);
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    // we learn that once a value is intialise then we should take care that it should not be initialise again;


    // another synatx for insert()
    g1.insert(g1.begin()+4,g2.begin(),g2.end());
    cout<<endl<<endl;
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    // clear() function is used to delete all the element of the vector and it is used to make it size 0
    for(auto i=g2.begin();i!=g2.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    g2.clear();
    for(auto i=g2.begin();i!=g2.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
//  when we have clear only few element from the vector then we use
// erase () function 
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl<<endl<<endl;
    g1.erase(g1.begin()+3);
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl<<endl<<endl;
    g1.erase(g1.begin()+5,g1.begin()+10);
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        if(*i % 2 == 0)
        {
            g1.erase(i);
            i--;
        }
    }
    cout<<"Hello";
    cout<<endl<<endl;
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    // now we will read about the function emplace() which is used to insert the element at the specified position and it is used to return the positionn of that element which it insert 
    i=g1.emplace(g1.begin()+2,199);
    cout<<"\n"<<*i;
    cout<<endl<<endl;
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    i=g1.emplace(g1.end(),4);
    cout<<endl<<endl;
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    // emplace_back is used to insert the element at the end of the vector
    g1.emplace_back(4);
    cout<<endl<<endl;
    for(auto i=g1.begin();i!=g1.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<endl;
    // in vector we can create the pair too
    // for example
    vector<pair<int,string>> h1;
    h1.emplace_back(8,"Ashish Kumar");
    h1.emplace_back(9,"Aditya Agarrawal");
    h1.emplace_back(10,"Dipanshu Garg");
    h1.push_back(make_pair(11,"Harshdeep Singh Sheeti"));
    h1.push_back(make_pair(12,"Adarsh Kumar"));
    for(int i=0;i<h1.size();i++)
    {
        printf("\n %3d  ",h1[i].first);
        cout<<h1[i].second;
    }
    return 0;
}
