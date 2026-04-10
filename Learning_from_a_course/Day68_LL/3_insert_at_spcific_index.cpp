#include <iostream>
using namespace std;

// creating new node
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at the very beginning
void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

// Helper: Insert at the very end
void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// Insert at specific position 
void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    // Case 1: Insert at head
    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    // Move to (position - 1)
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    // check if  position is out of bounds
    if (temp == NULL) {
        cout << "Position out of range." << endl;
        return;
    }

    // Case 2: Insert at tail
    if (temp->next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    // Case 3: Insert in middle
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to print 
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Initializing an empty Linked list
    Node* head = NULL;
    Node* tail = NULL;

    // 1. Initial data
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 30);
    cout << "Initial list: ";
    printList(head);

    // 2. Insert at Head (Position 1)
    insertAtPosition(head, tail, 1, 5);
    
    // 3. Insert in Middle (Position 3)
    insertAtPosition(head, tail, 3, 20);
    
    // 4. Insert at Tail (Position 5)
    insertAtPosition(head, tail, 5, 40);

    cout << "After insertions: ";
    printList(head);

    return 0;
}