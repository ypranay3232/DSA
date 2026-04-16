#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev_ptr;
    Node *next_ptr;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->prev_ptr = NULL;
        this->next_ptr = NULL;
    }
};

// Print the doubly linked list
void printfunc(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next_ptr;
    }
    cout << endl;
}

// Insert at Head
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    // Empty list
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    newNode->next_ptr = head;
    head->prev_ptr = newNode;
    head = newNode;
}

// Insert at Tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    // Empty list
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    tail->next_ptr = newNode;
    newNode->prev_ptr = tail;
    tail = newNode;
}

// Insert at Position (1-based index)
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{

    // Insert at head
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    Node *temp = head;
    int count = 1;

    // Move to (position - 1)
    while (count < position - 1 && temp->next_ptr != NULL)
    {
        temp = temp->next_ptr;
        count++;
    }

    // Insert at tail
    if (temp->next_ptr == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // Insert in middle
    Node *newNode = new Node(data);

    newNode->next_ptr = temp->next_ptr;
    newNode->prev_ptr = temp;

    temp->next_ptr->prev_ptr = newNode;
    temp->next_ptr = newNode;
}

// Insert in Sorted Doubly Linked List
void insertSorted(Node *&head, Node *&tail, int data)
{

    // Empty list
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = tail = newNode;
        return;
    }

    // Insert at head
    if (data <= head->data)
    {
        insertAtHead(head, tail, data);
        return;
    }

    Node *temp = head;

    // Find correct position
    while (temp->next_ptr != NULL && temp->next_ptr->data < data)
    {
        temp = temp->next_ptr;
    }

    // Insert at tail
    if (temp->next_ptr == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // Insert in middle
    Node *newNode = new Node(data);

    newNode->next_ptr = temp->next_ptr;
    newNode->prev_ptr = temp;

    temp->next_ptr->prev_ptr = newNode;
    temp->next_ptr = newNode;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    cout << "Insert at Head:\n";
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 5);
    printfunc(head); // 5 10

    cout << "Insert at Tail:\n";
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    printfunc(head); // 5 10 20 30

    cout << "Insert at Position:\n";
    insertAtPosition(head, tail, 3, 15);
    printfunc(head); // 5 10 15 20 30

    cout << "Insert Sorted:\n";
    insertSorted(head, tail, 25);
    insertSorted(head, tail, 1);
    printfunc(head); // 1 5 10 15 20 25 30

    return 0;
}