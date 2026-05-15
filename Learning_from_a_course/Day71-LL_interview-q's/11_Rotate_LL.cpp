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

void insertAtTail(ListNode* &head, ListNode* &tail, int val) {
    ListNode* newNode = new ListNode(val);

    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void printLL(ListNode* head) {
    ListNode* temp = head;

    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    int len = 1;
    ListNode* tail = head;

    while(tail->next != NULL) {
        len++;
        tail = tail->next;
    }

    k = k % len;

    if(k == 0) {
        return head;
    }

    tail->next = head;

    int steps = len - k;
    ListNode* newTail = head;

    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    cout << "Original LL: ";
    printLL(head);

    int k = 2;

    head = rotateRight(head, k);

    cout << "Rotated LL: ";
    printLL(head);

    return 0;
}