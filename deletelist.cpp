#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList
{
    public:
        Node* head;

        LinkedList()
        {
            head = NULL;
        }

        void deleteTheBeginning()
        {
            Node* deletedNode = head;
            Node* temp = head->next;

            free(deletedNode);
            head = temp;
        }

        void deleteTheEnd()
        {
            if(head == NULL)
            {
                if(head->next == NULL)
                {
                    free(head);
                }
                cout << "List is empty!" << endl;
            }
            else
            {
                Node* temp = head;
                
                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }

                Node* deletedNode = temp->next;
                temp->next = NULL;
                free(deletedNode);
            }
        }

        void deleteAtPos(int pos)
        {
            if(pos == 1)
            {
                deleteTheBeginning();
            }
            else if(pos > 1)
            {
                Node* deletedNode = head;
                Node* temp = head;

                if(temp == NULL)
                {
                    cout << "List is empty!" << endl;
                }
                else
                {
                    for(int i=1; i < pos-1; i++)
                    {
                        if(temp->next != NULL)
                        {
                            temp = temp->next;
                        }
                        else
                        {
                            temp = NULL;
                            break;
                        }
                    }

                    if(temp == NULL)
                    {
                        cout << "Invalid position" << endl;
                    }
                    else
                    {
                        deletedNode = temp->next;
                        temp->next = deletedNode->next;
                        free(deletedNode);
                    }
                }
            }
            else
            {
                cout << "Invalid position" << endl;
            }
        }

        void printData()
        {
            Node* temp = head;
            if (temp != NULL)
            {
                cout << "Data in the list: ";
                while(temp != NULL)
                {
                    cout << temp->data;
                    cout << " ---> ";

                    temp = temp->next;
                }
                cout << "NULL" <<endl;
            }
            else
            {
                cout << "Linked list is empty" << endl;
            }
        }
};

int main()
{
    LinkedList mylist;

    Node* one = new Node();
    one->data = 66;
    one->next = NULL;

    mylist.head = one;

    Node* two = new Node();
    two->data = 10;
    two->next = NULL;

    one->next = two;

    Node* three = new Node();
    three->data = 7;
    three->next = NULL;

    two->next = three;

    Node* four = new Node();
    four->data = 28;
    four->next = NULL;

    three->next = four;

    Node* five = new Node();
    five->data = 51;
    five->next = NULL;

    four->next = five;

    Node* six = new Node();
    six->data = 70;
    six->next = NULL;

    five->next = six;

    Node* seven = new Node();
    seven->data = 45;
    seven->next = NULL;

    six->next = seven;

    mylist.printData();

    cout << "Delete the first node" <<endl;
    mylist.deleteTheBeginning();
    mylist.printData();

    cout << "Delete the last node" << endl;
    mylist.deleteTheEnd();
    mylist.printData();

    cout << "Delete node at position 3" << endl;
    mylist.deleteAtPos(3);
    mylist.printData();

    return 0;
}