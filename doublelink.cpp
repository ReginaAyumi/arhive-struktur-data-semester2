#include <iostream>
using namespace std;
 
class Node
{
    public:
    string data;
    Node* next;
    Node* prev;
};
 
void push(Node** head_ref, string new_data)
{
    Node* new_node = new Node();
 
    Node* last = *head_ref; 
 
    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
 
    new_node->prev = last;
 
    return;
}
 
void printList(Node* node)
{
    Node* last;
    while (node != NULL)
    {
        cout << node->data<< " <--> ";
        last = node;
        node = node->next;
    }
    cout << "NULL" << endl;
 
}

void afterBefore(Node* node, int m, int n)
{
    Node* last;
    Node* temp;
    int i;
    while(node!=NULL)
    {
        if(i < m-1)
        {
            node = node->next;
        }
        else if (i<m) 
        {
            cout << "Step " << m << ": " ;
            cout << node->data;
            temp = node->next;
            last = node->prev;
        }
        i++;
    }

    cout << "Step after " << m << ": " << endl;
    for(i=0; i<n; i++)
    {
        cout << temp->data << " " ;
        temp = temp->next;
        if(temp==NULL)
        {
            cout << "NULL" << endl;
        }
    }

    cout << "Step before: " << endl;
    for(i=0; i<n; i++)
    {
        cout << last->data << " " ;
        last = last->prev;
        if(temp==NULL)
        {
            cout << "NULL" << endl;
        }
    }
}

int main()
{
    Node* head = NULL;
    push(&head, "e4e5");
    push(&head, "c4");
    push(&head, "e4");
    push(&head, "e5");
    push(&head, "b5a6");
    push(&head, "kf3");
    push(&head, "c6");
    push(&head, "cxb5");
 
    
 
    cout << "Created DLL is: ";
    printList(head);

    afterBefore(head, 4, 2);

    return 0;
}