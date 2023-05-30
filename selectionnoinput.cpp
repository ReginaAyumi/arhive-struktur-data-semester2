#include <iostream>
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
    int arr[] = {81, 56, 2, 12, 9, 32, 45, 26, 23, 66, 51, 87, 39, 29, 47, 7, 16, 92, 44, 21};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Program Selection Sort" << endl;

    selection(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}