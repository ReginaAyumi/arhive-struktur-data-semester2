#include <iostream>
#include <stack>
using namespace std;

#define MAX 100

class MyStack{
    public:
        int top;
        string data[MAX];
        string current_url = "";
        stack<string> forward_stack;
        stack<string> backward_stack;

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
        string topElement()
        {
            if(isEmpty())
            {
                cout << "stack is empty!" << endl;
                string tmp;
                tmp = "";
                return tmp;
            }
            else
            {
                return data[top];
            }
        }
        void push(string newdata)
        {
            if(isFull())
            {
                cout << "stack is full!" << endl; 
            }
            else
            {
                data[++top] = newdata;
                visit_new_url(newdata);
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
                string x = topElement();
                cout << "  url: " << x << endl;
                pop();
            }
        }

        void visit_new_url(string url)
        {
            if (current_url != "") {
                backward_stack.push(current_url);
            }

            current_url = url;
        }

        void forward()
        {
            if (forward_stack.empty()) 
            {
                cout << "Not Available";
                return;
            }
            else 
            {
                backward_stack.push(current_url);
                current_url = forward_stack.top();
                forward_stack.pop();
                cout << "  Move forward to " << current_url;
            }
        }

        void backward()
        {
            if (backward_stack.empty()) 
            {
                cout << "Not Available";
                return;
            }
            else 
            {
                forward_stack.push(current_url);
                current_url = backward_stack.top();
                backward_stack.pop();
                cout << "  Move backward to " << current_url;
                return;
            }
        }
};

int main()
{
    MyStack stack;
    string url;
    char again, move;

    cout << "\nBrowsing History"<<endl;
    cout << "\nEnter url and type 'stop' to quit"<<endl;

    do {
        cout << "  Enter url: ";
        cin >> url;  
        if (url != "stop")
        {
            stack.push(url);
        }
    } while (url != "stop");
    
    cout << endl;
    cout << "Print stack" <<endl;
    stack.print();
    cout << "\ncurrent url is " << stack.current_url << endl;
    cout << "\nChoose One:" <<endl;
    
    do {
        cout << "Backward (b) || Forward (f) = ";
        cin >> move;
        if (move == 'b')
        {
            stack.backward();
        }
        else if (move == 'f')
        {
            stack.forward();
        }
        else
        {
            cout << "Input false!";
        }
        cout << "\n\nMove again?(y/n): ";
        cin >> again;
    } while (again == 'y');

    return 0;
}

