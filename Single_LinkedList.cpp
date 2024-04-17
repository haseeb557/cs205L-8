#include <iostream>
using namespace std;
class node
{
    public:
    int val;            //node consists of a value and a next pointer which stores the address of the next node
    node* next;   

   node (int data)   //constructor 
   {
       val = data;
       next = NULL;
    }

};

void insertAtHead(node* &head, int val)    //when adding & deleting elements, we use '&head' for getting the 'heads' address and when simply displaying, we only use'head'
{
    node* new_node = new node(val);
    new_node -> next = head;
    head = new_node;
}

void insertAtEnd(node* &head, int val)
{
    node* new_node = new node(val);
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = new_node;
}

void insertAtPosition(node* &head, int val, int pos)
{
    if (pos==0)
    {
        insertAtHead(head,val);
        return;
    }    

        node* new_node = new node(val);
        node* temp = head;
        int current_pos = 0;
        while(current_pos != pos-1)
        {
            temp = temp ->next;
            current_pos++;
        }
    
    new_node -> next = temp -> next;
    temp -> next = new_node;          //establishing two connections here 
}

void deleteAtHead(node* &head)
{
    node* temp = head;
    head = head -> next;
    free(temp);
}

void deleteAtTail(node* &head)
{
    node* second_last = head;
    while(second_last -> next -> next != NULL)
    {
        second_last = second_last -> next;
    }
    node* temp = second_last -> next;
    second_last -> next = NULL;
    free(temp);
}    

void deleteAtPosition(node* &head, int pos)
{
    if(pos==0)
    {
        deleteAtHead(head);
        return;
    }

    node* prev = head;
    int current_pos = 0;
    while(current_pos != pos-1)
    {
        prev = prev -> next;
        current_pos++;
    }
    node* temp = prev -> next;
    prev -> next = prev -> next -> next;
    free(temp);
}    

void display(node* head)           //when simply displaying, we only use 'head'
{
    node* temp = head; 
    while (temp!=NULL)
    {
        cout<<temp->val<<"->";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

int main()
{
    node* head = NULL;

    insertAtHead(head,2);
    display(head);
    insertAtHead(head,1);
    display(head);

    insertAtEnd(head, 3);
    display(head);

    insertAtPosition(head, 4, 1);
    display(head);

    deleteAtHead(head);
    display(head);

    deleteAtTail(head);
    display(head);

    deleteAtPosition(head, 1);
    display(head);
}