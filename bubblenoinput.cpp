#include <iostream>
using namespace std;

void swap(int *a, int *b)
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
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    int arr[] = {81, 56, 2, 12, 9, 32, 45, 26, 23, 66, 51, 87, 39, 29, 47, 7, 16, 92, 44, 21};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    cout << "Program Bubble Sort" << endl;

    bubble(arr, n);

    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}