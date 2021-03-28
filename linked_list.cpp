// Linked List 


#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};


ListNode* newNode(int data) {
    ListNode *node = new ListNode;
    node->data = data;
    node->next = nullptr;
    return node;
}

void printList(ListNode *root) {
    while(root != nullptr) {
        std::cout << root->data<<"->";
        root = root->next;
    }
    cout<<"null"<<endl;
}

void reverseList(ListNode** head) {
    ListNode *current = *head;
    ListNode *prev = nullptr, *next = nullptr;
    while(current != nullptr ) {
        next = current->next;
        current->next = prev;
        
        prev = current;
        current = next;
         
    }
    *head = prev;
}

// inserting at front of the linked list
void InsertAtFront(ListNode **head, int value) {
    ListNode *node = newNode(value);
    node->next = *head;
    *head = node;
}


void InsertAtEndOfList(ListNode *head, int value) {
    ListNode *node = newNode(value), *temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = node;
}

int carryLastDigit(int value) {
   return value % 10;
}

bool carryRequired(int value) {
    return value >= 10;
}

// add two LL 2->4->5 + 4->6->2 = 7->0->7 we will do inplace
void AdditionofTwoLinkedList(ListNode **head, ListNode *head2) {
    
    // let's reverse both linked list 
    reverseList(head);
    reverseList(&head2);
    
    ListNode *temp = *head, *temp2 = head2, *prev = nullptr;
    int carry = 0;
    
    while(temp != nullptr && temp2 != nullptr) {
        
        int value = temp->data + temp2->data + carry;
        
        
        temp->data = value % 10;
        carry = value / 10;
        prev = temp;
      
        temp = temp->next;
        temp2 = temp2->next;
    }
    
    
    
    
    if (temp2 != nullptr || temp != nullptr) {
        
       
        if (temp2 != nullptr) {
            prev->next = temp2;
        }
        
        temp = prev->next;
        
        while(temp != nullptr) {
            int value = temp->data + carry;
            temp->data = value % 10;
            carry = value / 10;
            prev = temp;
            temp = temp->next;
        }
    }
   
   
   if (carry > 0) {
       prev->next = newNode(carry);
   }
   
   reverseList(head);
}


int main() {
    ListNode *head = newNode(9);
    InsertAtEndOfList(head, 9);
    InsertAtEndOfList(head,9);
    
    printList(head);
    
    
    ListNode *head2 = newNode(9);
    InsertAtEndOfList(head2, 9);
    InsertAtEndOfList(head2, 9);
    
    printList(head2);
    
    
    AdditionofTwoLinkedList(&head, head2);
    
    
    printList(head);
    //reverse a Linked List 
    // reverseList(&head);
    
    
    //insert at fromt of Linked List
    // InsertAtFront(&head, 9);
    
    // printList(head);
   
	return 0;
}
