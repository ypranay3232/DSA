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

// // Reverse using extra space
// Node* Reverse_singleLL(Node* head){
//     // Array to store values and a temp ptr that points to head
//     vector<int> arr;
//     Node* temp = head;

//     // now store values in array :
//     while(temp != NULL){
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     // now reverse the array
//     temp = head;
//     for(int i =arr.size() -1;i>=0;i--){
//         temp->data = arr[i];
//         temp = temp->next;
//     }
//     return head;
// }

// Optimised approach :
Node *reverse_singleLL(Node *head)
{
    // 'prev' will eventually become the new head of the reversed list
    Node *prev = NULL;
    // 'curr' starts at the original head to begin the traversal
    Node *curr = head;

    while (curr != NULL)
    {
        // 1. Temporarily store the next node so we don't lose the rest of the list
        Node *nextnode = curr->next;
        // 2. Reverse the link: point the current node back to the previous node
        curr->next = prev;
        // 3. Move the 'prev' and 'curr' pointers one step forward
        prev = curr;
        curr = nextnode;
    }
    // After the loop, 'prev' rests on the last non-NULL node (the new head)
    return prev;
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


    head = reverse_singleLL(head);
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