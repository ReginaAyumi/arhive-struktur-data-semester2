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

        void addNodeToStart(int newElement)
        {
            Node* newNode = new Node();
            newNode->data = newElement;
            newNode->next = head;

            head = newNode;
        }

        void addNodeToPos(int newElement, int pos)
        {
            if(pos == 1)
            {
                addNodeToStart(newElement);
            }
            else if(pos > 1)
            {
                Node* newNode = new Node();
                newNode->data = newElement;

                Node* temp = head;
                if(temp == NULL)
                {
                    cout << "List is empty" << endl;
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
                        newNode->next = temp->next;
                        temp->next = newNode;
                    }
                }
            }
            else
            {
                cout << "Invalid position" << endl;
            }
        }

        void addNodeToEnd(int newElement)
        {
            Node* newNode = new Node();
            newNode->data = newElement;
            newNode->next = NULL;

            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                Node* temp = head;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
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

    Node* first = new Node();
    first->data = 6;
    first->next = NULL;

    mylist.head = first;

    Node* second = new Node();
    second->data = 10;
    second->next = NULL;

    first->next = second;

    Node* third = new Node();
    third->data = 7;
    third->next = NULL;

    second->next = third;

    mylist.printData();

    mylist.addNodeToStart(21);
    mylist.printData();

    mylist.addNodeToPos(50, 2);
    mylist.printData();

    mylist.addNodeToEnd(99);
    mylist.printData();

    mylist.addNodeToEnd(100);
    mylist.printData();

    int sum = 0;
    Node* temp = mylist.head;
    while(temp->next != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    cout << "jumlah data: "<<sum;

    return 0;
}