#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;    // points to next list
    Node* bottom;  // points to sorted sublist

    Node(int val) {
        data = val;
        next = NULL;
        bottom = NULL;
    }
};


Node* merge(Node* a, Node* b) {
    // Base cases
    if (!a) return b;
    if (!b) return a;

    Node* result;

    // Choose the smaller node
    if (a->data < b->data) {
        result = a;
        // recursively merge remaining
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = NULL;

    return result;
}


Node* flatten(Node* root) {
    // Base case
    if (!root || !root->next)
        return root;

    // first flatten the right side
    root->next = flatten(root->next);

    // now merge current list with flattened right
    root = merge(root, root->next);

    return root;
}
// here we can printing list using bottom pointer 
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

Node* insertBottom(Node* head, int val) {
    if (!head) return new Node(val);

    Node* temp = head;
    while (temp->bottom)
        temp = temp->bottom;

    temp->bottom = new Node(val);
    return head;
}

int main() {
    /*
        The structure looks like this :

        5 -> 10 -> 19 -> 28
        |    |     |     |
        7    20    22    35
        |          |     |
        8          50    40
        |
        30

        Each vertical list is sorted
    */

    Node* head = new Node(5);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Node* flat = flatten(head);

    cout << "Flattened list:\n";
    printList(flat);

    return 0;
}