#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int val)
    {
        data = val;
        next = NULL;
        child = NULL;
    }
};

Node *flattenDFS(Node *head)
{
    Node *curr = head;
    Node *tail = head;

    while (curr)
    {

        // Save next pointer
        Node *nextNode = curr->next;

        // If child exists
        if (curr->child)
        {

            // Flatten child recursively
            Node *childHead = flattenDFS(curr->child);

            // Attach child between current and next
            curr->next = childHead;

            // Find tail of child list
            Node *temp = childHead;
            while (temp->next)
            {
                temp = temp->next;
            }

            // Connect back to saved next
            temp->next = nextNode;

            // Remove child pointer
            curr->child = NULL;

            tail = temp;
        }
        else
        {
            tail = curr;
        }

        curr = nextNode;
    }

    return head;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{

    /*
        Structure:

        1 -> 2 -> 3 -> 4
             |
             7 -> 8
                  |
                  11 -> 12
    */

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->next->child = new Node(7);
    head->next->child->next = new Node(8);

    head->next->child->next->child = new Node(11);
    head->next->child->next->child->next = new Node(12);

    flattenDFS(head);

    cout << "Flattened List:\n";
    printList(head);

    return 0;
}