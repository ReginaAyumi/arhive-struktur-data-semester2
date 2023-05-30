#include<iostream>
#include<queue>
using namespace std;

#define MAX 5

class myqueue
{
	int *arr;
	int front;
	int rear;
	
    public:
        myqueue(int size)
        {
        	arr = new int[size];
        	front = 0;
        	rear = 0;
		}

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
            if(isempty() == true)
            {
                cout << "Queue is empty!";
            }
            cout << "-> Front queue: " << arr[front] << endl;;
        }

        void enqueue(int data)
        {
            if (isfull() == true)
            {
                cout << "Queue is full!" << endl;
            }
            else
            {
                arr[rear] = data;
                rear = rear + 1;
                cout << "add " << data << endl;
            }
        }

        // dequeue dengan menggeser front
        void dequeue()
        {
            if (isempty() == true)
            {
                cout << "Queue is empty!" << endl;
            }
            else
            {
                int x = arr[front];
                front = front + 1;
                cout << "removing " << x << endl;
            }
        }

        void print()
        {
        	cout << "\nprint data: " << endl;
            int x = front;
            while(!isempty()) 
            {
                cout << arr[front] << "  ";
                front = front + 1;
            }
            cout << endl;
            front = x;
        }
};

int main()
{
    myqueue q(MAX);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.peek();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.print();

    q.dequeue();
    q.print();
    q.peek();

    q.dequeue();
    q.dequeue();
    q.peek();
    
    q.print();
    
    return 0;
}
