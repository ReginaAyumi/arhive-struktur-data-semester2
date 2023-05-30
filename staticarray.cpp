#include <iostream>
using namespace std;

int main(){
    const int NUM_MHS = 3;
    const int NUM_NILAI = 3;
    string mahasiswa[NUM_MHS] = {"Andi", "Budi", "Cahya"};
    string pelajaran[NUM_NILAI] = {"Matematika", "Bahasa Indonesia", "Bahasa Inggris"};
    float nilai[NUM_MHS][NUM_NILAI];
    int i, j;
    float total;
    float rerata[NUM_MHS];

    for (i = 0; i < NUM_MHS; i++)
    {
        total = 0;
        for (j = 0; j < NUM_NILAI; j++)
        {
            cout << "Masukkan nilai " << mahasiswa[i] << " untuk mapel " << pelajaran[j] << ": ";
            cin >> nilai[i][j];

            total = total + nilai[i][j];
        }

        //hitung rerata
        rerata[i] = total/NUM_NILAI;
    }

    for (int i = 0; i < NUM_MHS; i++)
    {
        cout << "Rerata nilai " << mahasiswa[i] << ": " << rerata[i] << endl;
    }

    return 0;
}