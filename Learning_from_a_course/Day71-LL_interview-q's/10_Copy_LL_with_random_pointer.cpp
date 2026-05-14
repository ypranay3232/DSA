#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int val) {
        this->val = val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head) {
    // Edge case: if list is empty, nothing to copy
    if (head == NULL) return NULL;

    // STEP 1: Create copy nodes and interweave them with original nodes
    Node *temp = head;
    while (temp != NULL) {
        Node *nextNode = temp->next;          // Save the original next
        Node *copyNode = new Node(temp->val); // Create the duplicate node
        
        temp->next = copyNode;               // Link original to copy
        copyNode->next = nextNode;           // Link copy to original's next
        
        temp = nextNode;                     // Move to the next original node
    }

    // STEP 2: Assign random pointers for the copied nodes
    temp = head;
    while (temp != NULL) {
        Node *copyNode = temp->next;         // The copy is always right after 'temp'
        if (temp->random != NULL) {
            // copy's random should point to the copy of original's random
            copyNode->random = temp->random->next;
        }
        // Jump two steps to reach the next original node
        temp = copyNode->next;
    }

    // STEP 3: Separate the interwoven lists
    temp = head;
    Node *copyHead = head->next;             // This will be the head of our new list
    while (temp != NULL) {
        Node *copyNode = temp->next;
        
        temp->next = copyNode->next;         // Restore original list's 'next'
        
        if (copyNode->next != NULL) {
            copyNode->next = copyNode->next->next; // Link copy nodes together
        }
        
        temp = temp->next;                   // Move forward in the restored original list
    }

    return copyHead;
}

// Helper function to print the list
void printList(Node *head) {
    while (head) {
        cout << "Val: " << head->val;
        if (head->random) cout << ", Random: " << head->random->val;
        else cout << ", Random: NULL";
        cout << endl;
        head = head->next;
    }
}

int main() {
    // Manually creating a list: 1 -> 2 -> 3
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;

    // Setting up random pointers
    head->random = third;    // 1 points to 3
    second->random = head;   // 2 points to 1
    third->random = second;  // 3 points to 2

    cout << "--- Original List ---" << endl;
    printList(head);

    Node* clonedList = copyRandomList(head);

    cout << "\n--- Cloned List ---" << endl;
    printList(clonedList);

    return 0;
}