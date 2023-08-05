#include<bits/stdc++.h>
using namespace std;

// implementation of Deque using STL

int main(){
    deque<int> q;
    // push_front , push_back , front , back , size , empty , clear
    q.push_front(10);
    q.push_front(20);
    q.push_front(30);
    q.push_front(40);

    q.push_back(50);
    q.push_back(60);
    q.push_back(70);

    cout<<"front : "<<q.front()<<endl;
    cout<<"back : "<<q.back()<<endl;
    cout<<"size : "<<q.size()<<endl;
    q.insert(q.begin(),100);
    q.insert(q.end(),200);
    q.insert(q.begin(),300);
    q.insert(q.end(),400);
    q.insert(q.begin(),500);
    q.insert(q.end(),600);
    q.insert(q.begin(),700);
    for(auto i : q){
        cout<<i<<" ";
    }
    cout<<endl;
    q.pop_back();
    q.pop_front();
    cout<<"front : "<<q.front()<<endl;
    cout<<"back : "<<q.back()<<endl;
    cout<<"empty : "<<q.empty()<<endl;
    q.clear();
    cout<<"empty : "<<q.empty()<<endl;
    return 0;
}