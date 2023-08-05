// Implementing the hash map using key-value pair
#include<bits/stdc++.h>
using namespace std;
template <typename K,typename V>
class HashNode{
    public:
        V value;
        K key;
        HashNode(K key, V value){
            this->key = key;
            this->value = value;
        }
};

template <typename K, typename V>
class HashMaps{
    private:
        HashNode<K,V> **HashTable;
        HashNode<K,V> *Dummy;
        int Capacity;
        int Size;
    public:
        HashMaps(int Capacity){
            this->Capacity = Capacity;
            this->Size = 0;
            HashTable = new HashNode<K,V>*[Capacity];
            Dummy = new HashNode<K,V>(-1,-1);
            for(int i=0; i<Capacity; i++){
                HashTable[i] = NULL;
            }
        }
        int HashCode(K key){
            return key % Capacity;
        }
        void Insert(K key, V value){
            int HashIndex = HashCode(key);
            HashNode<K,V> *NewNode = new HashNode<K,V>(key,value);
            while (HashTable[HashIndex] == NULL && HashTable[HashIndex]->key != key && HashTable[HashIndex]->key != -1){
                HashIndex++;
                HashIndex %= Capacity;
            }
            
        }
}
