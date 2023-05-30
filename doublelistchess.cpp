#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node* next;
    Node* prev;
};

class linkedList
{
    public:
        Node* head;

        linkedList()
        {
            head = NULL;
        }

        void addNode(Node** head_ref, string new_data)
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
            {
                last = last->next;
            }

            last->next = new_node;
            new_node->prev = last;
        
            return;
        }

        void printList(Node* node)
        {
            Node* temp;
            cout << "\nData in the list: "<< endl;
            if (node != NULL)
            {
                while (node != NULL)
                {
                    cout << node->data << " <--> ";
                    temp = node;
                    node = node->next;
                }
                cout << "NULL" <<endl;
            }
        }

        void displayList(Node* node, int m, int n)
        {
            Node* last;
            Node* temp;

            int i = 0;
            while (node != NULL)
            {
                if (i < m-1)
                {
                    node = node->next;
                }
                else if (i == m-1)
                {
                    cout << "\nStep " << m << ": ";
                    cout << node->data << endl;
                    temp = node->next;
                    last = node->prev;
                }
                i++;
            }

            cout << "\nStep after " << m << ": "<< endl;
            for (int i = 0; i < n; i++)
            {
                cout << temp->data << "    ";
                temp = temp->next;
                if (temp == NULL)
                {
                    cout << "NULL" <<endl;
                }
            }
        
            cout << "\n\nStep before " << m << ": "<< endl;
            for (int i = 0; i < n; i++)
            {
                cout << last->data << "    ";
                last = last->prev;
                if (temp == NULL)
                {
                    cout << "NULL" <<endl;
                }
            }
        }
};

int main()
{
    linkedList mylist;
    Node* head = NULL;
    int m, n;

    mylist.addNode(&head, "e2e4");
    mylist.addNode(&head, "e7e5");
    mylist.addNode(&head, "g1f3");
    mylist.addNode(&head, "f8e7");
    mylist.addNode(&head, "a2a3");
    mylist.addNode(&head, "b8a6");
    mylist.addNode(&head, "h2h4");
    mylist.addNode(&head, "a8b8");
    mylist.addNode(&head, "b2b3");
    mylist.addNode(&head, "e8f8");
    mylist.addNode(&head, "f3e5");
    mylist.addNode(&head, "b7b5");
    mylist.printList(head);

    cout << "\nInput m position: ";
    cin >> m;
    cout << "Input n step: ";
    cin >> n;
    mylist.displayList(head, m, n);

    return 0;
}
