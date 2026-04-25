#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node *removeDuplicatesUnsorted(Node *head) {
    if (head == NULL)
        return head;

    // create a set to store visited values 
    unordered_set<int> seen;
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL) {
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

void insertAtTail(Node *&head, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node *head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 30);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicatesUnsorted(head);
    
    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}