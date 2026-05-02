// Merge sort : eliminates need of array here so merge sort works by dividing the LL into two parts its memory efficient O(1). si we ai as first we find the LL split it into two parts then we sort them using recursion and merge the splitted halves.

#include <iostream>
using namespace std;

// create the node structure
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

// insert the elements at tail because its easy to do so
void insertAtTail(ListNode *&head, ListNode *&tail, int val)
{
    // create a new node
    ListNode *newnode = new ListNode(val);

    // check the base condition : if head is null assign head and tail to new node else tail next = new node and tail = new node.
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}
// func to print the List
void PL(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL";
}

//  if we remember the approach is : we divide the LL by using a middle element so find that
ListNode *getmiddle(ListNode *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // now we use two pointers slow and fast
    ListNode *slow = head;
    ListNode *fast = head->next;

    // as we know the fast moves faster than slow pointer so check
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // because as fast finishes the list slow will get to the Middle
}

// now next step is merge the sorted LL
ListNode *merge(ListNode *left, ListNode *right)
{
    // two dummy nodes for merging
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;

    // now compare both and merge them
    while (left != NULL && right != NULL)
    {
        if (left->val < right->val)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    // Attach remaining nodes
    if (left != NULL)
        temp->next = left;

    if (right != NULL)
        temp->next = right;

    return dummy->next;
}

// Merge sort logic : find middle sort using recursion and merge
ListNode* Mergesort(ListNode* head){

    // base condition : 
    if(head == NULL || head->next == NULL){
        return head;
    }

    // find middle element: 
    ListNode* mid = getmiddle(head);

    ListNode* righthead = mid->next;
    mid->next = NULL;//break

    ListNode* left = head;
    ListNode* right = righthead;

    // use recursion :
    left = Mergesort(left);
    right = Mergesort(right);

    // now merge both 
    return merge(left,right);
}

int main(){
    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertAtTail(head,tail,4);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,3);

    cout<<"original list"<<endl;
    PL(head);

    // sort
    head = Mergesort(head);

    cout<<"sorted List"<<endl;
    PL(head);

    return 0;
}