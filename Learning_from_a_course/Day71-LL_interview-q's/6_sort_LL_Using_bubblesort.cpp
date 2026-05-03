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

// Insert at tail
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


void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// using Bubble Sort 
ListNode* bubbleSort(ListNode* head) {
    if (head == NULL) return head;

    bool swapped;

    do {
        swapped = false;
        ListNode* curr = head;

        // traverse list
        while (curr->next != NULL) {
            // now compare the adjacent nodes
            if (curr->val > curr->next->val) {
                // swap values
                int temp = curr->val;
                curr->val = curr->next->val;
                curr->next->val = temp;

                swapped = true;
            }
            curr = curr->next;
        }

    } while (swapped); // repeat until no swaps

    return head;
}

int main() {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 3);

    cout << "Original List:\n";
    printList(head);

    head = bubbleSort(head);

    cout << "Sorted List:\n";
    printList(head);

    return 0;
}