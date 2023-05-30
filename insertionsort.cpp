#include <iostream>
#include <chrono>
using namespace std;

void insertion(int arr[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    const int max = 100;
    int arr[max];
    int n;
    int i;

    cout << "Program Insertion Sort" << endl;
    cout << "Berapa jumlah data?: ";
    cin >> n;

    // Input array
    for(i = 0; i < n; i++){
        cout << "Masukkan nilai elemen ke-" << i+1 << ": ";
        cin >> arr[i];
    }

    // Mulai hitung waktu
    auto start = chrono::steady_clock::now();

    // Insertion sort
    insertion(arr, n);

    // Akhir hitung waktu
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "\nWaktu eksekusi: " << chrono::duration<double, milli>(diff).count()<<" ms"<<endl;

    // Output setelah sorting
    cout << "\nHasil sorting: " << endl;
    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}