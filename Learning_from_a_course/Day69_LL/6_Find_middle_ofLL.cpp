// Find the middle node of a LL : using slow and fast pointer approach, slow ptr moves 1 step and fast ptr moves 2 steps. so when fast ptr reaches end the slow will be the middle

#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Insert nodes at tail to easily build the LL
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    // check if list is empty
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    // if list contains elements append elements
    tail->next = newNode;
    tail = newNode;
}

// function to print 
void printlist(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

// function to find middle node
Node* findMiddle(Node* head){
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    // loop until fast == NULL when it reaches NULL end.
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);

    cout<<"LL is : "<<endl;
    printlist(head);

    Node* middle = findMiddle(head);

    if(middle != NULL){
        cout<<"Middle node is : "<<middle->data<<endl;
    }
    return 0;
}