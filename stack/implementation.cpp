#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> vec;
    int top;
    int cap;

public:
    Stack() {
        top = -1;
        cap = 1;
        vec.resize(cap);
    }

    void push(int val) {
        if (top + 1 < cap) {
            top++;
            vec[top] = val;
        }
        else {
            
            cap = cap * 2;
            top++;
            vec.resize(cap);
            vec[top] = val;
        }
    }
    void pop(){
        if(top == -1){
            cout << "The stack is empty";
            return;
        }
        top--;
    }
    void display(){
        for(int i = top;i>=0;i--){
            cout << vec[i] << " ";
            cout << i << "\n";
        }
        return;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.display();
    return 0;
}