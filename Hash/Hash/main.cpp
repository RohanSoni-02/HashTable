//
//  main.cpp
//  Hash
//
//  Created by Rohan Soni on 17/2/2024.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

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
};
