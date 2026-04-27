#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        int digit = sum % 10;
        carry = sum / 10;
        temp->next = new ListNode(digit);
        temp = temp->next;
    }
    return dummy->next;
}

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val;
        if (node->next != NULL) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Creating first list: 2 -> 4 -> 3 (represents number 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Creating second list: 5 -> 6 -> 4 (represents number 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    // Call the function
    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result); // Expected: 7 -> 0 -> 8 (represents 807)

    return 0;
}