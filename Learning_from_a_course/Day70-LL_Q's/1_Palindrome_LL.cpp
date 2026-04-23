// Check if a LL is palindrome or not ? The optimal approach to solve it in O(1) is to find the middle of List and reverse the second half and compare. 
#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// To reverse the List
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL){
        Node* nextNode = curr->next;//store the next node values in newnode 
        curr->next = prev;//reverse the list
        prev = curr;//now move both curr and prev forward
        curr = nextNode;
    }
    return prev;
}

// check if the given LL is a palindrome or not 
bool ispalindrome(Node* head){
    if(head == NULL || head->next == NULL){
        return true;
    }

    // find the middle part of List
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // now reverse the second half of list
    Node* secondhalf = reverse(slow->next);

    // compare the both halves of list
    Node* firstHalf = head;
    Node* temp  = secondhalf;
    
    while(temp != NULL){
        if(firstHalf->data != temp->data){
            return false;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }
    return true;
}

// now insert the elements in List ad print it

void insertAtTail(Node* &head,int val){
    if(head == NULL){
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(val);
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data    <<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;

    // palindrome insertion 
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,1);
    
    print(head);

    if(ispalindrome){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}