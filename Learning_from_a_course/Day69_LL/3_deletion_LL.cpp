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

// Insert in Sorted DLL
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

//  Delete at Position (1-based index)
void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    // Case 1: Empty list
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    // Case 2: Delete head
    if (position == 1)
    {
        Node *temp = head;

        // Only one node
        if (head->next_ptr == NULL)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next_ptr;
            head->prev_ptr = NULL;
        }

        delete temp;
        return;
    }

    Node *curr = head;
    int count = 1;

    // Traverse to the node
    while (count < position && curr != NULL)
    {
        curr = curr->next_ptr;
        count++;
    }

    // Invalid position
    if (curr == NULL)
    {
        cout << "Position out of bounds\n";
        return;
    }

    // Case 3: Delete tail
    if (curr->next_ptr == NULL)
    {
        tail = curr->prev_ptr;
        tail->next_ptr = NULL;

        delete curr;
        return;
    }

    // Case 4: Delete middle node
    Node *prevNode = curr->prev_ptr;
    Node *nextNode = curr->next_ptr;

    prevNode->next_ptr = nextNode;
    nextNode->prev_ptr = prevNode;

    delete curr;
}

// Main function
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

    cout << "Delete Operations:\n";
    deleteAtPosition(head, tail, 1); // delete head
    printfunc(head);

    deleteAtPosition(head, tail, 3); // delete middle
    printfunc(head);

    deleteAtPosition(head, tail, 5); // delete tail
    printfunc(head);

    return 0;
}