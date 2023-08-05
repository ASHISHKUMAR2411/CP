// Implemenetation of Chaining Using Linked List
#include <bits/stdc++.h>
using namespace std;

// we can have three implementation using linked list
// 1.) tradition Method of making a struct , class of node (second)
// 2.) using stl of forward_list (most simple)
// 3.) using stl of list which is a deque (this is not required as it takes extra space for storing two address of front and back)

// 3rd Implemenetation
class HashTable
{
private:
    int bucket;
    list<int> *Hash;
    int HashKey(int key)
    {
        return (key % bucket);
    }

public:
    HashTable(int buck);
    void Insert(int num);
    void Search(int num);
    void Delete(int num);
    void Display();
};

HashTable::HashTable(int buck)
{
    this->bucket = buck;
    Hash = new list<int>[bucket];
}

void HashTable::Insert(int num)
{
    int key = HashKey(num);
    Hash[key].push_back(num);
    cout << "\nElement Inserted \n";
    return;
}

void HashTable::Search(int num)
{
    int key = HashKey(num);

    for (auto it : Hash[key])
    {
        if (num == it)
        {
            cout << "\n"
                 << num << " Found " << key << "th row\n";
            return;
        }
    }
    cout << "\nELement Not Found" << endl;
    return;
}

void HashTable::Delete(int num)
{
    int key = HashKey(num);

    for (auto it = Hash[key].begin(); it != Hash[key].end(); it++)
    {
        if (*it == num)
        {
            Hash[key].erase(it);
            cout << "\n Element Deleted\n";
            return;
        }
    }
    cout << "\n"<< num << "ELement Not Found" << endl;
    return;
}

void HashTable::Display()
{
    for (int i = 0; i < this->bucket; i++)
    {
        cout << i << " : ";
        for (auto it : Hash[i])
        {
            cout << "-->" << it;
        }
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    int n = rand() % 100;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    int m = rand() % 47;
    // Creating Object
    HashTable H(m);
    for (int i = 0; i < n; i++)
    {
        H.Insert(arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        H.Search(rand() % 100);
    }
    H.Display();
    return 0;
}