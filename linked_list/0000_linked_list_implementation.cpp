#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    ~Node(){
        if(next!=nullptr){
            delete next;
            next = nullptr;//why? and what happend of next is actually null
        }
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(int value) {
        Node* data = new Node();

        data->value = value;
        data->next = nullptr;

        if (head == nullptr) {
            head = data;
            tail = data;
        }
        else {
            tail->next = data;
            tail = data;
        }
    }
    void insert(int value, int position){
        Node* temp = head;
        Node* prev = NULL;
        for(int i = 0;i<position;i++){
            prev = temp;
            temp = prev-> next;
        }
        Node* data = new Node();
        data-> value = value;
        data-> next = temp;
        prev-> next = data;

    }
    ~List(){
        if(head!=nullptr){
            delete head;
            cout << " Head";
            head = nullptr;
        }
    }
};
