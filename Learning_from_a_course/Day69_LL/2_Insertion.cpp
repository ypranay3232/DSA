#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev_ptr;
    Node *next_ptr;

    Node(int data)
    {
        this->data = data;
        this->prev_ptr = NULL;
        this->next_ptr = NULL;
    }
};

// print function
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

// insertion at head

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newnode = new Node(data);

    // Case 1: Empty list
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return; // Exit after setting up the first node
    }

    // Case 2: List already has nodes
    newnode->next_ptr = head;
    head->prev_ptr = newnode;
    head = newnode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    cout << "Insert at Head:\n";
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 5);
    printfunc(head);
    return 0;
}