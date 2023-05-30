#include <iostream>
#include <string>
using namespace std;

struct Node{
    string uraian;
    int nominal;
    Node *next;
};

class linkedList{
    public:
    Node* head1;
    Node* head2;

    linkedList()
    {
        head1 = NULL;
        head2 = NULL;
    }

    void addNode(Node *head)
    {
        bool quit = false;
        string temp;
        int nom;
        Node *current;

        while (!quit){
            cout << "Uraian: ";
            getline(cin >> ws, temp);
            if (temp != "quit"){
                cout << "Nominal: ";
                cin >> nom;
            }

            if (temp == "quit"){
                quit = true;
            }
            else{
                // Allocate the new node here:
                current = new Node;
                current-> uraian = temp;
                current-> nominal = nom;

                // the new node is inserted after the empty head
                // because head is an empty node in your implementation:
                current->next = head->next;
                head -> next = current;
            }
        }
        return;
    }

    void printList(Node *head)
    {
        if (!head->next)
        {
            cout << "List empty" << endl;
            return;
        }

        Node *current;
        // set current to head->next, because the head is empty in your implementation:
        current = head->next;
        while (current)
        {
            cout << current-> uraian << " = " << current->nominal << endl;
            current = current->next;
        }
    }

};

int main()
{
    linkedList pemasukan;
    linkedList pengeluaran;
    Node *head1 = new Node;
    Node *head2 = new Node;
    head1->next = NULL;
    head2->next = NULL;

    bool quit = false;
    int menu;

    while (!quit){
        cout << "\n=== Menu ==="<<endl;
        cout << "1. input pemasukan"<<endl;
        cout << "2. input pengeluaran"<<endl;
        cout << "3. print list"<<endl;
        cout << "4. quit program"<<endl;
        cout << "Pilih nomor: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "\nInput detail pemasukan (type quit to stop)"<<endl;
            pemasukan.addNode(head1);
            break;
        case 2:
            cout << "\nInput detail pengeluaran (type quit to stop)"<<endl;
            pengeluaran.addNode(head2);
            break;
        case 3:
            cout << "\nRekap Transaksi: "<<endl;
            cout << "Pemasukan: "<<endl;
            pemasukan.printList(head1);
            cout << "\nPengeluaran: "<<endl;
            pengeluaran.printList(head2);
            break;
        case 4: quit = true;
            cout << "Quit Program" << endl;
            break;
        default:
            cout << "Input tidak valid, menutup program.."<<endl;
            quit = true;
            break;
        }
    }

    return 0;
}

