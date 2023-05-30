#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string bus, time, destination;
    Node *next;
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void addSchedule(string bus, string time, string destination)
    {
        Node *newNode = new Node();
        newNode->bus = bus;
        newNode->time = time;
        newNode->destination = destination;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    };

    void deleteSchedule(string bus)
    {
        Node *newNode = head;
        Node *p = NULL;

        if (newNode != NULL && newNode->bus == bus)
        {
            head = newNode->next;
            free(newNode);

            cout << "Jadwal Bus Berhasil Dihapus\n";
        }

        while (newNode != NULL && newNode->bus != bus)
        {
            p = newNode;
            newNode = newNode->next;
        }
        if (newNode == NULL)
        {
            cout << "Jadwal Bus tidak tersedia\n";
            p->next = newNode->next;

            free(newNode);
            cout << "Jadwal Bus Berhasil Dihapus\n";
        }
    };

    void showSchedule()
    {
        Node *temp = head;
        if (temp != NULL)
        {
            cout << "\nJadwal bus: " << endl;
            while (temp != NULL)
            {
                cout << "================================" << endl;
                cout << "Nama bus: " << temp->bus << endl;
                cout << "Waktu keberangkatan: " << temp->time << endl;
                cout << "Tujuan: " << temp->destination << endl;

                temp = temp->next;
            }
        }
        else
        {
            cout << "Jadwal kosong" << endl;
        }
    };

    void searchSchedule(string datasearchBus)
    {

        Node *temp = head;
        bool found;
        if (temp != NULL)
        {
            while (temp != NULL)
            {
                if (datasearchBus == temp->bus)
                {
                    cout << "Data found\n";
                    found = true;
                    cout << "Kedatangan: " << temp->time << endl;
                    cout << "Destinasi: " << temp->destination << endl;
                    break;
                }
                temp = temp->next;
            }
        }
        else
        {
            cout << "Linked List is empty" << endl;
        }
    }
};

int main()
{
    LinkedList bs;
    string bus, time, destination;
    string del;
    int menu;
    bool quit;

    cout << "\nJadwal bus di Semarang" << endl;

    // contoh
    bs.addSchedule("Trans Semarang", "11.00", "Surabaya");

    while (!quit)
    {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Masukkan jadwal bus" << endl;
        cout << "2. Hapus jadwal bus" << endl;
        cout << "3. Print jadwal bus" << endl;
        cout << "4. Search jadwal bus" << endl;
        cout << "5. quit program" << endl;
        cout << "Pilih nomor: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "\nInput jadwal bus" << endl;
            cout << "\nNama bus: ";
            cin >> bus;
            cout << "Waktu keberangkatan: ";
            cin >> time;
            cout << "Tujuan perjalanan: ";
            cin >> destination;
            bs.addSchedule(bus, time, destination);
            break;
        case 2:
            cout << "Input nama bus yang ingin dihapus: ";
            cin >> del;
            bs.deleteSchedule(del);
            break;
        case 3:
            bs.showSchedule();
            break;
        case 4:
            cout << "Input nama bus yang ingin dicari: ";
            cin >> bus;
            bs.searchSchedule(bus);
            break;
        case 5:
            quit = true;
            cout << "Quit Program" << endl;
            break;
        default:
            cout << "Input tidak valid, menutup program.." << endl;
            quit = true;
            break;
        }
    }

    return 0;
}
