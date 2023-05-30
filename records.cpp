#include <iostream>
using namespace std;

const int Nmax = 3;
typedef struct {int NIM; string name; int score;
} student;

int main(){
    student A[Nmax];
    A[0].NIM = 111100, A[0].name = "Regina", A[0].score = 89;
    A[1].NIM = 222200, A[1].name = "Ayumi", A[1].score = 78;
    A[2].NIM = 333300, A[2].name = "Ulayyaa", A[2].score = 80;

    for (int i = 0; i < Nmax; i++)
    {
        cout <<"index-"<<i<< "= Name: "<< A[i].name<<", NIM: "<<A[i].NIM<<", score: "<<A[i].score<<endl;
    }

    return 0;
}