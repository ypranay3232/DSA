#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Create a new node, newtodo -> next = head, head = new node
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newnode = new Node(data);
    newnode->next = head;
    if (head == NULL)
    {
        tail = newnode;
    }
    head = newnode;
}

// inserting at tail : create a new node, tail->next = newnode,tail = newnode
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newnode = new Node(data);
    if (tail == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    // Assume we have a starting Node of head with 10
    // Node *head = new Node(10);

    // even if we dont have any starting values it still works
    Node *head = NULL;

    // initializing tail with null
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 70);
    insertAtHead(head, tail, 40);

    // inserting at tail
    insertAtTail(head,tail, 10); // wont work because whenever we initialize head or tail, you have to make sure that the first new node should be initialized with head and tail. (just pass tail in insertathead(,tail,))

    print(head);
    return 0;
}