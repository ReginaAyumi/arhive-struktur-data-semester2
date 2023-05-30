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

void selection(int arr[], int n)
{
    int i, j, imin;

    for(i = 0; i < n-1; i++){
        imin = i;
        for(j = i; j < n; j++){
            if (arr[j] < arr[imin]){
                imin = j;
            }
        }

        myswap(&arr[imin], &arr[i]);
    }
}

int main()
{
    const int max = 100;
    int arr[max];
    int n;
    int i;

    cout << "Program Selection Sort" << endl;
    cout << "Berapa jumlah data?: ";
    cin >> n;

    for(i = 0; i < n; i++){
        cout << "Masukkan nilai elemen ke-" << i+1 << ": ";
        cin >> arr[i];
    }
    
    // Mulai hitung waktu
    auto start = chrono::steady_clock::now();

    // Selection sort
    selection(arr, n);

    // Akhir hitung waktu
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "\nWaktu eksekusi: " << chrono::duration<double, milli>(diff).count()<<" ms"<<endl;

    //Output setelah sorting
    cout << "\nHasil sorting: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
