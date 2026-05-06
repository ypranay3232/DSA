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
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Get length of list
int getLength(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// first Split list into two parts of size 'size' and  returns head of second part
ListNode* split(ListNode* head, int size) {
    while (--size && head) {
        head = head->next;
    }

    if (!head) return NULL;

    ListNode* second = head->next;
    head->next = NULL; // break
    return second;
}

// Merge two sorted lists and return tail
ListNode* merge(ListNode* l1, ListNode* l2, ListNode* &tail) {
    ListNode dummy(0);
    ListNode* curr = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    curr->next = (l1 ? l1 : l2);

    // Move to end (important to update tail)
    while (curr->next) {
        curr = curr->next;
    }

    tail = curr;
    return dummy.next;
}

// Bottom-Up Merge Sort
ListNode* bottomUpMergeSort(ListNode* head) {
    if (!head || !head->next) return head;

    int n = getLength(head);

    ListNode dummy(0);
    dummy.next = head;

    // size = 1,2,4,8...
    for (int size = 1; size < n; size *= 2) {
        ListNode* curr = dummy.next;
        ListNode* tail = &dummy;

        while (curr) {
            ListNode* left = curr;
            ListNode* right = split(left, size);
            curr = split(right, size);

            ListNode* mergedTail = NULL;
            tail->next = merge(left, right, mergedTail);
            tail = mergedTail;
        }
    }

    return dummy.next;
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

    head = bottomUpMergeSort(head);

    cout << "Sorted List:\n";
    printList(head);

    return 0;
}