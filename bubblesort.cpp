#include <iostream>
#include <chrono>
using namespace std;

void myswap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int arr[], int n)
{
    int i, j;

    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                myswap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    const int max = 100;
    int arr[max];
    int n;
    int i;

    cout << "Program Bubble Sort" << endl;
    cout << "Berapa jumlah data?: ";
    cin >> n;

    // Input array
    for(i = 0; i < n; i++){
        cout << "Masukkan nilai elemen ke-" << i+1 << ": ";
        cin >> arr[i];
    }

    // Mulai hitung waktu
    auto start = chrono::steady_clock::now();

    // Bubble sort
    bubble(arr, n);

    // Akhir hitung waktu
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "\nWaktu eksekusi: " << chrono::duration<double, milli>(diff).count()<<" ms"<<endl;

    // Output setelah sorting
    cout << "\nHasil sorting:" << endl;
    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}