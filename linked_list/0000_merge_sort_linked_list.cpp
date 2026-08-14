#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    }

    return slow;
}

Node* merge(Node* left, Node* right) {
    List ans;
    Node* i = left;
    Node* j = right;
    while (i != NULL && j != NULL) {
        if (i->value <= j->value) {
            ans.push_back(i->value);
            i = i->next;
        } else {
            ans.push_back(j->value);
            j = j->next;
        }
    }
    while (i != NULL) {
        ans.push_back(i->value);
        i = i->next;
    }
    while (j != NULL) {
        ans.push_back(j->value);
        j = j->next;
    }

    return ans.head;
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value;
        if (temp->next != NULL) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    List list;
    list.push_back(4);
    // list.push_back(2);
    // list.push_back(1);
    // list.push_back(3);
    // list.push_back(5);

    cout << "Original List: ";
    printList(list.head);

    list.head = mergeSort(list.head);

    cout << "Sorted List:   ";
    printList(list.head);

    return 0;
}
