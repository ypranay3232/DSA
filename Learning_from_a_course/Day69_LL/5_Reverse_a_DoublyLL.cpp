// ex : 1,2,3,4 NULL so reverse this LL (Null 4,3,2,1)

// 1) Brute Force Approach : We simply store the values inside an array and we reverse that array

#include <iostream>
#include <vector>
using namespace std;

// first create a node with two values data and next ptr
class Node
{
public:
    int data;
    Node *next;

    // constructor : where data = data and next = null
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Optimised approach :
Node* reverseDLL(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;  // Store next node
        curr->next = prev;  // Reverse the link
        prev = curr;        // Move prev forward
        curr = next;        // Move curr forward
    }
    return prev; // New head is the last node we processed
}

// function to print the list
void PrintList(Node* head){
    Node* temp = head;
    while (temp !=NULL)
    {
        cout<<temp->data <<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    
}

int main()
{
    // create a node 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout<<"original List"<<endl;
    PrintList(head);


    head = reverseDLL(head);
    cout<<"Reversed Single LL"<<endl;
    PrintList(head);

    // now clear the memory

    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}