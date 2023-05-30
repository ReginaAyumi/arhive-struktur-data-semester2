#include <iostream>
#include <stack>
using namespace std;

struct mhs
{
    string nim,nama;
};

int main() {
	stack<mhs> stack;
    mhs nino;
    nino.nim = "001";
    nino.nama = "Nino";
	stack.push(nino);

    mhs tmp;
	while (stack.empty() == false) {
		tmp = stack.top();
        cout << tmp.nim << ": " << tmp.nama << endl;
		stack.pop();
	}
}


/*
do {
        cout << "\nEnter url: ";
        cin >> url;  
        stack.push(url);
        cout << "Input url again?(y/n): ";
        cin >> again;
    } while (again == 'y');
*/
