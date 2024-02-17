//
//  main.cpp
//  Hash
//
//  Created by Rohan Soni on 17/2/2024.
//

#include <iostream>
using namespace std;

class Node{
public:
    string key;
    int value;
    Node* next;
    
    Node(string key, int value){
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable{
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];
    
public:
    void printTable(){
        for(int i =0; i < SIZE; i++){
            if(dataMap[i]){
                Node* temp = dataMap[i];
                cout<< i << ": ";
                while (temp) {
                    cout<< " {" << temp->key << ", " << temp->value<< "}"<<endl;
                    temp = temp->next;
                }
            }
        }
    }
    
    int hash(string key){
        int hash = 0;
        for(int i = 0; i < key.length(); i++){
            int ascii = int(key[i]);
            hash = (hash + (ascii*23)) % SIZE;
        }
        return hash;
    }
    
    void set(string key, int value){
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if(dataMap[index] == nullptr){
            dataMap[index] = newNode;
        }
        else{
            Node* temp = dataMap[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    int get(string key){
        int index = hash(key);
        Node* temp = dataMap[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return 0;
    }
    
    vector<string> keys(){
        vector<string> allKeys;
        for(int i = 0; i <SIZE; i++){
            Node* temp = dataMap[i];
            while (temp != nullptr) {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return allKeys;
    }
};

int main() {
    HashTable* hash = new HashTable();
    hash->set("nails", 100);
    hash->set("tile", 200);
    hash->set("lumber", 400);
    hash->set("anything", 800);
    hash->set("toys", 900);
    
    
    //hash->printTable();
    
    vector<string> keys = hash->keys();
    
    for (auto key: keys) {
        cout<< key <<endl;
    }
}
