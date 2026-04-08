// An array is an linear DS which stores data in continuous memory location, but what if we have memory space available as parts individually throughout  the memory location so we cant use array rather we have to use linked list.

// A linked list is a collection of nodes each node contains (data,address of next node (pointer)) and last node will have (null).

// Types of linked lists : 1) single LL 2)circular LL 3)doubly LL (contains previous ptr,data,next ptr)

#include <iostream>
using namespace std;

// creation of a node
class Node
{
public: 
    int data;
    Node *next_ptr;

    // constructor to add some default values
    Node()
    {
        this->data = 0;
        this->next_ptr = NULL; // because if there is a single linked list there is no next node so it's NULL
    }

    Node(int data){
        this->data = data;
        this->next_ptr = NULL;
    }

    // printing function
    void print(Node* &head){
        Node* temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<" "; 
            temp = temp->next_ptr;
        }
        cout << endl;
    }
};

int main()
{
    Node *first_obj_node = new Node(10);  // Add some values to see the output
    Node *second_obj_node = new Node(20);
    Node *third_obj_node = new Node(30);
    Node *fourth_obj_node = new Node(40);
    Node *fifth_obj_node = new Node(50);

    // now connect each node with other
    first_obj_node->next_ptr = second_obj_node; // first node points to second
    second_obj_node->next_ptr = third_obj_node; // second node points to third
    third_obj_node->next_ptr = fourth_obj_node; // third node points to fourth
    fourth_obj_node->next_ptr = fifth_obj_node; // fourth node points to fifth

    first_obj_node->print(first_obj_node);

    return 0;
}