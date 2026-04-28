// here given a single linked list and return the kth node from the end

// ex : 1->2->3->4->5, k = 2
// we count from back and here index starts with 1 not 0, so k =2 so k = 4


// we use two pointer approach (fast and slow)

#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// function to find the kth node 
Node* KthFromEnd(Node* head,int k){
    // first find the length of the list
    int length = 0;
    Node* temp = head;

    while(temp!=NULL){
        length++; //this counts the no of nodes
        temp = temp->next;
    }

    // now handle the k condition if k is not 0
    if(k>length) return NULL;

    // now find the length - kth node from start
    temp = head;
    int target = length - k;

    while(target--){
        temp = temp->next; //move the target node
    }

    return temp;
}
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
int main() {
    Node* head = NULL;

    // Creating the list: 1 -> 2 -> 3 -> 4 -> 5
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    int k = 2;
    Node* result = KthFromEnd(head, k);

    if (result != NULL) {
        cout << "The " << k << "nd node from the end is: " << result->data << endl;
    } else {
        cout << "Error: k is out of bounds or list is empty." << endl;
    }

    return 0;
}