#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

Node* createNode(const string& value){
    Node* n = new Node();
    n->data = value;
    n->prev = nullptr;
    n->next = nullptr;
    return n;
}

int main(){
    return 0;
}