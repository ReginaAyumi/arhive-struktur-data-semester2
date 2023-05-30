#include <iostream>
using namespace std;

#define MAX 100

struct mhs
{
    string nim,nama;
};

class MyStack{
    public:
        int top;
        mhs data[MAX];
        MyStack()
        {
            top = -1;
        }
        bool isEmpty()
        {
            return (top == -1);
        }
        int size()
        {
            return top + 1;
        }
        int isFull()
        {
            return (size() >= MAX - 1);
        }
        mhs topElement()
        {
            if(isEmpty())
            {
                cout << "stack is empty!" << endl;
                mhs tmp;
                tmp.nim = "";
                tmp.nama = "";
                return tmp;
            }
            else
            {
                return data[top];
            }
        }
        void push(mhs newdata)
        {
            if(isFull())
            {
                cout << "stack is full!" << endl; 
            }
            else
            {
                data[++top] = newdata;
                cout << "data added successfully!" << endl;
            }
        }
        void pop()
        {
            if(isEmpty())
            {
                cout << "stack is empty!" << endl;
            }
            else
            {
                top = top - 1;
            }
        }
        void print()
        {
            while(isEmpty() == false)
            {
                mhs x = topElement();
                cout << x.nim << ": " << x.nama << endl;
                pop();
            }
        }
};

int main()
{
    MyStack stack;
    mhs mhs1,mhs2;
    mhs1.nim = "001";
    mhs1.nama = "Agung";
    mhs2.nim = "002";
    mhs2.nama = "Budi";
    stack.push(mhs1);
    stack.push(mhs2);
    stack.print();
}