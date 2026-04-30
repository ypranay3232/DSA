#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// we insert elements at tail
void insertAtTail(ListNode* &head, ListNode* &tail, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to print linked list
void printList(ListNode* head) {
    ListNode* temp = head;

    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// we use a two pointer approach 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    // creating a Dummy node to simplify logic
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    // now Traverse both lists
    while (l1 != NULL && l2 != NULL) {

        // now compare both values and attach smaller node
        if (l1->val <= l2->val) {
            temp->next = l1;   // link l1 node
            l1 = l1->next;     // move l1 forward
        } else {
            temp->next = l2;   // link l2 node
            l2 = l2->next;     // move l2 forward
        }

        temp = temp->next; // move result pointer
    }

    // Attach remaining nodes (only one list will have nodes left)
    if (l1 != NULL) {
        temp->next = l1;
    } else {
        temp->next = l2;
    }

    return dummy->next; // return merged head
}

int main() {

    // first list
    ListNode* l1 = NULL;
    ListNode* tail1 = NULL;

    insertAtTail(l1, tail1, 1);
    insertAtTail(l1, tail1, 3);
    insertAtTail(l1, tail1, 5);

    cout << "List 1: ";
    printList(l1);

    // second list
    ListNode* l2 = NULL;
    ListNode* tail2 = NULL;

    insertAtTail(l2, tail2, 2);
    insertAtTail(l2, tail2, 4);
    insertAtTail(l2, tail2, 6);

    cout << "List 2: ";
    printList(l2);

    // now merge both and print
    ListNode* merged = mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}