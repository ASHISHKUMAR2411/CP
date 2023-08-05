// Implementing Hash Tables using Linked List
#include<bits/stdc++.h>
using namespace std;
struct MyFirstHash{
    int Bucket;
    list<int> *HashTable;
    MyFirstHash(int Bucket){
        this->Bucket = Bucket;
        HashTable = new list<int>[Bucket];
    }
    void Insert(int key){
        int HashIndex = key % Bucket;
        HashTable[HashIndex].push_back(key);
    }
    void Delete(int key){
        int HashIndex = key % Bucket;
        list<int>::iterator it;
        for(it = HashTable[HashIndex].begin(); it != HashTable[HashIndex].end(); it++){
            if(*it == key){
                HashTable[HashIndex].erase(it);
                cout << "Deleted " << key << endl;
                break;
            }
        }

        // OR

        // HashTable[HashIndex].remove(key);
    }
    bool Search(int key){
        int HashIndex = key % Bucket;
        list<int>::iterator it;
        for(it = HashTable[HashIndex].begin(); it != HashTable[HashIndex].end(); it++){
            if(*it == key){
                return true;
            }
        }
        // OR
        // for(auto it : HashTable[HashIndex]){
        //     if(it == key){
        //         return true;
        //     }
        // }
        return false;
    }

}