#include <iostream>
using namespace std;

// Node structure
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
// Insert at tail
void insertAtTail(ListNode *&head, ListNode *&tail, int val)
{
    // Create new node
    ListNode *newNode = new ListNode(val);
    // If LL is empty
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    // Attach node at tail
    tail->next = newNode;

    // Move tail forward
    tail = newNode;
}

// Print Linked List
void printLL(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Function to delete N nodes after M nodes
void deleteNafterM(ListNode *&head, int M, int N)
{
    // Edge case
    if (head == NULL || N == 0)
    {
        return;
    }

    ListNode *curr = head;

    // Traverse until end
    while (curr != NULL)
    {
        // Move curr M-1 times
        for (int i = 1; i < M && curr != NULL; i++)
        {
            curr = curr->next;
        }
        // If list ended
        if (curr == NULL)
        {
            return;
        }
        // temp points to first node to delete
        ListNode *temp = curr->next;

        // Move temp N times
        for (int i = 0; i < N && temp != NULL; i++)
        {

            // Store next node
            ListNode *nextNode = temp->next;

            // Delete current node
            delete temp;

            // Move forward
            temp = nextNode;
        }

        curr->next = temp;

        curr = temp;
    }
}

int main()
{

    ListNode *head = NULL;
    ListNode *tail = NULL;

    // Create Linked List
    for (int i = 1; i <= 10; i++)
    {
        insertAtTail(head, tail, i);
    }

    cout << "Original Linked List:" << endl;
    printLL(head);

    int M = 2;
    int N = 3;

    deleteNafterM(head, M, N);

    cout << "\nAfter Deleting:" << endl;
    printLL(head);

    return 0;
}