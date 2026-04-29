// Intersection of two LL and we return the node at which the both LL intersect. and if they dont intersect we return NULL 

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};
// here we take two LL A,B
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    // Base condition
    if (headA == NULL || headB == NULL) return NULL;

    ListNode* ptrA = headA;
    ListNode* ptrB = headB;

    // Traverse both lists
    while (ptrA != ptrB) {

        // Move ptrA
        if (ptrA == NULL) {
            ptrA = headB;
        } else {
            ptrA = ptrA->next;
        }

        // Move ptrB
        if (ptrB == NULL) {
            ptrB = headA;
        } else {
            ptrB = ptrB->next;
        }
    }
    // Either intersection node or NULL
    return ptrA;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {

    // Create common intersection part: 8 -> 9
    ListNode* common = new ListNode(8);
    common->next = new ListNode(9);

    // Create List A: 1 -> 2 -> 3 -> (8 -> 9)
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common;

    // Create List B: 6 -> 7 -> (8 -> 9)
    ListNode* headB = new ListNode(6);
    headB->next = new ListNode(7);
    headB->next->next = common;

    // Print both lists
    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    // Find intersection
    ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}