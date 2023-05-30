#include <iostream>
using namespace std;

int main(){
    const int num_mak = 5;
    const int num_min = 5;
    string makanan[num_mak];
    string minuman[num_min];
    int harga_mak[num_mak];
    int harga_min[num_min];
    int pesan[2];
    int i, j;

    int menu;
    char lanjut = 'y';

    do {
        cout << "\n     PROGRAM MENU CAFE     " << endl;
        cout << "=============================" << endl;
        cout << "1. Isi Makanan" << endl;
        cout << "2. Isi Minuman" << endl;
        cout << "3. Isi Harga Makanan" << endl;
        cout << "4. Isi Harga Minuman" << endl;
        cout << "5. Pesan Makanan dan Minuman" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu)
        {
            case 1:
                cout << "\nInput Nama Makanan\n"<<endl;
                for (i = 0; i < num_mak; i++)
                {
                    cout << "Makanan "<< i+1 << ": ";
                    cin >> makanan[i];
                }
                break;
            case 2:
                cout << "\nInput Nama Minuman\n"<<endl;
                for (i = 0; i < num_min; i++)
                {
                    cout << "Minuman "<< i+1 << ": ";
                    cin >> minuman[i];
                }
                break;
            case 3:
                cout << "\nInput Harga Makanan\n"<<endl;
                for (i = 0; i < num_mak; i++)
                {
                    cout << "Harga " << makanan[i] << ": ";
                    cin >> harga_mak[i];
                }
                break;
            case 4:
                cout << "Input Harga Minuman"<<endl;
                for (i = 0; i < num_min; i++)
                {
                    cout << "Harga " << minuman[i] << ": ";
                    cin >> harga_min[i];
                }
                break;
            case 5:
                int mak, min;
                // Menampilkan daftar makanan dan minuman
                cout << "Daftar Makanan: "<< endl;
                for (i = 0; i < num_mak; i++)
                {
                    cout << i+1 <<". " << makanan[i] <<" ---> Harga: "<< harga_mak[i] << endl;
                }
                cout << "Daftar Minuman: "<< endl;
                for (i = 0; i < num_min; i++)
                {
                    cout << i+1 << ". " << minuman[i] <<" ---> Harga: "<< harga_min[i] << endl;
                }

                // Pesan makanan dan minuman
                cout << "Masukkan nomor makanan yang ingin dipesan: ";
                cin >> pesan[0];
                mak = pesan[0] - 1;
                cout << "Masukkan nomor minuman yang ingin dipesan: ";
                cin >> pesan[1];
                min = pesan[1] - 1;

                // Menampilkan pesanan dan total harga
                cout << "\nPesanan: " << makanan[mak] << " dan " << minuman[min] << endl;
                cout << "Total harga: " << harga_mak[mak] + harga_min[min] << endl;
                break;
            default:
                cout << "Pilihan menu tidak tersedia."<< endl;
                break;
        }

        cout << "\nApakah Anda ingin melanjutkan? (y/n): ";
        cin >> lanjut;

    } while (lanjut == 'y');

    return 0;
}
