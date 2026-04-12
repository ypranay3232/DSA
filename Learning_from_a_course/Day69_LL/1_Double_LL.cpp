#include <iostream>
using namespace std;

// A doubly ll contains 3 parts in each node : previous address ptr, data, next ptr. In simple words we have to have three parameters in the node function

class Node
{
public:
    int data;
    Node *prev_ptr;
    Node *next_ptr;

    // constructor to initialize values : data = 0 , prev and next = null default

    Node()
    {
        this->data = 0;
        this->next_ptr = NULL;
        this->prev_ptr = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next_ptr = NULL;
        this->prev_ptr = NULL;
    }
};

// pass the head to temp
void printfunc(Node *head)
{
    Node *temp = head;

    // if temp != null print temp data
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next_ptr;
    }
    cout << endl;
}

int getlength(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next_ptr;
        len++;
    }
    return len;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // point each node with prev and next 
    first->next_ptr = second;
    second->prev_ptr = first;

    second->next_ptr = third;
    third->prev_ptr = second;

    printfunc(first);

    return 0;
}