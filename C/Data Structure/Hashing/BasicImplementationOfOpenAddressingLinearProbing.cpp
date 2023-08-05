#include<bits/stdc++.h>
using namespace std;
// Using Linear Probing Assuming elements are positive
// In Libraries they use NULL for empty slot and Dummy Node for deleted items
struct HashTable{
    int capacity, size;
    vector<int> hash;
    HashTable(int c){
        capacity = c;
        size = 0;
        for(int i = 0; i<c;i++)
            hash.push_back(-1);
    }
    int HashKey(int item);
    void Insert(int item);
    void Delete(int item);
    void Search(int item);
    void DisplayHash();
};
int HashTable::HashKey(int item){
    return item % this->capacity;
}

void HashTable::Insert(int item){
    if( this->size == this->capacity ){
        cout << "\n " << item << " Overflow Size \n";
        return;
    }
    int key = this->HashKey(item);
    int i = key;
    while(this->hash[i] != -1 && this->hash[i]!=-2 && this->hash[i] != item )
        i = (i + 1) % (this->capacity);
    if(this->hash[i] == item){
        cout << "\n " << item << " Element Already there \n";
        return;
    }
    else{
        cout << "\n " << item << " Element Inserted \n";
        this->hash[i] = key;
        this->size++;
        return;
    }
}

void HashTable::Delete(int item){
    int key = this->HashKey(item);
    int pos = key;
    while(this->hash[pos] != -1){
        if(this->hash[pos] == item){
            this->hash[pos] = -2;
            this->size--;
            cout << "\n " << item << " Element deleted\n";
            return;
        }
        pos = (pos + 1) % this->capacity;
        if(pos == key){
            cout << "\n " << item << " Element Not found \n";
            return ;
        }
    }
    cout << "\n " << item << " Element Not found \n";
    return ;
}

void HashTable::Search(int item){
    int key = this->HashKey(item);
    int pos = key;
    while(this->hash[pos]!= -1){
        if(this->hash[pos] == item){
            cout << "\n element found at index " << pos << "\n";
            return ;
        }
        pos = (pos + 1) % this->capacity;
        if (pos == key)
        {
            cout << "\n " << item << " Element Not found \n";
            return ;
        }
    }
    cout << "\n " << item << " Element Not found \n";
    return ;
}

void HashTable::DisplayHash(){
    cout << "\n";
    for (int i = 0; i < this->hash.size(); i++)
    {
        cout << "-->" << this->hash[i];
    }
    cout << "\n";
    return;
}

int main()
{
    srand(time(0));
    HashTable H(rand() % 97);
    int n = rand() % 47;
    for (int i = 0; i < n; i++){
        H.Insert(rand() % 250);
    }
    H.DisplayHash();
    for (int i = 0; i < 10; i++){
        H.Search(rand() % 250);
    }
    
    for (int i = 0; i < 10; i++)
    {
        H.Delete(rand()%250);
    }
    H.DisplayHash();
    return 0;
}