#include<iostream>
#include<queue>
using namespace std;

#define MAX 100

class myqueue
{
    public:
        myqueue(int size = MAX);
        int *arr;
        int front = 0;
        int rear = 0;
        int count = 0;

        bool isfull()
        {
            if(rear == MAX)
            {
                return true;
            }
            else 
            {
                return false;
            }
        };

        bool isempty()
        {
            if(front == rear)
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        void peek()
        {
            if(isempty())
            {
                cout << "Queue is empty!";
            }
            cout << "Front queue: " << arr[front];
        };

        void enqueue(int data)
        {
            if (isfull())
            {
                cout << "Queue is full!";
            }
            arr[rear] = data;
            rear = rear + 1;
        }

        int dequeue()
        {
            // check for queue underflow
            if (isempty())
            {
                cout << "Underflow\nProgram Terminated\n";
                exit(EXIT_FAILURE);
            }
        
            int x = arr[front];
            cout << "Removing " << x << endl;
        
            front = front + 1;
            count--;
        
            return x;
        }

        void print()
        {
            while(!isempty()) 
            {
                cout << arr[front] << ", ";
                pop();
            }
        }

        void pop()
        {
            if(isempty())
            {
                cout << "queue is empty!" << endl;
            }
            else
            {
                front = front + 1;
            }
        }
};



int main()
{
    myqueue q;

    q.enqueue(10);
    q.enqueue(10);
    q.enqueue(10);

    q.print();

    return 0;
}
