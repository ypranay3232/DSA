// The optimised approach is to create 3 dummy lists and traverse them then attach the lists and merge all.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to sort all 0s 1s and 2s
Node *sortList(Node *head)
{
    // base condition if head is empty or no next Node for head return head
    if (!head || !head->next)
        return head;

    // now create 3 dummy lists
    Node *zeroListHead = new Node(-1);
    Node *zeroListTail = zeroListHead;

    Node *oneListHead = new Node(-1);
    Node *oneListTail = oneListHead;

    Node *twoListHead = new Node(-1);
    Node *twoListTail = twoListHead;

    Node *curr = head;

    // Now distribute Node to all 3 dummy lists
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            zeroListTail->next = curr;
            zeroListTail = curr;
        }
        else if (curr->data == 1)
        {
            oneListTail->next = curr;
            oneListTail = curr;
        }
        else
        {
            twoListTail->next = curr;
            twoListTail = curr;
        }
        curr = curr->next;
    }

    // now merge the list and connect o with 1 and 1 with 2
    if (oneListHead->next != NULL)
    {
        zeroListTail->next = oneListHead->next;
    }
    else
    {
        zeroListTail->next = twoListHead->next;
    }

    // Connect 1s -> 2s
    oneListTail->next = twoListHead->next;

    // End list
    twoListTail->next = NULL;

    // New head
    head = zeroListHead->next;

    // Cleanup dummy nodes
    delete zeroListHead;
    delete oneListHead;
    delete twoListHead;

    return head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // Creating a dummy list: 1 -> 2 -> 0 -> 1 -> 0
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List:   ";
    printList(head);

    return 0;
}