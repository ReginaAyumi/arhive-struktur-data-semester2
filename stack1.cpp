#include <iostream>
using namespace std;

#define MAX 100

class MyStack{
    public:
        int top;
        int data[MAX];
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
        int topElement()
        {
            if(isEmpty())
            {
                cout << "stack is empty!" << endl;
                return 0;
            }
            else
            {
                return data[top];
            }
        }
        void push(int newdata)
        {
            if(isFull())
            {
                cout << "stack is full!" << endl; 
            }
            else
            {
                top = top + 1;
                data[top] = newdata;
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
                int x = topElement();
                cout << x << endl;
                pop();
            }
        }
};

int main()
{
    MyStack stack;
    stack.push(15);
    stack.push(17);
    stack.push(19);
    stack.print();
}