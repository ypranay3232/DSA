// Remove the Duplicates from a sorted and un-sorted LL : if a LL is sorted then the duplicates will always be adjacent of the elements so we just compare current node and next node.

// Approach is simple : traverse once, check curr->data == curr->next->data, delete it and move.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// function to remove the duplicates
Node* removeDup(Node* head){
    // if LL is empty or contains single element return it
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* curr = head;

    // now traverse the list : 
    while(curr != NULL && curr->next != NULL){
        // if duplicate found 
        if(curr->data == curr->next->data){
            Node* temp = curr->next;//store duplicate node
            curr->next = curr->next->next; //skip duplicate 
            delete temp;//remove the duplicate 
        }else{
            // if no duplicates found move forward
            curr = curr->next;
        }
    }
    return head;
}

// insert elements at tail 
void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node* head = NULL;

    // Inserting sorted elements with duplicates
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 30);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    cout << "Original List: ";
    printList(head);


    head = removeDup(head);
    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}