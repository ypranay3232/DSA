// A circular LL is a type of LL where last node does not point to a NULL rather it points to a Node (usually its the head but can vary). To solve we use the approach two pointers slow and fast

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

// insert at tail :
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newnode = new Node(data);

    // if head == null LL is empty
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    // Key note : tail next = new node
    tail->next = newnode;
    tail = newnode;
}

// Printfunc which stops after a limit to avoid infinite loop
void printList(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL && count < 20)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << "NULL" << endl;
}

// we use floyd cycle algorithm to detect for cycles at O(n) time and O(1) space.
Node* findCycleStart(Node *head)
{
    // base case : if head == NUll list is empty so return NULL
    if (head == NULL)
        return NULL;

    // the two pointers slow and fast : slow moves 1 step fast moves 2 steps
    Node *slow = head;
    Node *fast = head;

    // check for a cycle :
    bool cycle = false;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // if slow == fast we have a cycle
        if (slow == fast)
        {
            cycle = true;
            break;
        }
    }
    // if no cycle return NULL
    if (!cycle)
        return NULL;

    // Now Move slow to head
    slow = head;
    // Move both to → meet at start
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // start of cycle
}

// Helper to check for cycle existence
bool isCircular(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

void removeCycle(Node* head) {
    Node* start = findCycleStart(head);
    if (start == NULL) return;

    Node* temp = start;
    while (temp->next != start) {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    cout << "Original List:\n";
    printList(head);

    // Create a cycle: 5 -> 3
    tail->next = head->next->next;

    if (isCircular(head)) {
        cout << "Cycle detected " << endl;
        Node* start = findCycleStart(head);
        cout << "Cycle starts at node with value: " << start->data << endl;
    }

    removeCycle(head);

    cout << "After removing cycle:\n";
    printList(head);

    return 0;
}