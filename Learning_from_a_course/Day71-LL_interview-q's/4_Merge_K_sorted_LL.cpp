#include <iostream>
#include <vector>
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

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void printList(ListNode* head) {
    ListNode* temp = head;

    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Merge two sorted lists 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    while (l1 != NULL && l2 != NULL) {

        if (l1->val <= l2->val) {
            temp->next = l1;   // attach l1 node
            l1 = l1->next;     // move forward
        } else {
            temp->next = l2;   // attach l2 node
            l2 = l2->next;
        }

        temp = temp->next;
    }

    // attach remaining nodes
    temp->next = (l1 != NULL) ? l1 : l2;

    return dummy->next;
}

// Divide & Conquer method 
ListNode* solve(vector<ListNode*>& lists, int start, int end) {

    // base case
    if (start == end) return lists[start];

    int mid = (start + end) / 2;

    // first divide 
    ListNode* left = solve(lists, start, mid);
    ListNode* right = solve(lists, mid + 1, end);

    // conquer
    return mergeTwoLists(left, right);
}

// Main merge K lists function
ListNode* mergeKLists(vector<ListNode*>& lists) {

    if (lists.size() == 0) return NULL;

    return solve(lists, 0, lists.size() - 1);
}

int main() {

    // first list
    ListNode* l1 = NULL;
    ListNode* t1 = NULL;

    insertAtTail(l1, t1, 1);
    insertAtTail(l1, t1, 4);
    insertAtTail(l1, t1, 7);

    cout << "List 1: ";
    printList(l1);

    // second list
    ListNode* l2 = NULL;
    ListNode* t2 = NULL;

    insertAtTail(l2, t2, 2);
    insertAtTail(l2, t2, 5);
    insertAtTail(l2, t2, 8);

    cout << "List 2: ";
    printList(l2);

    // third list 
    ListNode* l3 = NULL;
    ListNode* t3 = NULL;

    insertAtTail(l3, t3, 3);
    insertAtTail(l3, t3, 6);
    insertAtTail(l3, t3, 9);

    cout << "List 3: ";
    printList(l3);

    // now we keep all lists into a vector
    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    // then Merge the 'K' lists
    ListNode* merged = mergeKLists(lists);

    cout << "Merged K Lists: ";
    printList(merged);

    return 0;
}