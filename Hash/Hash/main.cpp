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
};
